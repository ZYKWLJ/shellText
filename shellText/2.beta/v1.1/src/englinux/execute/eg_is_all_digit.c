# include "../../../include/englinux/execute/eg_is_all_digit.h"
int is_all_digit(const char *token)
{
    // %str% 形式
    for (int i = 0; token[i]; i++)
    {
        if (!isdigit((unsigned char)token[i]))
        {
            return 0;
            break;
        }
    }
    return 1;
}

int is_all_alpha(const char *token)
{
    // %str% 形式
    for (int i = 0; token[i]; i++)
    {
        if (!isalpha((unsigned char)token[i]))
        {
            return 0;
            break;
        }
    }
    return 1;
}

