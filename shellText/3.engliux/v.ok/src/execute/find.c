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
void find_parser(char *token, char *full_command)
{
    int library = 0;
    int search_mod = 0;
    int first_show = 1, second_show = 0, third_show = 3; // 默认显示单词和释义

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        printf("%s%s请输入要查找的单词！%s\n", RED, BOLD, RESET);
        return;
    }

    // 检查单词格式
    int is_valid = 1;
    int len = strlen(token);
    if (len > 0)
    {
        if (token[0] == '%' && token[len - 1] == '%')
        {
            is_valid = is_all_alpha(token, 1, len - 1);
        }
        else if (token[0] == '%')
        {
            is_valid = is_all_alpha(token, 1, len);
        }
        else if (token[len - 1] == '%')
        {
            is_valid = is_all_alpha(token, 0, len - 1);
        }
        else
        {
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

    // 解析第三个参数（词库编号）
    char *third_token = strtok(NULL, " ");
    if (third_token != NULL)
    {
        if (third_token[0] == '-' && isdigit((unsigned char)third_token[1]))
        {
            library = atoi(third_token + 1);
            if (library != 4 && library != 6)
            {
                printf("%s%s当前%d库暂未录入！%s\n", RED, BOLD, library, RESET);
                return;
            }
        }
        else
        {
            printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("find "), RESET, BOLD, RED, RESET);
            return;
        }
    }

    // 解析第四个参数（显示模式）
    char *fourth_token = strtok(NULL, " ");
    if (fourth_token != NULL)
    {
        if (fourth_token[0] != '-')
        {
            printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
            return;
        }

        int display_option = atoi(fourth_token + 1);
        if (display_option < 0 || display_option > 333)
        {
            printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
            return;
        }

        first_show = (display_option / 100) % 10;
        second_show = (display_option / 10) % 10;
        third_show = display_option % 10;

        if (first_show + second_show + third_show == 0)
        {
            printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
            return;
        }
    }

    // 解析搜索模式
    if (!strchr(token, '%'))
    {
        search_mod = 1; // 精确查找
    }
    else if (token[0] == '%' && token[len - 1] == '%')
    {
        token[len - 1] = '\0';
        token++;
        search_mod = 2; // 模糊查找
    }
    else if (token[len - 1] == '%')
    {
        token[len - 1] = '\0';
        search_mod = 3; // 以 token 为前缀
    }
    else if (token[0] == '%')
    {
        token++;
        search_mod = 4; // 以 token 为后缀
    }
    printf("搜索单词: %s, 词库: %d, 搜索模式: %d, 第一列显示: %d, 第二列显示: %d, 第三列显示: %d\n", token, library, search_mod, first_show, second_show, third_show);
    // 执行搜索
    search_word(token, library, search_mod, first_show, second_show, third_show);
}

// printf("搜索单词: %s, 词库: %d, 搜索模式: %d, 第一列显示: %d, 第二列显示: %d, 第三列显示: %d\n", token, *library, *search_mod, *first_show, *second_show,*third_show);
