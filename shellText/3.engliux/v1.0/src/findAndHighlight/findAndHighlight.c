#include "../../include/findAndHighlight.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 计算部分匹配表（next 数组）
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP 搜索算法
int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int) * M);
    if (lps == NULL) {
        perror("malloc");
        return 0;
    }
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            count++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    free(lps);
    return count;
}

// 在字符串数组 s 中查找字符串 t，返回匹配的条数
int find_if_exist(const char **s, int s_size, char *t, int mod)
{
    int total_count = 0;
    for (int i = 0; i < s_size; i++)
    {
        int match = 0;
        switch (mod)
        {
            case 1: // 精确查找单词
                match = strcmp(s[i], t) == 0;
                total_count += match;
                break;
            case 2: // 包含查找
                total_count += KMPSearch(t, (char *)s[i]);
                break;
            case 3: // 前缀查找
                match = strncmp(s[i], t, strlen(t)) == 0;
                total_count += match;
                break;
            case 4: // 后缀查找
            {
                size_t suffix_len = strlen(t);
                size_t word_len = strlen(s[i]);
                match = word_len >= suffix_len && strcmp(s[i] + word_len - suffix_len, t) == 0;
                total_count += match;
            }
            break;
            default:
                fprintf(stderr, "无效的查找模式: %d\n", mod);
                break;
        }
    }
    return total_count;
}

// 高亮显示匹配的字符串
int find_and_highlight(const char **s, int s_size, char *t, int mod)
{
    int flag = 0;
    int first = 1;
    int count = 0;
    for (int i = 0; i < s_size; i++)
    {
        int found = 0;
        switch (mod)
        {
            case 1: // 精确查找单词
                found = strcmp(s[i], t) == 0;
                break;
            case 2: // 包含查找
                found = KMPSearch(t, (char *)s[i]) > 0;
                break;
            case 3: // 前缀查找
                found = strncmp(s[i], t, strlen(t)) == 0;
                break;
            case 4: // 后缀查找
            {
                size_t suffix_len = strlen(t);
                size_t word_len = strlen(s[i]);
                found = word_len >= suffix_len && strcmp(s[i] + word_len - suffix_len, t) == 0;
            }
            break;
            default:
                fprintf(stderr, "无效的查找模式: %d\n", mod);
                break;
        }

        if (found)
        {
            if (!first)
            {
                // putchar(',');
                // puts("");
            }
            const char *p = s[i];
            if (mod == 2)
            {
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
            }
            else if (mod == 3) // 前缀查找
            {
                printf("%s%s", BOLD, YELLOW);
                for (int k = 0; k < strlen(t); k++) {
                    putchar(p[k]);
                }
                printf("%s", RESET);
                printf("%s", p + strlen(t));
                flag = 1;
            }
            else if (mod == 4) // 后缀查找
            {
                size_t suffix_len = strlen(t);
                size_t word_len = strlen(s[i]);
                const char *suffix_start = p + word_len - suffix_len;
                for (int k = 0; k < word_len - suffix_len; k++) {
                    putchar(p[k]);
                }
                printf("%s%s", BOLD, YELLOW);
                for (int k = 0; k < suffix_len; k++) {
                    putchar(suffix_start[k]);
                }
                printf("%s", RESET);
                flag = 1;
            }
            else
            {
                printf("%s%s%s%s", BOLD, YELLOW, s[i], RESET);
            }
            first = 0;
            printf("\n\n");
        }
    }
    return flag;
}

// int main()
// {
//     // char *s[] = {"ABCDDAB", "ABC","ABDCG","AD", "AM"};
//     // char t[] = "AB";
//     char *s[] = {"你好啊，你在干什么", "大家好", "你人真好", "使得", "江口", "好了不起的人啊", "对流层的人呢！"};
//     char t[] = "好";
//     int s_size = sizeof(s) / sizeof(s[0]); // 每一个指针的大小相等！所以这里可以借此得到长度！
//     puts("精确查找:");
//     // printf("find_if_exist(s, s_size, t, 1) = %d\n", find_if_exist(s, s_size, t, 1));
//     find_and_highlight(s, s_size, t, 1);
//     puts("包含查找:");

//     find_and_highlight(s, s_size, t, 2);
//     puts("前缀查找:");

//     find_and_highlight(s, s_size, t, 3);
//     puts("后缀查找:");

//     find_and_highlight(s, s_size, t, 4);

//     return 0;
// }