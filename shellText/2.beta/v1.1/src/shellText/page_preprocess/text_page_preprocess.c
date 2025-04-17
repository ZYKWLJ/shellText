#include "../../../include/shellText/text_page_preprocess.h"
/*
void page_preprocess(char *str)
作用：伪代码
背景：str是用户输入的字符串，可能包含多个单词，每个单词之间用空格分隔
其中，str在前面已经确定以page或者p开头，接下来的单词可能是数字，也可能是其他字符
任务：检查接下来的字符：
0. 如果没有任何字符，输出“您未输出页面号!”
1. 如果是单独的一个数字num，输出“这是num页面内容”
2. 其余任何情况(包括多个单词、跟一个包含非数字的单词)，请你输出除了第一个单词之后的所有命令(之间的空格也不能省略)，并指示非有效页面。如printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, invalid_part, RESET);

*/

// 去除字符串头尾的空格
void trim(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    // 去除开头的空格
    while (start < len && isspace(str[start]))
    {
        start++;
    }

    // 去除结尾的空格
    while (end > start && isspace(str[end]))
    {
        end--;
    }

    // 移动字符串内容
    int i;
    for (i = 0; i <= end - start; i++)
    {
        str[i] = str[start + i];
    }
    str[i] = '\0';
}

void page_preprocess(char *str)
{
    trim(str);

    // 跳过开头的 "page" 或 "p" 以及后面的空格
    if (strncmp(str, "page", 4) == 0)
    {
        str += 4;
    }
    else if (strncmp(str, "p", 1) == 0)
    {
        str += 1;
    }
    while (*str == ' ')
    {
        str++;
    }

    // 如果没有任何字符
    if (*str == '\0')
    {
        printf("%s%s您未输出页面号!%s\n",RED,BOLD,RESET);
        return;
    }

    // 检查是否为单独的一个数字
    int is_digit = 1;
    char *start = str;
    while (*str != '\0' && *str != ' ')
    {
        if (!isdigit(*str))
        {
            is_digit = 0;
            break;
        }
        str++;
    }

    if (is_digit && *str == '\0')
    {
        
        if (atoi(start) > 400)
        {
            printf("本书仅有%s%s400%s页，%s%s%d%s超页\n", BOLD, GREEN, RESET, BOLD, RED, atoi(start), RESET);
        }
        else
        {
            show_page(atoi(start));
        }

        // printf("这是%s页面内容\n", start);
    }
    else
    {
        // 其余情况
        printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, start, RESET);
    }
}
