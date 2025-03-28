#include "../../include/execute.h"

char *instructions_all[50] = {
    // 全局指令
    "help",  // 帮助指令 0
    "find",  // 查找知识点 1
    "clear", // 清屏 2
    "exit",  // 退出程序 3
    "find",  // 查找单词4
    "f",     // 同find 5
    "NULL"};

// 去除字符串首尾的空白字符
void trim(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    // 去除开头的空白字符
    while (start <= end && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
    {
        start++;
    }

    // 去除结尾的空白字符
    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
    {
        end--;
    }

    // 将处理后的字符串移到开头
    int i;
    for (i = 0; start <= end; i++, start++)
    {
        str[i] = str[start];
    }
    str[i] = '\0';
}
// 执行命令的函数
void execute(char *str)
{
    trim(str);
    char full_command[256] = {0};
    strcpy(full_command, str);

    // 分割命令为单词
    char *token = strtok(str, " ");
    if (token == NULL)
    {
        printf("提示：命令不存在！\n请重新输入！\n");
        return;
    }

    // 1.判读find指令
    if (strcasecmp(token, "find") == 0 || strcasecmp(token, "f") == 0)
    {
        token = strtok(NULL, " ");
        // 仅有f或者find时，提示输入要查找的单词
        if (token == NULL)
        {
            printf("%s%s请输入要查找的单词！%s\n", RED, BOLD, RESET);
            return;
        }

        char *third_token = strtok(NULL, " ");
        int library = 0;
        if (third_token != NULL)
        {
            char *fourth_token = strtok(NULL, " ");
            if (fourth_token != NULL)
            {
                // 有超过第三个单词，报错
                printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("find "), RESET, BOLD, RED, RESET);
                return;
            }

            if (third_token[0] == '-')
            {
                // 判断是否是 -4 或者 -6
                library = atoi(third_token + 1);
                if (library != 4 && library != 6)
                {
                    printf("%s%s当前%d库暂未录入！%s\n", RED, BOLD, library, RESET);
                    return;
                }
                if (library <= 0)
                {
                    printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("find "), RESET, BOLD, RED, RESET);
                    return;
                }
            }
            else
            {
                printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("find "), RESET, BOLD, RED, RESET);
                return;
            }
        }

        // 这里是返回条数的判断
        int results = 0;
        if (strstr(token, "%") == NULL)
        {
            // printf("%s%s%s%s--%s%s%s%s\n", RED, BOLD, token, RESET, BLUE, BOLD, token, RESET);

            // 查找特定单词
            results = search_word(token, library, 1); // 1代表查找单词
        }
        else if (token[0] == '%' && token[strlen(token) - 1] == '%')
        {
            // 去除前后的 %
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token + 1, len - 2);
                new_token[len - 2] = '\0';
                // printf("%s%s%s%s--%s%s%s%s\n", RED, BOLD, token, RESET, BLUE, BOLD, new_token, RESET);

                results = search_word(new_token, library, 2); // 2代表查找包含单词
                free(new_token);
            }
        }
        else if (token[strlen(token) - 1] == '%')
        {
            // 查找以特定后缀结尾的单词
            // 因为%在后面，所以是后缀
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token, len - 1);
                new_token[len - 1] = '\0';
                // printf("%s%s%s%s--%s%s%s%s\n", RED, BOLD, token, RESET, BLUE, BOLD, new_token, RESET);

                results = search_word(new_token, library, 3); // 4代表查找以单词为后缀
                free(new_token);
            }
        }
        else if (token[0] == '%')
        {
            // 查找以特定前缀结尾的单词
            // 因为%在前面，所以是前缀
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token + 1, len - 1);
                new_token[len - 1] = '\0';
                // printf("%s%s%s%s--%s%s%s%s\n", RED, BOLD, token, RESET, BLUE, BOLD, new_token, RESET);

                results = search_word(new_token, library, 4); // 3代表查找以单词为前缀
                free(new_token);
            }
        }

        // 这里提示没有找到匹配的单词
        if (results == 0)
        {
            // printf("%s%s%s%s%s%s--未找到匹配的单词。%s\n", BLUE, BOLD, token, RESET, RED, BOLD, RESET);
            return;
        }
    }
    // 2.判断exit指令
    else if (strcasecmp(token, "exit") == 0)
    {
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            // printf("%s%s退出程序！%s\n", RED, BOLD, RESET);
            exit_signal_handler(SIGINT); // 和ctrl+c一样的效果
        }
        else
        {
            printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("exit "), RESET, BOLD, RED, RESET);
        }
    }
    // 3.判断help指令
    else if (strcasecmp(token, "help") == 0)
    {
        help_list();
    }
    // 4.判断clear指令
    else if (strcasecmp(token, "clear") == 0)
    {
        clear();
    }
    // 4.判断其他指令
    else
    {
        printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command, RESET, BOLD, RED, RESET);
        find_similar_commands(full_command);
    }
}

/*
find 命令的形式：
find <查找字符> -<指定数据集>

void execute(char* str){
    先统一将传入命令trim，再判断，如果第一个单词是find，那么执行find命令，具体如下：

    if(如果第一个单词是find或者f，那么跳转到以下逻辑：){
        如果没有第二个单词，那么提示：请输入要查找的单词！
        如果只有两个单词，那么执行find命令，则在所有数据集里面查询，具体如下：
            如果第二个单词是str，那么查找单词str
            如果第二个单词是str%，那么查找以str为前缀的单词
            如果第二个单词是%str，那么查找以str为后缀的单词
            如果第二个单词是%str%，那么查找包含str的单词
        如果有第三个单词，那么是指定了查询数据集：
            如果第三个单词是-4，那么在四级词库里面查询
            如果第三个单词是-6，那么在六级词库里面查询
        如果有超过第三个单词，那么报错，提示无相关指令：
    }else if(如果第一个单词是exit，那么跳转到以下逻辑：){
        如果仅有一个单词，那么执行exit命令，输出退出程序！
        如果有超过一个单词，那么报错，无相关指令：
    }else{
        其他的任何命令，都报错：
        提示：命令不存在！
        请重新输入！
    }
}

*/