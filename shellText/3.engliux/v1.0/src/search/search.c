#include "../../include/search.h"

// // 查找特定单词
// char **search_word(char *str, int library)
// {
//     // 根据library的规则在指定库里面精确查询，并返回结果！
//     // 注意，查询的时候，用find_and_highlight(char **s, int s_size, char *t)这个函数。因为方便高亮
// }

// // 查找以特定前缀开头的单词，返回单词集合
// char **search_prefix(char *str, int library)
// {
//      // 根据library的规则在指定库里面前缀查询，并返回结果！
//     // 注意，查询的时候，用find_and_highlight(char **s, int s_size, char *t)这个函数。因为方便高亮
// }


// // 查找以特定后缀结尾的单词，返回单词集合
// char **search_suffix(char *str, int library)
// {
   
//      // 根据library的规则在指定库里面后缀查询，并返回结果！
//     // 注意，查询的时候，用find_and_highlight(char **s, int s_size, char *t)这个函数。因为方便高亮

// }

// // 查找包含特定字符串的单词，返回单词集合
// char **search_contains(char *str, int library)
// {
    
//      // 根据library的规则在指定库里面包含查询，并返回结果！
//     // 注意，查询的时候，用find_and_highlight(char **s, int s_size, char *t)这个函数。因为方便高亮

// }

// 查找特定单词
char **search_word(char *str, int library_index)
{
    printf("search_word.......\n");
    if (library_index < 0 || library[library_index] == NULL) {
        return NULL;
    }

    int result_count = 0;
    char **result = NULL;
    for (int i = 0; library[library_index][i] != NULL; i++) {
        for (int j = 0; library[library_index][i][j] != NULL; j++) {
            if (strcmp(library[library_index][i][j], str) == 0) {
                result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
                result[result_count] = strdup(library[library_index][i][j]);
                result_count++;
            }
        }
    }
    if (result_count > 0) {
        result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
        result[result_count] = NULL;
        find_and_highlight(result, result_count, str);
    }
    return result;
}

// 查找以特定前缀开头的单词，返回单词集合
char **search_prefix(char *str, int library_index)
{
    if (library_index < 0 || library[library_index] == NULL) {
        return NULL;
    }

    int result_count = 0;
    char **result = NULL;
    for (int i = 0; library[library_index][i] != NULL; i++) {
        for (int j = 0; library[library_index][i][j] != NULL; j++) {
            if (strncmp(library[library_index][i][j], str, strlen(str)) == 0) {
                result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
                result[result_count] = strdup(library[library_index][i][j]);
                result_count++;
            }
        }
    }
    if (result_count > 0) {
        result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
        result[result_count] = NULL;
        find_and_highlight(result, result_count, str);
    }
    return result;
}

// 查找以特定后缀结尾的单词，返回单词集合
char **search_suffix(char *str, int library_index)
{
    if (library_index < 0 || library[library_index] == NULL) {
        return NULL;
    }

    int result_count = 0;
    char **result = NULL;
    size_t suffix_len = strlen(str);
    for (int i = 0; library[library_index][i] != NULL; i++) {
        for (int j = 0; library[library_index][i][j] != NULL; j++) {
            size_t word_len = strlen(library[library_index][i][j]);
            if (word_len >= suffix_len && strcmp(library[library_index][i][j] + word_len - suffix_len, str) == 0) {
                result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
                result[result_count] = strdup(library[library_index][i][j]);
                result_count++;
            }
        }
    }
    if (result_count > 0) {
        result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
        result[result_count] = NULL;
        find_and_highlight(result, result_count, str);
    }
    return result;
}

// 查找包含特定字符串的单词，返回单词集合
char **search_contains(char *str, int library_index)
{
    if (library_index < 0 || library[library_index] == NULL) {
        return NULL;
    }

    int result_count = 0;
    char **result = NULL;
    for (int i = 0; library[library_index][i] != NULL; i++) {
        for (int j = 0; library[library_index][i][j] != NULL; j++) {
            if (strstr(library[library_index][i][j], str) != NULL) {
                result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
                result[result_count] = strdup(library[library_index][i][j]);
                result_count++;
            }
        }
    }
    if (result_count > 0) {
        result = (char **)realloc(result, (result_count + 1) * sizeof(char *));
        result[result_count] = NULL;
        find_and_highlight(result, result_count, str);
    }
    return result;
}    