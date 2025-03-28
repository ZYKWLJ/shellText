#include "../../include/execute.h"

char *instructions_all[50] = {
    // 全局指令
    "help",  // 帮助指令 0
    "find",  // 查找知识点 1
    "clear", // 清屏 2
    "exit",  // 退出程序 3
    // "find",  // 查找单词4
    "f",     // 同find 5
    "NULL"
};

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

int is_all_alpha(char *token, int begin, int end)
{
    // %str% 形式
    for (int i = begin; i < end; i++)
    {
        if (!isalpha((unsigned char)token[i]))
        {
            return 0;
            break;
        }
    }
    return 1;
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
        // 单词形式判断，必须是str、%str、str%、%str% 的形式，并且 str 只能全是字母，不是则直接报错。
        else
        {
            int is_valid = 1;
            int len = strlen(token);
            if (len > 0)
            {

                if (token[0] == '%' && token[len - 1] == '%')
                {
                    // %str% 形式
                    is_valid = is_all_alpha(token, 1, len - 1);
                }
                else if (token[0] == '%')
                {
                    // %str 形式
                    is_valid = is_all_alpha(token, 1, len);
                }
                else if (token[len - 1] == '%')
                {
                    // str% 形式
                    is_valid = is_all_alpha(token, 0, len - 1);
                }
                else
                {
                    // str 形式
                    is_valid = is_all_alpha(token, 0, len);
                }
            }
            else
            {
                is_valid = 0;
            }

            if (!is_valid)
            {
                printf("%s%s无效的查找参数格式！%s(输入%s%shelp%s查看手册)\n", RED, BOLD, RESET, BOLD, YELLOW, RESET);
                return;
            }
        }

        int library = 0;
        int search_mod = 0;
        int first_show = 1, second_show = 0, third_show = 3; // 默认显示单词和释义

        char *third_token = strtok(NULL, " ");
        if (third_token != NULL)
        {

            if (third_token[0] == '-')
            {
                // 检查 - 后面是否为数字
                if (!isdigit((unsigned char)third_token[1]))
                {
                    printf("%s%s非数字！请输入有效的数字词库编号。(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                    return;
                }
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
            } // 第三个指令不以-开头，报错！
            else
            {
                printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("find "), RESET, BOLD, RED, RESET);
                return;
            }
        }

        // 判断第四个指令是否以-开头
        char *fourth_token = strtok(NULL, " ");
        if (fourth_token != NULL)
        {
            int len = strlen(fourth_token);
            int has_dash = 0;
            if (fourth_token[0] == '-')
            {
                has_dash = 1;
                fourth_token++;
                len--;
            }
            else
            {
                printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                return; // 指令出错，必须以-开头！
            }
            // 只能最多显示3列，超出直接报错！
            if (len > 3)
            {
                printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                return;
            }
            // 补齐到3位
            char padded_token[4] = "000";
            strncpy(padded_token + 3 - len, fourth_token, len);

            // 检查每个字符是否为 0 - 3
            for (int i = 0; i < 3; i++)
            {
                if (padded_token[i] < '0' || padded_token[i] > '3')
                {
                    printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                    return;
                }
            }

            first_show = padded_token[0] - '0';
            second_show = padded_token[1] - '0';
            third_show = padded_token[2] - '0';

            if ((first_show + second_show + third_show == 0))
            {
                printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                return;
            }
        }
        else
        {
            // 如果没有第四个指令，默认显示单词和释义
            first_show = 1;
            second_show = 0;
            third_show = 3;
        }

        // 精确查找
        if (strstr(token, "%") == NULL)
        {
            search_mod = 1; // 1代表查找单词
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
                search_mod = 2; // 2代表查找包含单词
                token = new_token;
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
                search_mod = 3; // 3代表查找以单词为前缀
                token = new_token;
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
                search_mod = 4; // 4代表查找以单词为后缀
                token = new_token;
            }
        }
        printf("搜索单词: %s, 词库: %d, 搜索模式: %d, 第一列显示: %d, 第二列显示: %d, 第三列显示: %d\n", token, library, search_mod, first_show, second_show, third_show);

        search_word(token, library, search_mod, first_show, second_show, third_show);
    }
    
    // 4.判断其他指令
    else
    {
        printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command, RESET, BOLD, RED, RESET);
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