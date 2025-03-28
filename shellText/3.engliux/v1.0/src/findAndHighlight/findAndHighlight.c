#include "../../include/findAndHighlight.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// KMP算法相关函数
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

int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(M * sizeof(int));
    if (!lps)
        return -1;

    computeLPSArray(pat, M, lps);

    int i = 0, j = 0, count = 0;
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
                j = lps[j - 1];
            else
                i++;
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
        const char(*entry)[3] = (const char(*)[3])word_set[i];
        
        // 严格验证数据结构
        if (!entry || !entry[0] || entry[1] == NULL || entry[2] == NULL) {
            continue; // 跳过不完整的条目
        }

        const char *word = entry[0]; // 只使用单词列进行匹配
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
        }
    }
    return count;
}
// 高亮显示函数

void find_and_highlight(const char **word_set, int set_size, const char *target,
                        int mode, int col1, int col2, int col3)
{
    for (int i = 0; i < set_size; i++)
    {
        printf("%s\t\t\t",word_set[i]);
    }

    printf("\n");
    for (int i = 0; i < set_size; i++) {
        const char(*entry)[3] = (const char(*)[3])word_set[i];
        
        // 严格验证数据结构
        if (!entry || !entry[0] || entry[1] == NULL || entry[2] == NULL) {
            continue; // 跳过不完整的条目
        }

        const char *word = entry[0]; // 只使用单词列进行匹配
        // const char *word = entry[0];
        const char *phonetic = entry[1];
        const char *meaning = entry[2];

        // 匹配判断
        int match = 0;
        size_t target_len = strlen(target);
        size_t word_len = strlen(word);

        switch (mode)
        {
        case 1:
            match = (strcmp(word, target) == 0);
            break;
        case 2:
            match = (strstr(word, target) != NULL);
            break;
        case 3: match = (strncmp(word, target, target_len) == 0); break;
            case 4: 
                match = (word_len >= target_len) && 
                       (strcmp(word + word_len - target_len, target) == 0);
                break;
            default:
                fprintf(stderr, "无效的搜索模式: %d\n", mode);
                return;
        }

        if (!match)
            continue;

        // 输出匹配项编号
        // printf("%s匹配项 #%d:%s ", BOLD, i + 1, RESET);

        // 动态计算列宽
        int word_width = 25;  // 单词列宽
        int phone_width = 20; // 音标列宽
        int mean_width = 50;  // 释义列宽

        // 处理第一列（单词）
        // 处理第一列（单词）
        if (col1 > 0 && col1 <= 3) {
            const char *content = entry[col1-1];
            if (content) {
                if (mode == 2 || mode == 3 || mode == 4) {
                    const char *pos = strstr(content, target);
                    if (pos) {
                        // 计算高亮部分前后的长度
                        int prefix_len = pos - content;
                        int suffix_len = strlen(pos + target_len);
                        
                        // 先打印高亮前的部分
                        printf("%.*s", prefix_len, content);
                        
                        // 打印高亮部分
                        printf("%s%s%s%s", BOLD, YELLOW, target, RESET);
                        
                        // 打印高亮后的部分
                        printf("%s", pos + target_len);
                        
                        // 补齐剩余宽度
                        int printed_len = prefix_len + target_len + suffix_len;
                        if (printed_len < word_width) {
                            printf("%*s", word_width - printed_len, "");
                        }
                    } else {
                        printf("%-*s", word_width, content);
                    }
                } else {
                    printf("%-*s", word_width, content);
                }
            } else {
                printf("%-*s", word_width, "");
            }
        }

        // 处理第二列（音标）
        if (col2 > 0 && col2 <= 3)
        {
            const char *content = entry[col2 - 1];
            printf("%-*s", phone_width, content ? content : "");
        }

        // 处理第三列（释义）
        if (col3 > 0 && col3 <= 3)
        {
            const char *content = entry[col3 - 1];
            printf("%-*s", mean_width, content ? content : "");
        }

        printf("\n");
    }
    printf("=== 显示结束 ===\n\n");
}
// 辅助函数：按列显示内容（不带高亮）
void show_columns(const char *columns[3], int col1, int col2, int col3)
{
    if (col1 > 0 && col1 <= 3)
        printf("%-20s", columns[col1 - 1]);
    if (col2 > 0 && col2 <= 3)
        printf("%-20s", columns[col2 - 1]);
    if (col3 > 0 && col3 <= 3)
        printf("%-20s", columns[col3 - 1]);
    printf("\n");
}