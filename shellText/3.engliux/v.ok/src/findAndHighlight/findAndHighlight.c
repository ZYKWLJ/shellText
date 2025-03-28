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
    if (lps == NULL)
    {
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
// int find_if_exist(char ***s, int s_size, char *t, int search_mod) {
//     // 增强参数检查
//     if (s == NULL || t == NULL || *t == '\0' || s_size <= 0) {
//         fprintf(stderr, "错误：无效的输入参数！\n");
//         return 0;
//     }

//     printf("进入查找是否存在阶段：\n");
//     int total_count = 0;

//     for (int i = 0; i < s_size; i++) {
//         // 增强指针检查
//         if (s[i] == NULL) {
//             printf("警告：s[%d]为NULL指针\n", i);
//             continue;
//         }

//         printf("检查s[%d][0]...", i);
//         if (s[i][0] == NULL) {
//             printf("s[%d][0]为NULL\n", i);
//             continue;
//         }
//         printf("OK\n");

//         char *word = s[i][0]; // 单词文本
//         printf("当前处理单词[%d]: %s\n", i, word);

//         int match = 0;
//         switch (search_mod) {
//         case 1: // 精确查找
//             match = (strcmp(word, t) == 0);
//             break;

//         case 2: // 包含查找
//             match = (KMPSearch(t, word) != -1);
//             break;

//         case 3: // 前缀查找
//             match = (strncmp(word, t, strlen(t)) == 0);
//             break;

//         case 4: // 后缀查找
//             {
//                 size_t suffix_len = strlen(t);
//                 size_t word_len = strlen(word);
//                 match = (word_len >= suffix_len) && 
//                        (strcmp(word + word_len - suffix_len, t) == 0);
//             }
//             break;

//         default:
//             fprintf(stderr, "警告：无效的查找模式: %d\n", search_mod);
//             return -1;
//         }

//         if (match) {
//             total_count++;
//             printf(">>> 匹配到: %s\n", word);
//         }
//     }

//     printf("查找结束，共找到 %d 个匹配项\n", total_count);
//     return total_count;
// }

int find_if_exist(const char ***word_list, int list_size, const char *target, int search_mode) {
    // 参数检查
    if (word_list == NULL || target == NULL || *target == '\0') {
        fprintf(stderr, "错误：无效的输入参数！\n");
        return 0;
    }

    printf("正在查找: %s (模式: %d)\n", target, search_mode);
    int total_count = 0;

    for (int i = 0; i < list_size && word_list[i] != NULL; i++) {
        // 获取单词条目
        printf("检查单词列表中的第 %d 个条目...\n", i);
        const char *word = word_list[i][0];
        if (word == NULL) continue;

        printf("检查单词: %s\n", word);

        int match = 0;
        switch (search_mode) {
        case 1: // 精确匹配
            match = (strcmp(word, target) == 0);
            break;
        case 2: // 包含
            match = (strstr(word, target) != NULL);
            break;
        case 3: // 前缀
            match = (strncmp(word, target, strlen(target)) == 0);
            break;
        case 4: // 后缀
            {
                size_t target_len = strlen(target);
                size_t word_len = strlen(word);
                match = (word_len >= target_len) && 
                       (strcmp(word + word_len - target_len, target) == 0);
            }
            break;
        default:
            fprintf(stderr, "错误：无效的搜索模式 %d\n", search_mode);
            return -1;
        }

        if (match) {
            total_count++;
            printf(">>> 匹配 #%d: %s\n", total_count, word);
        }
    }

    printf("查找完成，共找到 %d 个匹配项\n", total_count);
    return total_count;
}
// 高亮显示匹配的字符串
int find_and_highlight(const char ***s, int s_size, char *t, int search_mod, int first_show, int second_show, int third_show)
{
    printf("进入高亮显示阶段：\n");
    // int flag = 0;//因为查找在上面已经完成了，所以这里就不用判断了！只需要高亮显示即可！
    int first = 1;
    // int count = 0;
    for (int i = 0; i < s_size; i++)
    {
        int found = 0;
        switch (search_mod)
        {
        case 1: // 精确查找单词
            found = strcmp(s[i][0], t) == 0;
            break;
        case 2: // 包含查找
            found = KMPSearch(t, (char *)s[i][0]) > 0;
            break;
        case 3: // 前缀查找
            found = strncmp(s[i][0], t, strlen(t)) == 0;
            break;
        case 4: // 后缀查找
        {
            size_t suffix_len = strlen(t);
            size_t word_len = strlen(s[i][0]);
            found = word_len >= suffix_len && strcmp(s[i][0] + word_len - suffix_len, t) == 0;
        }
        break;
        default:
            fprintf(stderr, "无效的查找模式: %d\n", search_mod);
            break;
        }

        // 已经能找到了！
        if (found)
        {
            if (!first)
            {
                // putchar(',');
                // puts("");
            }
            const char *p = s[i][0];
            // 包含查找
            if (search_mod == 2)
            {
                printf("进入包含查找阶段：\n");
                show_contains_columns(s, i, t, first_show, second_show, third_show);
                // while (*p)
                // {
                //     if (strncmp(p, t, strlen(t)) == 0)
                //     {
                //         printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                //         p += strlen(t);
                //         // flag = 1;
                //     }
                //     else
                //     {
                //         putchar(*p);
                //         p++;
                //     }
                // }
            }
            else if (search_mod == 3) // 前缀查找
            {
                printf("进入前缀查找阶段：\n");
                // printf("%s%s", BOLD, YELLOW);
                // for (int k = 0; k < strlen(t); k++)
                // {
                //     putchar(p[k]);
                // }
                // printf("%s", RESET);
                // printf("%s", p + strlen(t));
                show_prefix_columns(s, i, t, first_show, second_show, third_show);

                // flag = 1;
                // 输出剩下的两个维度，这里就看传入的参数了！
            }
            else if (search_mod == 4) // 后缀查找
            {
                printf("进入后缀查找阶段：\n");
                show_suffix_columns(s, i, t, first_show, second_show, third_show);

                // size_t suffix_len = strlen(t);
                // size_t word_len = strlen(s[i][0]);
                // const char *suffix_start = p + word_len - suffix_len;
                // for (int k = 0; k < word_len - suffix_len; k++)
                // {
                //     putchar(p[k]);
                // }
                // printf("%s%s", BOLD, YELLOW);
                // for (int k = 0; k < suffix_len; k++)
                // {
                //     putchar(suffix_start[k]);
                // }
                // printf("%s", RESET);
                // flag = 1;
            }
            // 精确查找
            else
            {
                printf("进入精确查找阶段：\n");
                show_own_columns(s, i, t, first_show, second_show, third_show);
                // printf("%s%s%s%s", BOLD, YELLOW, s[i], RESET);
            }
            first = 0;
            printf("\n\n");
        }
    }
    printf("高亮完毕！\n");
    // return flag;
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