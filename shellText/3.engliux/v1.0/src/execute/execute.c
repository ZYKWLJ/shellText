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
            // 查找以特定前缀结尾的单词
            // 因为%在后面，所以是前缀
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token, len - 1);
                new_token[len - 1] = '\0';
                // printf("%s%s%s%s--%s%s%s%s\n", RED, BOLD, token, RESET, BLUE, BOLD, new_token, RESET);

                results = search_word(new_token, library, 3); // 3代表查找以单词为前缀
                free(new_token);
            }
        }
        else if (token[0] == '%')
        {
            // 查找以特定后缀结尾的单词
            // 因为%在前面，所以是后缀
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token + 1, len - 1);
                new_token[len - 1] = '\0';
                // printf("%s%s%s%s--%s%s%s%s\n", RED, BOLD, token, RESET, BLUE, BOLD, new_token, RESET);

                results = search_word(new_token, library, 4); // 4代表查找以单词为后缀
                free(new_token);
            }
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

/*

我的源码如上，并没有提提供显示方式，所以我需要提供一个显示方式，这个显示方式是可以自定义的，具体如下：

带单词、音标、释义的单词库：
总的显示：
单词(1)     音标(2)      释义(3)
find <查找字符> -<指定数据集> -[1|2|3]
find命令共有4种形式：
if(如果第一个单词是find或者f，那么跳转到以下逻辑：){
// 接下来的目的就是明确token、library、search_mod、first_show、second_show、third show这六个变量的值，然后最后在调用search_word函数！！
// 逻辑如下：
        如果没有第二个单词，那么提示：请输入要查找的单词！

        如果只有两个单词，那么执行find命令，则在所有数据集里面查询，具体如下：
            如果第二个单词是str，那么查找单词str，默认显示单词、释义(也就是1，3)
            如果第二个单词是str%，那么查找以str为前缀的单词，默认显示单词、释义(也就是1，3)
            如果第二个单词是%str，那么查找以str为后缀的单词，默认显示单词、释义(也就是1，3)
            如果第二个单词是%str%，那么查找包含str的单词，默认显示单词、释义(也就是1，3)

        如果有第三个单词，那么是指定了查询数据集：
            如果第三个单词是-4，那么在四级词库里面查询
            如果第三个单词是-6，那么在六级词库里面查询

        如果没有第四个单词，那么默认显示单词、释义(也就是1，3)

        如果有第四个单词，那么是指定了查询字段：其中    1代表单词   2代表音标      3代表释义
        // 其中，先后按下的顺序是在电脑上显示的顺序，电脑上一共最多显示3列，但是可以自定义显示方式！从数量上，可以自定义显示1~3列，从位置上，可以自定义1~3列的位置显示什么内容！我们不提供不同列显示相内容，这无实际意义并且占用空间！
        
        // 首先是第四个单词不足3位的情况：自动扩展！
            如果第四个单词是1，那么扩展为100，即只显示单词，则first_show=1，second_show=0，third_show=0
            如果第四个单词是2，那么扩展为200，即只显示音标，则first_show=2，second_show=，third_show=0
            如果第四个单词是3，那么扩展为300，即只显示释义，则first_show=3，second_show=0，third_show=0
            如果第四个单词是12，那么扩展为120，即显示单词-音标，则first_show=1，second_show=2，third_show=0
            如果第四个单词是21，那么扩展为210，即显示音标-单词，则first_show=2，second_show=1，third_show=0
            如果第四个单词是13，那么扩展为130，即显示单词-释义，则first_show=1，second_show=3，third_show=0
            如果第四个单词是31，那么扩展为310，即显示释义-单词，则first_show=3，second_show=1，third_show=0
            如果第四个单词是23，那么扩展为230，即显示音标-释义，则first_show=2，second_show=3，third_show=0
            如果第四个单词是32，那么扩展为320，即显示释义-音标，则first_show=3，second_show=2，third_show=0

        // 然后是第四个单词等于3位的情况：每一位都可以以0~3的数字表示，分别表示该列显示什么内容，0代表不显示，1代表显示单词，2代表显示音标，3代表显示释义
            第四单词数字	first_show	second_show	third_show	显示内容
            001	0	0	1	显示释义
            002	0	0	2	显示音标
            010	0	1	0	显示音标
            012	0	1	2	显示音标 - 释义
            013	0	1	3	显示音标 - 单词
            020	0	2	0	显示音标
            021	0	2	1	显示音标 - 单词
            023	0	2	3	显示音标 - 释义
            030	0	3	0	显示释义
            031	0	3	1	显示释义 - 单词
            032	0	3	2	显示释义 - 音标
            100	1	0	0	显示单词
            102	1	0	2	显示单词 - 音标
            103	1	0	3	显示单词 - 释义
            120	1	2	0	显示单词 - 音标
            123	1	2	3	显示单词 - 音标 - 释义
            130	1	3	0	显示单词 - 释义
            132	1	3	2	显示单词 - 释义 - 音标
            200	2	0	0	显示音标
            201	2	0	1	显示音标 - 单词
            203	2	0	3	显示音标 - 释义
            210	2	1	0	显示音标 - 单词
            213	2	1	3	显示音标 - 单词 - 释义
            230	2	3	0	显示音标 - 释义
            231	2	3	1	显示音标 - 释义 - 单词
            300	3	0	0	显示释义
            301	3	0	1	显示释义 - 单词
            302	3	0	2	显示释义 - 音标
            310	3	1	0	显示释义 - 单词
            312	3	1	2	显示释义 - 单词 - 音标
            320	3	2	0	显示释义 - 音标
            321	3	2	1	显示释义 - 音标 - 单词
            330	3	3	0	显示释义 - 音标 - 释义
        如果第四个单词不在这里面

        如果有超过第四个单词，那么报错，提示无相关指令：

现在请你实现这个需求：
*/
// 总的下来，search_word(char*token, int library, int search_mod/*指定精确查询，包含查询，前缀查询，后缀查询*/, int  first_show,/*指定在终端第一列显示的什么，为0不显示，为1则显示单词，为2则显示音标，为3则显示释义*/, int  second_show,/*指定在终端第二列显示的什么，为0不显示，为1则显示单词，为2则显示音标，为3则显示释义*/, int  third_show/*指定在终端第三列显示的什么，为0不显示，为1则显示单词，为2则显示音标，为3则显示释义*/)
//  把这个查询函数是实现了就OK了！！