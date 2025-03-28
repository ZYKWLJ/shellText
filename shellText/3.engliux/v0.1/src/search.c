#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/findAndHighlight.h"

// 假设这些数据结构在其他地方已经正确定义
extern const char ****library;

// 辅助函数，用于遍历单词集合查找匹配单词
void find_matching_words(const char **words, char *str, char ***result, int *result_index, int lib_index, int set_index) {
    for (int i = 0; words[i] != NULL; i++) {
        if (strcmp(words[i], str) == 0) {
            size_t len = strlen(str) + 50;
            (*result)[(*result_index)] = (char *)malloc(len * sizeof(char));
            snprintf((*result)[(*result_index)], len, "Library %d, Set %d: %s", lib_index, set_index, str);
            (*result_index)++;
        }
    }
}

// 修改search_library_set函数中调用find_matching_words的参数传递
void search_library_set(const char **lib_set, char *str, char ***result, int *result_index, int lib_index, int set_index) {
    for (int i = 0; lib_set[i] != NULL; i++) {
        if (strcmp(lib_set[i], "NO") != 0 && strcmp(lib_set[i], "NULL") != 0) {
            // 这里将lib_set[i]解引用，因为它当前是const char *类型，
            // 而find_matching_words期望的是const char **类型，
            // 我们需要传递一个指向单词数组的指针
            find_matching_words((const char **)lib_set[i], str, result, result_index, lib_index, set_index);
        }
    }
}

// 单独分离的函数，用于遍历所有库文件
void search_all_libraries(char *str, char ***result, int *result_index) {
    for (int lib_index = 0; library[lib_index] != NULL; lib_index++) {
        for (int set_index = 0; library[lib_index][set_index] != NULL; set_index++) {
            search_library_set(library[lib_index][set_index], str, result, result_index, lib_index + 1, set_index + 1);
        }
    }
}

// 确保search_word函数只在一个文件中定义，如果lib.c中也有定义，需要删除或注释掉
char** search_word(char* str, int library_index) {
    char **result = (char **)malloc(100 * sizeof(char *));
    int result_index = 0;

    if (library_index == 0) {
        search_all_libraries(str, &result, &result_index);
    } else if (library_index > 0 && library[library_index - 1] != NULL) {
        for (int set_index = 0; library[library_index - 1][set_index] != NULL; set_index++) {
            search_library_set(library[library_index - 1][set_index], str, &result, &result_index, library_index, set_index + 1);
        }
    }

    result[result_index] = NULL;
    find_and_highlight(result, result_index, str);

    return result;
}