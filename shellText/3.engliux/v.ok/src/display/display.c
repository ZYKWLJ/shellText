#include "../../include/display.h"
// #include "display.h"
// #include "display.h"
// #include "display.h"
void show_contains_columns(const char ***words, int line, char *t,
                           int first_show, int second_show, int third_show)
{
    // 参数检查
    if (words == NULL || line < 0)
    {
        printf("参数错误！\n");
        return;
    }

    // 检查行结束标记
    if (words[line][0] == NULL)
    {
        printf("行号超出范围！\n");
        return;
    }

    // 显示第一列
    if (first_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        while (*p)
        {
            if (strncmp(p, t, strlen(t)) == 0)
            {
                printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                p += strlen(t);
                // flag = 1;
            }
            else
            {
                putchar(*p);
                p++;
            }
        }
    }
    else if (first_show > 1 && first_show <= 3)
    {
        printf("%-*s", COL1_WIDTH, words[line][first_show - 1]);
    }
    else if (first_show == 0)
    {
        printf("%-*s", COL1_WIDTH, "");
    }

    // 显示第二列
    if (second_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        while (*p)
        {
            if (strncmp(p, t, strlen(t)) == 0)
            {
                printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                p += strlen(t);
                // flag = 1;
            }
            else
            {
                putchar(*p);
                p++;
            }
        }
    }
    else if (second_show > 1 && second_show <= 3)
    {
        printf("%-*s", COL2_WIDTH, words[line][second_show - 1]);
    }
    else if (second_show == 0)
    {
        printf("%-*s", COL2_WIDTH, "");
    }

    // 显示第三列
    if (third_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        while (*p)
        {
            if (strncmp(p, t, strlen(t)) == 0)
            {
                printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                p += strlen(t);
                // flag = 1;
            }
            else
            {
                putchar(*p);
                p++;
            }
        }
    }
    else if (third_show > 1 && third_show <= 3)
    {
        printf("%-*s", COL3_WIDTH, words[line][third_show - 1]);
    }
    else if (third_show == 0)
    {
        printf("%-*s", COL3_WIDTH, "");
    }

    printf("\n");
}
void show_prefix_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show)
{
    // 参数检查
    if (words == NULL || line < 0)
    {
        printf("参数错误！\n");
        return;
    }

    // 检查行结束标记
    if (words[line][0] == NULL)
    {
        printf("行号超出范围！\n");
        return;
    }

    // 显示第一列
    if (first_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        printf("%s%s", BOLD, YELLOW);
        for (int k = 0; k < strlen(t); k++)
        {
            putchar(p[k]);
        }
        printf("%s", RESET);
        printf("%s", p + strlen(t));
    }
    else if (first_show > 1 && first_show <= 3)
    {
        printf("%-*s", COL1_WIDTH, words[line][first_show - 1]);
    }
    else if (first_show == 0)
    {
        printf("%-*s", COL1_WIDTH, "");
    }

    // 显示第二列
    if (second_show == 1)
    { // 高亮显示
        // 高亮显示
        const char *p = words[line][0];
        printf("%s%s", BOLD, YELLOW);
        for (int k = 0; k < strlen(t); k++)
        {
            putchar(p[k]);
        }
        printf("%s", RESET);
        printf("%s", p + strlen(t));
    }
    else if (second_show > 1 && second_show <= 3)
    {
        printf("%-*s", COL2_WIDTH, words[line][second_show - 1]);
    }
    else if (second_show == 0)
    {
        printf("%-*s", COL2_WIDTH, "");
    }

    // 显示第三列
    if (third_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        printf("%s%s", BOLD, YELLOW);
        for (int k = 0; k < strlen(t); k++)
        {
            putchar(p[k]);
        }
        printf("%s", RESET);
        printf("%s", p + strlen(t));
    }
    else if (third_show > 1 && third_show <= 3)
    {
        printf("%-*s", COL3_WIDTH, words[line][third_show - 1]);
    }
    else if (third_show == 0)
    {
        printf("%-*s", COL3_WIDTH, "");
    }

    printf("\n");
}

void show_suffix_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show)
{
    // 参数检查
    if (words == NULL || line < 0)
    {
        printf("参数错误！\n");
        return;
    }

    // 检查行结束标记
    if (words[line][0] == NULL)
    {
        printf("行号超出范围！\n");
        return;
    }

    // 显示第一列
    if (first_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        size_t suffix_len = strlen(t);
        size_t word_len = strlen(words[line][0]);
        const char *suffix_start = p + word_len - suffix_len;
        for (int k = 0; k < word_len - suffix_len; k++)
        {
            putchar(p[k]);
        }
        printf("%s%s", BOLD, YELLOW);
        for (int k = 0; k < suffix_len; k++)
        {
            putchar(suffix_start[k]);
        }
        printf("%s", RESET);
    }
    else if (first_show > 1 && first_show <= 3)
    {
        printf("%-*s", COL1_WIDTH, words[line][first_show - 1]);
    }
    else if (first_show == 0)
    {
        printf("%-*s", COL1_WIDTH, "");
    }

    // 显示第二列
    if (second_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        size_t suffix_len = strlen(t);
        size_t word_len = strlen(words[line][0]);
        const char *suffix_start = p + word_len - suffix_len;
        for (int k = 0; k < word_len - suffix_len; k++)
        {
            putchar(p[k]);
        }
        printf("%s%s", BOLD, YELLOW);
        for (int k = 0; k < suffix_len; k++)
        {
            putchar(suffix_start[k]);
        }
        printf("%s", RESET);
    }
    else if (second_show > 1 && second_show <= 3)
    {
        printf("%-*s", COL2_WIDTH, words[line][second_show - 1]);
    }
    else if (second_show == 0)
    {
        printf("%-*s", COL2_WIDTH, "");
    }

    // 显示第三列
    if (third_show == 1)
    { // 高亮显示
        const char *p = words[line][0];
        size_t suffix_len = strlen(t);
        size_t word_len = strlen(words[line][0]);
        const char *suffix_start = p + word_len - suffix_len;
        for (int k = 0; k < word_len - suffix_len; k++)
        {
            putchar(p[k]);
        }
        printf("%s%s", BOLD, YELLOW);
        for (int k = 0; k < suffix_len; k++)
        {
            putchar(suffix_start[k]);
        }
        printf("%s", RESET);
    }
    else if (third_show > 1 && third_show <= 3)
    {
        printf("%-*s", COL3_WIDTH, words[line][third_show - 1]);
    }
    else if (third_show == 0)
    {
        printf("%-*s", COL3_WIDTH, "");
    }

    printf("\n");
}

void show_own_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show)
{

    // 参数检查
    if (words == NULL || line < 0)
    {
        printf("参数错误！\n");
        return;
    }

    // 检查行结束标记
    if (words[line][0] == NULL)
    {
        printf("行号超出范围！\n");
        return;
    }

    // 显示第一列
    if (first_show == 1)
    { // 高亮显示
        printf("%s%s%s%s", BOLD, YELLOW, words[line][0], RESET);
    }
    else if (first_show > 1 && first_show <= 3)
    {
        printf("%-*s", COL1_WIDTH, words[line][first_show - 1]);
    }
    else if (first_show == 0)
    {
        printf("%-*s", COL1_WIDTH, "");
    }

    // 显示第二列
    if (second_show == 1)
    { // 高亮显示
        printf("%s%s%s%s", BOLD, YELLOW, words[line][0], RESET);
    }
    else if (second_show > 1 && second_show <= 3)
    {
        printf("%-*s", COL2_WIDTH, words[line][second_show - 1]);
    }
    else if (second_show == 0)
    {
        printf("%-*s", COL2_WIDTH, "");
    }

    // 显示第三列
    if (third_show == 1)
    { // 高亮显示
        printf("%s%s%s%s", BOLD, YELLOW, words[line][0], RESET);
    }
    else if (third_show > 1 && third_show <= 3)
    {
        printf("%-*s", COL3_WIDTH, words[line][third_show - 1]);
    }
    else if (third_show == 0)
    {
        printf("%-*s", COL3_WIDTH, "");
    }

    printf("\n");
}
