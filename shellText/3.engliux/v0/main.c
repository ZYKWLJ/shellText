#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义颜色宏（这里只是占位，可根据需要修改）
#define GREEN "\033[32m"//绿色专用于请输入指令提示信息
#define RED "\033[31m"//红色专用于错误提示信息
#define BLUE "\033[34m"//蓝色专用于章节名
#define PURPLE "\033[35m"//紫色专用于指引信息
#define YELLOW "\033[33m"//黄色专用于各个指令执行前缀！
#define RESET "\033[0m"
#define BOLD "\033[1m"//加粗

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
    NULL,   // 代替 "NO"
    NULL,   // 代替 "NO"
    NULL,   // 代替 "NO"
    NULL,   // 代替 "NO"
    words_4,
    NULL,   // 代替 "NO"
    NULL    // 结束标记
};

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
        if (lib_set[i] != NULL && strcmp(lib_set[i], "NO") != 0 && strcmp(lib_set[i], "NULL") != 0) {
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

// 查找并高亮显示匹配的单词
int find_and_highlight(char **s, int s_size, char *t);

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

// 查找并高亮显示匹配的单词
int find_and_highlight(char **s, int s_size, char *t)
{
    int flag = 0;
    int first = 1;
    int count = 0;
    for (int i = 0; i < s_size; i++)
    {
        char *p = s[i];
        int found = 0;
        while (*p)
        {
            if (strncmp(p, t, strlen(t)) == 0)
            {
                found = 1;
                break;
            }
            p++;
        }
        if (found)
        {
            if (!first)
            {
                // putchar(',');
                // puts("");
            }
            p = s[i];
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
            first = 0;
            printf("\n\n");
        }
    }
    // printf("\n");
    return flag; // 判断是否找到！
}

int main() {
    // 测试搜索所有库中的单词
    char *word = "a";
    char **result = search_word(word, 0);
    if (result) {
        printf("Search results in all libraries for word '%s':\n", word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No results found in all libraries for word '%s'\n", word);
    }

    // 测试搜索特定库中的单词
    int libraryIndex = 1;
    result = search_word(word, libraryIndex);
    if (result) {
        printf("\nSearch results in library %d for word '%s':\n", libraryIndex, word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No results found in library %d for word '%s'\n", libraryIndex, word);
    }

    return 0;
}    