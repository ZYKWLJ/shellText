#include "../../../include/englinux/execute/eg_execute.h"
// #include "../../../include/englinux/lexer/lexer.h"

void eg_execute(char *str)
{
    // 1. 先将整个输入字符串转为小写
    for (char *p = str; *p; p++) {
        *p = tolower((unsigned char)*p);  // 使用unsigned char避免符号扩展问题
    }

    // printf("this is executor\n");
    // 调用词法分析器进行分析！
    // 词法分析器的作用是将输入的字符串分割成一个个的单词（token），并返回一个指向这些单词的指针数组。
    char *origin_str = (char *)malloc(strlen(str) * sizeof(char)); // 保留原始命令！
    strncpy(origin_str, str, strlen(str));
    int token_num;
    char *token[100];
    lexer(str, token, &token_num);
    // 按照token的类型进行逐步判断！
    // 先判错！
    if (token_num > 4) // 最长有4个单词！
    {                  // 肯定是无效指令，大于最长的了，先从数量上进行判断！
                       // printf("%s%s%s--无效指令！%s(按下%s%shelp%s查看指令表)\n", BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET); // 这里提示的信息也是原字符串！
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return;
    }
    // 单长度指令：
    else if (token_num == 1)
    {
        execute_one_token(token, token_num, origin_str);
    }
    else if (token_num == 2)
    {
        execute_two_token(token, token_num, origin_str);
    }
    else if (token_num == 3)
    {
        execute_three_token(token, token_num, origin_str);
    }
    else if (token_num == 4)
    {
        execute_four_token(token, token_num, origin_str);
    }
}

/*总命令：
单长度命令：
help
clear
exit
story
author
subject


多长度命令：
find/f -text
page/p -num
list/ls -num
*/