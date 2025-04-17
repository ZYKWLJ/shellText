#include "../../../include/englinux/execute/eg_parser_third_token.h"
int parser_third_token(char *token, char *origin_str, int *library_index)
{
    if (token[0] != '-')
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    else
    {
        char *ptr = token + 1;
        if (is_all_digit(ptr) == 0)
        {
            printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
            return 0;
        }
        *library_index = atoi(ptr);
        if (*library_index != 4 && *library_index != 6)
        {
            printf(ERROR_LIB_NOT_EXIST, BOLD, RED, *library_index, RESET);
            return 0;
        }

        // printf("库索引为:%d\n", *library_index);
        *library_index = *library_index == 4 ? 0 : 1;
        return 1;
    }
}
