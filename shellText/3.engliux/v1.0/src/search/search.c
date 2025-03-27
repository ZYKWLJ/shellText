#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/search.h"
// 假设 words 数组已经在其他地方定义
// extern const char **words[27];

// 查找特定单词
char **search_word(char *str) {
    int count = 0;
    // 先统计符合条件的单词数量
    for (int i = 0; i < 26; i++) {
        if (words[i] != NULL) {
            for (int j = 0; words[i][j] != NULL; j++) {
                if (strcmp(words[i][j], str) == 0) {
                    count++;
                }
            }
        }
    }

    // 动态分配数组来存储符合条件的单词
    char **result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    int index = 0;
    // 将符合条件的单词存入数组
    for (int i = 0; i < 26; i++) {
        if (words[i] != NULL) {
            for (int j = 0; words[i][j] != NULL; j++) {
                if (strcmp(words[i][j], str) == 0) {
                    result[index++] = (char *)words[i][j];
                }
            }
        }
    }
    result[index] = NULL; // 数组末尾添加 NULL 指针

    return result;
}

// 查找以特定前缀开头的单词，返回单词集合
char **search_prefix(char *str) {
    if (str[0] < 'a' || str[0] > 'z') {
        return NULL;
    }
    int index = str[0] - 'a';
    int count = 0;
    // 统计符合条件的单词数量
    if (words[index] != NULL) {
        for (int j = 0; words[index][j] != NULL; j++) {
            if (strstr(words[index][j], str) == words[index][j]) {
                count++;
            }
        }
    }

    // 动态分配数组来存储符合条件的单词
    char **result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    int res_index = 0;
    // 将符合条件的单词存入数组
    if (words[index] != NULL) {
        for (int j = 0; words[index][j] != NULL; j++) {
            if (strstr(words[index][j], str) == words[index][j]) {
                result[res_index++] = (char *)words[index][j];
            }
        }
    }
    result[res_index] = NULL; // 数组末尾添加 NULL 指针

    return result;
}

// 查找以特定后缀结尾的单词，返回单词集合
char **search_suffix(char *str) {
    int suffix_len = strlen(str);
    int count = 0;
    // 统计符合条件的单词数量
    for (int i = 0; i < 26; i++) {
        if (words[i] != NULL) {
            for (int j = 0; words[i][j] != NULL; j++) {
                int word_len = strlen(words[i][j]);
                if (word_len >= suffix_len && strcmp(words[i][j] + word_len - suffix_len, str) == 0) {
                    count++;
                }
            }
        }
    }

    // 动态分配数组来存储符合条件的单词
    char **result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    int res_index = 0;
    // 将符合条件的单词存入数组
    for (int i = 0; i < 26; i++) {
        if (words[i] != NULL) {
            for (int j = 0; words[i][j] != NULL; j++) {
                int word_len = strlen(words[i][j]);
                if (word_len >= suffix_len && strcmp(words[i][j] + word_len - suffix_len, str) == 0) {
                    result[res_index++] = (char *)words[i][j];
                }
            }
        }
    }
    result[res_index] = NULL; // 数组末尾添加 NULL 指针

    return result;
}

// 查找包含特定字符串的单词，返回单词集合
char **search_contains(char *str) {
    int count = 0;
    // 统计符合条件的单词数量
    for (int i = 0; i < 26; i++) {
        if (words[i] != NULL) {
            for (int j = 0; words[i][j] != NULL; j++) {
                if (strstr(words[i][j], str) != NULL) {
                    count++;
                }
            }
        }
    }

    // 动态分配数组来存储符合条件的单词
    char **result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    int res_index = 0;
    // 将符合条件的单词存入数组
    for (int i = 0; i < 26; i++) {
        if (words[i] != NULL) {
            for (int j = 0; words[i][j] != NULL; j++) {
                if (strstr(words[i][j], str) != NULL) {
                    result[res_index++] = (char *)words[i][j];
                }
            }
        }
    }
    result[res_index] = NULL; // 数组末尾添加 NULL 指针

    return result;
}
    