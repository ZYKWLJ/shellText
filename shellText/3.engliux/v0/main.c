#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义颜色宏（这里只是占位，可根据需要修改）
#define GREEN "\033[32m"  // 绿色专用于请输入指令提示信息
#define RED "\033[31m"    // 红色专用于错误提示信息
#define BLUE "\033[34m"   // 蓝色专用于章节名
#define PURPLE "\033[35m" // 紫色专用于指引信息
#define YELLOW "\033[33m" // 黄色专用于各个指令执行前缀！
#define RESET "\033[0m"
#define BOLD "\033[1m" // 加粗

// 定义单词集合
const char *a_4[] = {
    "a",
    "an",
    "and",
    NULL
};

const char *b_4[] = {
    "bin",
    "bing",
    "bound",
    NULL
};

const char **words_4[27] = {
    a_4,
    b_4,
    NULL
};

// 库文件定义
const char ***library[] = {
    NULL, // 代替 "NO"
    NULL, // 代替 "NO"
    NULL, // 代替 "NO"
    NULL, // 代替 "NO"
    words_4,
    NULL, // 代替 "NO"
    NULL  // 结束标记
};

// 辅助函数：统计符合条件的单词数量
int count_matching_words(const char **word_list, char *str, int (*matcher)(const char *, char *)) {
    int count = 0;
    for (int i = 0; word_list[i] != NULL; i++) {
        if (matcher(word_list[i], str)) {
            count++;
        }
    }
    return count;
}

// 辅助函数：将符合条件的单词存入数组
char **store_matching_words(const char **word_list, char **result, char *str, int (*matcher)(const char *, char *)) {
    int res_index = 0;
    for (int i = 0; word_list[i] != NULL; i++) {
        if (matcher(word_list[i], str)) {
            size_t len = strlen(word_list[i]) + 50;
            result[res_index] = (char *)malloc(len * sizeof(char));
            snprintf(result[res_index], len, "Library %d, Set %d: %s", 1, 1, word_list[i]);  // 这里的库和集合编号先简单设为1，可根据实际调整
            res_index++;
        }
    }
    result[res_index] = NULL; // 数组末尾添加 NULL 指针
    return result;
}

// 匹配函数：精确匹配
int exact_match(const char *word, char *str) {
    return strcmp(word, str) == 0;
}

// 匹配函数：前缀匹配
int prefix_match(const char *word, char *str) {
    return strncmp(word, str, strlen(str)) == 0;
}

// 匹配函数：后缀匹配
int suffix_match(const char *word, char *str) {
    int suffix_len = strlen(str);
    int word_len = strlen(word);
    return word_len >= suffix_len && strcmp(word + word_len - suffix_len, str) == 0;
}

// 匹配函数：包含匹配
int contains_match(const char *word, char *str) {
    return strstr(word, str) != NULL;
}

// 查找并高亮显示匹配的单词
int find_and_highlight(char **s, int s_size, char *t);

// 确保search_word函数只在一个文件中定义，如果lib.c中也有定义，需要删除或注释掉
char **search_word(char *str, int library_index, int mode) {
    char **result = NULL;
    int result_index = 0;
    int count = 0;

    int (*matcher)(const char *, char *);
    switch (mode) {
        case 0:
            matcher = exact_match;
            break;
        case 1:
            matcher = prefix_match;
            break;
        case 2:
            matcher = suffix_match;
            break;
        case 3:
            matcher = contains_match;
            break;
        default:
            return NULL;
    }

    if (library_index == 0) {
        for (int lib_index = 0; library[lib_index] != NULL; lib_index++) {
            for (int set_index = 0; library[lib_index][set_index] != NULL; set_index++) {
                const char **word_list = library[lib_index][set_index];
                count = count_matching_words(word_list, str, matcher);
                if (count > 0) {
                    if (result == NULL) {
                        result = (char **)malloc((count + 1) * sizeof(char *));
                        if (result == NULL) {
                            perror("Memory allocation failed");
                            return NULL;
                        }
                    }
                    result = store_matching_words(word_list, result, str, matcher);
                }
            }
        }
    } else if (library_index > 0 && library[library_index - 1] != NULL) {
        for (int set_index = 0; library[library_index - 1][set_index] != NULL; set_index++) {
            const char **word_list = library[library_index - 1][set_index];
            count = count_matching_words(word_list, str, matcher);
            if (count > 0) {
                if (result == NULL) {
                    result = (char **)malloc((count + 1) * sizeof(char *));
                    if (result == NULL) {
                        perror("Memory allocation failed");
                        return NULL;
                    }
                }
                result = store_matching_words(word_list, result, str, matcher);
            }
        }
    }

    if (result != NULL) {
        find_and_highlight(result, count, str);
    }

    return result;
}

// 查找并高亮显示匹配的单词
int find_and_highlight(char **s, int s_size, char *t) {
    int flag = 0;
    int first = 1;
    int count = 0;
    for (int i = 0; i < s_size; i++) {
        char *p = s[i];
        int found = 0;
        while (*p) {
            if (strncmp(p, t, strlen(t)) == 0) {
                found = 1;
                break;
            }
            p++;
        }
        if (found) {
            if (!first) {
                // putchar(',');
                // puts("");
            }
            p = s[i];
            while (*p) {
                if (strncmp(p, t, strlen(t)) == 0) {
                    printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                    p += strlen(t);
                    flag = 1;
                } else {
                    putchar(*p);
                    p++;
                }
            }
            first = 0;
            printf("\n\n");
        }
    }
    // printf("\n");
    return flag; // 判断是否找到！
}

int main() {
    // 测试精确匹配
    char *word = "a";
    char **result = search_word(word, 0, 0);
    if (result) {
        printf("Exact match results in all libraries for word '%s':\n", word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No exact match results found in all libraries for word '%s'\n", word);
    }

    // 测试前缀匹配
    word = "a";
    result = search_word(word, 0, 1);
    if (result) {
        printf("Prefix match results in all libraries for word '%s':\n", word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No prefix match results found in all libraries for word '%s'\n", word);
    }

    // 测试后缀匹配
    word = "d";
    result = search_word(word, 0, 2);
    if (result) {
        printf("Suffix match results in all libraries for word '%s':\n", word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No suffix match results found in all libraries for word '%s'\n", word);
    }

    // 测试包含匹配
    word = "an";
    result = search_word(word, 0, 3);
    if (result) {
        printf("Contain match results in all libraries for word '%s':\n", word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No contain match results found in all libraries for word '%s'\n", word);
    }

    return 0;
}