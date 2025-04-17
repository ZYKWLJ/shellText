#include "../../../include/englinux/execute/eg_parser_fourth_token.h"
int parser_fourth_token(char *token, char *origin_str, int *firstcol_show, int *secondcol_show, int *thirdcol_show, int *fourthcol_show)
{
    // 1.先检查是不是5位参数
    // 大于直接pass
    if (strlen(token) > 5)
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;

    } // 小于的话，后面补0直至到5位
    else if (strlen(token) < 5)
    {
        // 不足的5位参数，后面补上0
        char *new_token = (char *)malloc(6); // 分配足够的空间，包括字符串结束符 '\0'
        if (new_token == NULL)
        {
            perror("malloc");
            return 0;
        }
        strcpy(new_token, token);
        for (int i = strlen(token); i < 5; i++)
        {
            new_token[i] = '0';
        }
        new_token[5] = '\0';
        token = new_token; // 使用新的字符串
    }
    // 2.再检查是不是-开头
    if (token[0] != '-')
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    // 3.再检查剩下的是不是1~4之间的数字
    // 第一列显示
    if (token[1] < '0' || token[1] > '4')
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    *firstcol_show = token[1] - '0';

    // 第二列显示
    if (token[2] < '0' || token[2] > '4')
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    *secondcol_show = token[2] - '0';

    // 第三列显示
    if (token[3] < '0' || token[3] > '4')
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    *thirdcol_show = token[3] - '0';

    // 第四列显示
    if (token[4] < '0' || token[4] > '4')
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    *fourthcol_show = token[4] - '0';
    return 1;
}