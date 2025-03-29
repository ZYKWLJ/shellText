/* display.c - 最终修正版 */
#include "../../include/display.h"
#include <string.h>
#include <ctype.h>

#define COL1_WIDTH 40
#define WORD_WIDTH 20
#define HIGHLIGHT_START "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"

/* 高亮显示核心函数 */
void print_highlighted_word(const char *word, const char *match, int is_prefix, int is_suffix) {
    const char *pos = NULL;
    int match_len = strlen(match);
    
    if (is_prefix) {
        if (strncasecmp(word, match, match_len) == 0) {
            printf(HIGHLIGHT_START "%.*s" HIGHLIGHT_END "%s", 
                  match_len, word, word + match_len);
            return;
        }
    } 
    else if (is_suffix) {
        int word_len = strlen(word);
        if (word_len >= match_len && 
            strncasecmp(word + word_len - match_len, match, match_len) == 0) {
            printf("%.*s" HIGHLIGHT_START "%s" HIGHLIGHT_END,
                  word_len - match_len, word, word + word_len - match_len);
            return;
        }
    } 
    else {
        pos = strcasestr(word, match);
        if (pos) {
            printf("%.*s" HIGHLIGHT_START "%.*s" HIGHLIGHT_END "%s",
                  (int)(pos - word), word, 
                  match_len, pos, 
                  pos + match_len);
            return;
        }
    }
    printf("%s", word);
}

/* 显示辅助函数 */
void print_word_with_phonetic(word_entry *entry, const char *match, 
                             int is_prefix, int is_suffix) {
    printf("%-*s", WORD_WIDTH, ""); // 单词占位宽度
    print_highlighted_word(entry->word, match, is_prefix, is_suffix);
    printf(" %-*s", (int)(COL1_WIDTH - WORD_WIDTH - 1), entry->phonetic);
}

/* 四种匹配模式的单列显示 */
void show_exact_single_column(word_entry *words_list, const char *t, int line, int column_content) {
    if (column_content == 0) {
        print_one_column("");
    }
    else if (column_content == 1) {
        print_word_with_phonetic(&words_list[line], t, 0, 0);
    }
    else if (column_content == 2) {
        print_one_column(words_list[line].phonetic);
    }
    else if (column_content == 3) {
        print_one_column(words_list[line].meaning);
    }
}

void show_contains_single_column(word_entry *words_list, const char *t, int line, int column_content) {
    show_exact_single_column(words_list, t, line, column_content); // 复用相同逻辑
}

void show_prefix_single_column(word_entry *words_list, const char *t, int line, int column_content) {
    if (column_content == 1) {
        print_word_with_phonetic(&words_list[line], t, 1, 0);
    } else {
        show_exact_single_column(words_list, t, line, column_content);
    }
}

void show_suffix_single_column(word_entry *words_list, const char *t, int line, int column_content) {
    if (column_content == 1) {
        print_word_with_phonetic(&words_list[line], t, 0, 1);
    } else {
        show_exact_single_column(words_list, t, line, column_content);
    }
}

/* 四列显示函数（保持原样） */
void show_exact_columns(word_entry *words_list, int line, char *t,
                       int first_show, int second_show, int third_show) {
    show_exact_single_column(words_list, t, line, first_show);
    show_exact_single_column(words_list, t, line, second_show);
    show_exact_single_column(words_list, t, line, third_show);
    printf("\n\n");
}

void show_contains_columns(word_entry *words_list, int line, char *t,
                          int first_show, int second_show, int third_show) {
    show_contains_single_column(words_list, t, line, first_show);
    show_contains_single_column(words_list, t, line, second_show);
    show_contains_single_column(words_list, t, line, third_show);
    printf("\n");
}

void show_prefix_columns(word_entry *words_list, int line, char *t,
                        int first_show, int second_show, int third_show) {
    show_prefix_single_column(words_list, t, line, first_show);
    show_prefix_single_column(words_list, t, line, second_show);
    show_prefix_single_column(words_list, t, line, third_show);
    printf("\n");
}

void show_suffix_columns(word_entry *words_list, int line, char *t,
                        int first_show, int second_show, int third_show) {
    show_suffix_single_column(words_list, t, line, first_show);
    show_suffix_single_column(words_list, t, line, second_show);
    show_suffix_single_column(words_list, t, line, third_show);
    printf("\n");
}