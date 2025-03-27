#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

// 假设这些函数已经实现，现在改为两个参数
char **search_word(const char *word, int library){
    printf("在%d库中查找单词：%s\n", library, word);
    return NULL;
}
char **search_prefix(const char *prefix, int library){
    printf("在%d库中查找前缀单词：%s\n", library, prefix);
    return NULL;
}
char **search_suffix(const char *suffix, int library){
    printf("在%d库中查找后缀单词：%s\n", library, suffix);
    return NULL;
}
char **search_contains(const char *str, int library){
     printf("在%d库中查找包含单词：%s\n", library, str);
    return NULL;
}

void help_list(){
    printf("help----find [word] [library]\n");
}
void clear(){
    printf("clear----清除屏幕\n");
}
void exit_signal_handler(int signum){
    printf("\n程序终止\n");
}
void find_similar_commands(const char *command){
    printf("find----相似命令\n");
}

#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

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
                library = atoi(third_token + 1);
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

        char **results = NULL;
        if (strstr(token, "%") == NULL)
        {
            // 查找特定单词
            results = search_word(token, library);
        }
        else if (token[0] == '%' && token[strlen(token) - 1] == '%')
        {
            // 去除前后的 %
            token[strlen(token) - 1] = '\0';
            results = search_contains(token + 1, library);
        }
        else if (token[0] == '%')
        {
            // 查找以特定后缀结尾的单词
            results = search_suffix(token + 1, library);
        }
        else if (token[strlen(token) - 1] == '%')
        {
            // 去除结尾的 %
            token[strlen(token) - 1] = '\0';
            results = search_prefix(token, library);
        }

        if (results != NULL)
        {
            if (results[0] == NULL)
            {
                printf("%s%s%s%s%s%s--未找到匹配的单词。%s\n", BLUE, BOLD, token, RESET, RED, BOLD, RESET);
            }
            else
            {
                for (int i = 0; results[i] != NULL; i++)
                {
                    printf("%s\n", results[i]);
                }
            }
            free(results);
        }
        else
        {
            printf("%s%s%s%s%s%s--未找到匹配的单词。%s\n", BLUE, BOLD, token, RESET, RED, BOLD, RESET);
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
