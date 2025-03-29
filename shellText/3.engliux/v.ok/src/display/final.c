#include <stdio.h>
#include <string.h>
#define COL1_WIDTH 50
#define COL2_WIDTH 50
#define COL3_WIDTH 50
#define HIGHLIGHT_START "\033[31m" // ANSI 颜色代码（红色）
#define HIGHLIGHT_END "\033[0m"


// 定义 word_entry 结构体
typedef struct
{
    const char *index;
    const char *word;
    const char *phonetic;
    const char *meaning;
} word_entry;

// **打印对齐文本**
void print_aligned(const char *text, int width) {
    printf("%-*s", width, text);
}

// **高亮后缀**
void print_highlighted_suffix(const char *word, const char *suffix) {
    size_t word_len = strlen(word);
    size_t suffix_len = strlen(suffix);

    if (word_len >= suffix_len && strcmp(word + word_len - suffix_len, suffix) == 0) {
        printf("%.*s" HIGHLIGHT_START "%s" HIGHLIGHT_END, 
               (int)(word_len - suffix_len), word, suffix);
    } else {
        printf("%s", word);
    }
}

// **打印单词（含高亮）**
void print_highlighted_word(const char *word, const char *query, int exact_match) {
    if (exact_match) {
        printf(HIGHLIGHT_START "%s" HIGHLIGHT_END, word);
        return;
    }

    const char *pos = strstr(word, query);
    if (pos) {
        int prefix_len = pos - word;
        printf("%.*s" HIGHLIGHT_START "%s" HIGHLIGHT_END "%s",
               prefix_len, word, query, pos + strlen(query));
    } else {
        printf("%s", word);
    }
}

// **通用三列打印**
void print_columns(const char *word, const char *phonetic, const char *meaning, const char *query, int exact_match, int suffix_highlight) {
    if (suffix_highlight) {
        print_highlighted_suffix(word, query);
    } else {
        print_highlighted_word(word, query, exact_match);
    }
    printf("  ");  // 列间距
    print_aligned(phonetic, COL2_WIDTH);
    print_aligned(meaning, COL3_WIDTH);
    printf("\n");
}
// **通用三列打印**

// **精确匹配**
void show_exact_match(word_entry *words, const char *query, int line) {
    if (strcmp(words[line].word, query) == 0) {
        print_columns(words[line].word, words[line].phonetic, words[line].meaning, query, 1, 0);
    }
}

// **包含匹配**
void show_contains_match(word_entry *words, const char *query, int line) {
    if (strstr(words[line].word, query) != NULL) {
        print_columns(words[line].word, words[line].phonetic, words[line].meaning, query, 0, 0);
    }
}

// **前缀匹配**
void show_prefix_match(word_entry *words, const char *query, int line) {
    if (strncmp(words[line].word, query, strlen(query)) == 0) {
        print_columns(words[line].word, words[line].phonetic, words[line].meaning, query, 0, 0);
    }
}

// **后缀匹配**
void show_suffix_match(word_entry *words, const char *query, int line) {
    size_t word_len = strlen(words[line].word);
    size_t query_len = strlen(query);

    if (word_len >= query_len && strcmp(words[line].word + word_len - query_len, query) == 0) {
        print_columns(words[line].word, words[line].phonetic, words[line].meaning, query, 0, 1);
    }
}

// 测试代码
int main()
{
    //    #include "../../../include/words_lib/cet6/cet6_a.h"
    word_entry words[1000] = {
        {
            "1",
            "abandon",
            "/əˈbændən/",
            "v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热",
        },
        {
            "2",
            "ability",
            "/əˈbɪləti/",
            "n. 能力，能耐；才能",
        },
        
        {NULL, NULL, NULL, NULL},
    };

    printf("【精确查询】搜索 'an'\n");
    for (int i = 0; words[i].index; i++)
    {
         show_exact_match(words, "an", i);
    }

    printf("\n【包含查询】搜索 'an'\n");
    for (int i = 0; words[i].index; i++)
    {
        show_contains_match(words, "an", i);
    }

    printf("\n【前缀查询】搜索 'an'\n");
    for (int i = 0; words[i].index; i++)
    {
         show_prefix_match(words, "an", i);
    }

    printf("\n【后缀查询】搜索 'a'\n");
    for (int i = 0; words[i].index; i++)
    {
       show_suffix_match(words, "a", i);
    }

    return 0;
}
