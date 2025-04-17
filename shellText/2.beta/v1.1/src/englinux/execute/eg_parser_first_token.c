#include "../../../include/englinux/execute/eg_parser_first_token.h"
int  parser_first_token(char *token, char *origin_str)
{
    if (!strcmp(token, "find") == 0 && !strcmp(token, "f") == 0)
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    return 1;
}