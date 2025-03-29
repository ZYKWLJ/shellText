#include "../../include/find.h"
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
void find_parser(char *token, char *full_command, int *library, int *search_mod, int *first_show, int *second_show, int *third_show)
{
    // 1.一定是find指令或者f指令
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
        printf("单词形式必须正确！\n");
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
    printf("find---判断第三个单词了!");
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
            // 什么都不输入，默认查询所有词库，输了就只能查看4或者6
            *library = atoi(third_token + 1);
            if (*library != 4 && *library != 6)
            {
                printf("%s%s当前%d库暂未录入！%s\n", RED, BOLD,*library, RESET);
                return;
            }
            if (*library <= 0)
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
    printf("find---判断第4个单词了!");

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

        *first_show = padded_token[0] - '0';
        *second_show = padded_token[1] - '0';
        *third_show = padded_token[2] - '0';

        if ((*first_show + *second_show + *third_show == 0))
        {
            printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
            return;
        }
    }
    else
    {
        // 如果没有第四个指令，默认显示单词和释义
        *first_show = 1;
        *second_show = 0;
        *third_show = 3;
    }

    // 精确查找
    if (strstr(token, "%") == NULL)
    {
        *search_mod = 1; // 1代表查找单词
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
            *search_mod = 2; // 2代表查找包含单词
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
            *search_mod = 3; // 3代表查找以单词为前缀
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
           *search_mod = 4; // 4代表查找以单词为后缀
            token = new_token;
        }
    }
}
