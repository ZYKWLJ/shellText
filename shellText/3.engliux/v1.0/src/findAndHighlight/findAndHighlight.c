#include "../../include/findAndHighlight.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// // 高亮显示匹配的字符串
// int find_and_highlight(const char ***s, int s_size, char *t, int search_mod, int first_show, int second_show, int third_show)
// {
//     printf("进入高亮显示阶段：\n");
//     // int flag = 0;//因为查找在上面已经完成了，所以这里就不用判断了！只需要高亮显示即可！
//     int first = 1;
//     // int count = 0;
//     for (int i = 0; i < s_size; i++)
//     {
//         int found = 0;
//         switch (search_mod)
//         {
//         case 1: // 精确查找单词
//             found = strcmp(s[i][0], t) == 0;
//             break;
//         case 2: // 包含查找
//             found = KMPSearch(t, (char *)s[i][0]) > 0;
//             break;
//         case 3: // 前缀查找
//             found = strncmp(s[i][0], t, strlen(t)) == 0;
//             break;
//         case 4: // 后缀查找
//         {
//             size_t suffix_len = strlen(t);
//             size_t word_len = strlen(s[i][0]);
//             found = word_len >= suffix_len && strcmp(s[i][0] + word_len - suffix_len, t) == 0;
//         }
//         break;
//         default:
//             fprintf(stderr, "无效的查找模式: %d\n", search_mod);
//             break;
//         }

//         // 已经能找到了！
//         if (found)
//         {
//             if (!first)
//             {
//                 // putchar(',');
//                 // puts("");
//             }
//             const char *p = s[i][0];
//             // 包含查找
//             if (search_mod == 2)
//             {
//                 printf("进入包含查找阶段：\n");
//                 show_contains_columns(s, i, t, first_show, second_show, third_show);
//                 // while (*p)
//                 // {
//                 //     if (strncmp(p, t, strlen(t)) == 0)
//                 //     {
//                 //         printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
//                 //         p += strlen(t);
//                 //         // flag = 1;
//                 //     }
//                 //     else
//                 //     {
//                 //         putchar(*p);
//                 //         p++;
//                 //     }
//                 // }
//             }
//             else if (search_mod == 3) // 前缀查找
//             {
//                 printf("进入前缀查找阶段：\n");
//                 // printf("%s%s", BOLD, YELLOW);
//                 // for (int k = 0; k < strlen(t); k++)
//                 // {
//                 //     putchar(p[k]);
//                 // }
//                 // printf("%s", RESET);
//                 // printf("%s", p + strlen(t));
//                 show_prefix_columns(s, i, t, first_show, second_show, third_show);

//                 // flag = 1;
//                 // 输出剩下的两个维度，这里就看传入的参数了！
//             }
//             else if (search_mod == 4) // 后缀查找
//             {
//                 printf("进入后缀查找阶段：\n");
//                 show_suffix_columns(s, i, t, first_show, second_show, third_show);

//                 // size_t suffix_len = strlen(t);
//                 // size_t word_len = strlen(s[i][0]);
//                 // const char *suffix_start = p + word_len - suffix_len;
//                 // for (int k = 0; k < word_len - suffix_len; k++)
//                 // {
//                 //     putchar(p[k]);
//                 // }
//                 // printf("%s%s", BOLD, YELLOW);
//                 // for (int k = 0; k < suffix_len; k++)
//                 // {
//                 //     putchar(suffix_start[k]);
//                 // }
//                 // printf("%s", RESET);
//                 // flag = 1;
//             }
//             // 精确查找
//             else
//             {
//                 printf("进入精确查找阶段：\n");
//                 show_own_columns(s, i, t, first_show, second_show, third_show);
//                 // printf("%s%s%s%s", BOLD, YELLOW, s[i], RESET);
//             }
//             first = 0;
//             printf("\n\n");
//         }
//     }
//     printf("高亮完毕！\n");
//     // return flag;
// }



// KMP算法相关函数
void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(M * sizeof(int));
    if (!lps) return -1;
    
    computeLPSArray(pat, M, lps);
    
    int i = 0, j = 0, count = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++; i++;
        }
        if (j == M) {
            count++;
            j = lps[j-1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
    free(lps);
    return count;
}

// 查找函数
int find_if_exist(const char **word_set, int set_size, const char *target, int mode) {
    if (!word_set || !target) return 0;
    
    int count = 0;
    for (int i = 0; i < set_size; i++) {
        const char (*entry)[3] = (const char (*)[3])word_set[i];
        if (!entry || !entry[0]) continue;
        
        const char *word = entry[0];
        int match = 0;
        
        switch (mode) {
            case 1: match = (strcmp(word, target) == 0); break;
            case 2: match = (strstr(word, target) != NULL); break;
            case 3: match = (strncmp(word, target, strlen(target)) == 0); break;
            case 4: {
                size_t tlen = strlen(target);
                size_t wlen = strlen(word);
                match = (wlen >= tlen) && (strcmp(word + wlen - tlen, target) == 0);
                break;
            }
            default: return -1;
        }
        
        if (match) {
            count++;
            printf("匹配: %s\n", word);
        }
    }
    return count;
}

// 高亮显示函数
// void find_and_highlight(const char **word_set, int set_size, const char *target, 
//                        int mode, int col1, int col2, int col3) {
//     for (int i = 0; i < set_size; i++) {
//         const char (*entry)[3] = (const char (*)[3])word_set[i];
//         if (!entry || !entry[0]) continue;
        
//         // 匹配逻辑与find_if_exist相同
//         int match = 0;
//         /* ... */
        
//         if (match) {
//             // 根据显示选项输出
//             if (col1 > 0 && col1 <= 3) printf("%-20s", entry[col1-1]);
//             if (col2 > 0 && col2 <= 3) printf("%-20s", entry[col2-1]);
//             if (col3 > 0 && col3 <= 3) printf("%-20s", entry[col3-1]);
//             printf("\n");
//         }
//     }
// }

// 高亮显示函数
void find_and_highlight(const char **word_set, int set_size, const char *target, 
                       int mode, int col1, int col2, int col3) 
{
    printf("=== 高亮显示 ===\n");
    printf("模式: %d | 显示列: %d-%d-%d\n", mode, col1, col2, col3);
    
    for (int i = 0; i < set_size; i++) {
        const char (*entry)[3] = (const char (*)[3])word_set[i];
        if (!entry || !entry[0]) continue;
        
        const char *word = entry[0];
        const char *phonetic = entry[1];
        const char *meaning = entry[2];
        
        // 匹配判断
        int match = 0;
        size_t target_len = strlen(target);
        size_t word_len = strlen(word);
        
        switch (mode) {
            case 1:  // 精确匹配
                match = (strcmp(word, target) == 0);
                break;
            case 2:  // 包含
                match = (strstr(word, target) != NULL);
                break;
            case 3:  // 前缀
                match = (strncmp(word, target, target_len) == 0);
                break;
            case 4:  // 后缀
                match = (word_len >= target_len) && 
                       (strcmp(word + word_len - target_len, target) == 0);
                break;
            default:
                fprintf(stderr, "无效的搜索模式: %d\n", mode);
                return;
        }
        
        if (!match) continue;
        
        // 高亮显示匹配部分
        printf("%s匹配项 #%d:%s\n", BOLD, i+1, RESET);
        
        // 处理第一列
        if (col1 > 0 && col1 <= 3) {
            const char *content = entry[col1-1];
            if (mode == 2 || mode == 3 || mode == 4) {
                // 高亮显示匹配部分
                const char *pos = strstr(content, target);
                if (pos) {
                    printf("%.*s%s%s%s%s", 
                          (int)(pos - content), content,
                          BOLD, YELLOW, target, RESET);
                    printf("%s\n", pos + target_len);
                } else {
                    printf("%-20s\n", content);
                }
            } else {
                printf("%-20s\n", content);
            }
        }
        
        // 处理第二列
        if (col2 > 0 && col2 <= 3) {
            printf("%-20s", entry[col2-1]);
        }
        
        // 处理第三列
        if (col3 > 0 && col3 <= 3) {
            printf("%-20s", entry[col3-1]);
        }
        
        printf("\n");
    }
    printf("=== 显示结束 ===\n\n");
}

// 辅助函数：按列显示内容（不带高亮）
void show_columns(const char *columns[3], int col1, int col2, int col3) {
    if (col1 > 0 && col1 <= 3) printf("%-20s", columns[col1-1]);
    if (col2 > 0 && col2 <= 3) printf("%-20s", columns[col2-1]);
    if (col3 > 0 && col3 <= 3) printf("%-20s", columns[col3-1]);
    printf("\n");
}