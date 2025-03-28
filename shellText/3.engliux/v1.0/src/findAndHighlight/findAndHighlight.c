#include "../../include/findAndHighlight.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 查找函数，返回匹配单词个数！
int find_if_exist(const char **word_set, int set_size, const char *target, int mode)
{
    if (!word_set || !target)
        return 0;

    int count = 0;
    for (int i = 0; i < set_size; i++)
    {
        const char(*entry)[3] = (const char(*)[3])word_set[i];

        // 严格验证数据结构
        if (!entry || !entry[0] || entry[1] == NULL || entry[2] == NULL)
        {
            continue; // 跳过不完整的条目
        }

        const char *word = entry[0]; // 只使用单词列进行匹配
        int match = 0;

        switch (mode)
        {
        case 1:
        //精确匹配
            match = (strcmp(word, target) == 0);
            break;
        case 2:
        // 包含匹配
            match = (strstr(word, target) != NULL);
            break;
        case 3:
        // 前缀匹配
            match = (strncmp(word, target, strlen(target)) == 0);
            break;
        case 4:
        {
            // 后缀匹配
            size_t tlen = strlen(target);
            size_t wlen = strlen(word);
            match = (wlen >= tlen) && (strcmp(word + wlen - tlen, target) == 0);
            break;
        }
        default:
            return -1;
        }

        if (match)
        {
            count++;
        }
    }
    return count;
}
// 高亮显示函数

#define COL_WIDTH 40 // 每列宽度
// 这是是二维数组，请你改为一维数组，即传*s喝*t比较，并高亮*s


// 高亮函数
int highlight(char *s, char *t)
{
    int flag = 0;
    char *p = s;
    while (*p)
    {
        if (strncmp(p, t, strlen(t)) == 0)
        {
            printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
            p += strlen(t);
            flag = 1;
        }
        else
        {
            putchar(*p);
            p++;
        }
    }
    printf("\n");
    return flag; // 判断是否找到！
}

// 查找并高亮函数
void find_and_highlight(const char **word_set, int set_size, const char *target,
                        int mode, int col1, int col2, int col3)
{
    // 验证输入参数
    if (!word_set || !target || set_size <= 0 || !word_set[0])
    {
        fprintf(stderr, "Invalid input parameters\n");
        return;
    }

    // 修正 highlight 函数调用
    highlight((char *)word_set[0], (char *)target);
    printf("=== 显示结束 ===\n\n");
}

