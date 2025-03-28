#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 颜色和格式宏定义
#define BOLD "\033[1m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// 单词表定义
const char *a_4[][3] = {
    {"apple", "/ˈæpl/", "n. 苹果；苹果树；苹果公司"},
    {"application", "/ˌæplɪˈkeɪʃən/", "n. 应用；申请"},
    {NULL, NULL, NULL}
};

const char *a_6[][3] = {
    {"banana", "/bəˈnɑːnə/", "n. 香蕉"},
    {"back", "/bæk/", "n. 背部；后面"},
    {NULL, NULL, NULL}
};

// 字母表定义
const char **words_4[] = {
    (const char **)a_4,
    NULL
};

const char **words_6[] = {
    (const char **)a_6,
    NULL
};

// 总库定义
const char ***library[] = {
    NULL, NULL, NULL, NULL,  // 0-3
    words_4,                 // 4
    NULL,                    // 5
    words_6,                 // 6
    NULL                     // 结束标记
};

// 计算单个单词集的长度
int words_len(const char **word_set) {
    if (word_set == NULL) return 0;
    
    int len = 0;
    while (word_set[len] != NULL) {
        len++;
    }
    return len;
}

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
void find_and_highlight(const char **word_set, int set_size, const char *target, 
                       int mode, int col1, int col2, int col3) {
    for (int i = 0; i < set_size; i++) {
        const char (*entry)[3] = (const char (*)[3])word_set[i];
        if (!entry || !entry[0]) continue;
        
        // 匹配逻辑与find_if_exist相同
        int match = 0;
        /* ... */
        
        if (match) {
            // 根据显示选项输出
            if (col1 > 0 && col1 <= 3) printf("%-20s", entry[col1-1]);
            if (col2 > 0 && col2 <= 3) printf("%-20s", entry[col2-1]);
            if (col3 > 0 && col3 <= 3) printf("%-20s", entry[col3-1]);
            printf("\n");
        }
    }
}

// 搜索函数
int search_word(const char *target, int lib_index, int mode, 
               int col1, int col2, int col3) {
    if (!target || !*target) return 0;
    
    if (lib_index == 0) { // 搜索所有库
        int count = 0;
        for (int i = 4; i <= 6; i += 2) {
            if (library[i]) {
                const char ***lib = library[i];
                for (int j = 0; lib[j]; j++) {
                    const char **words = lib[j];
                    int len = words_len(words);
                    count += find_if_exist(words, len, target, mode);
                    find_and_highlight(words, len, target, mode, col1, col2, col3);
                }
            }
        }
        return count;
    } 
    else if (lib_index == 4 || lib_index == 6) {
        if (!library[lib_index]) return 0;
        
        int count = 0;
        const char ***lib = library[lib_index];
        for (int j = 0; lib[j]; j++) {
            const char **words = lib[j];
            int len = words_len(words);
            count += find_if_exist(words, len, target, mode);
            find_and_highlight(words, len, target, mode, col1, col2, col3);
        }
        return count;
    }
    return 0;
}

int main() {
    // 测试精确查找
    printf("=== 测试精确查找 ===\n");
    search_word("apple", 4, 1, 1, 2, 3);
    
    // 测试包含查找
    printf("\n=== 测试包含查找 ===\n");
    search_word("app", 0, 2, 1, 0, 3);
    
    // 测试前缀查找
    printf("\n=== 测试前缀查找 ===\n");
    search_word("ba", 6, 3, 1, 2, 0);
    
    // 测试后缀查找
    printf("\n=== 测试后缀查找 ===\n");
    search_word("ana", 0, 4, 1, 0, 0);
    
    return 0;
}