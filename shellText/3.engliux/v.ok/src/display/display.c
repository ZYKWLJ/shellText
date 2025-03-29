// #include "../../include/display.h"
// // #include "display.h"
// // #include "display.h"
// // #include "display.h"
// // #include "word.h"
// // 单独打印一列的函数
// void print_one_column(const char *words)
// {
//     printf("%-*s", COL1_WIDTH, words);
// }

// // 这是精确查询打印的单列显示函数！
// void show_exact_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     //  一个一个凑起来
//     // 本列不显示，打印空格
//     if (column_content == 0)
//     {
//         print_one_column("");
//     }
//     // 本列显示精确单词
//     else if (column_content == 1)
//     {
//         // 高亮显示匹配到的单词片段，并打印剩余部分，注意，这里统一左对齐40字符再打印
//     }
//     // 第一列音标！
//     else if (column_content == 2)
//     {
//         print_one_column(words_list[line].phonetic);
//     }
//     // 第一列显示释义！
//     else if (column_content == 3)
//     {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 打印精确指定查询的单词的三列内容
// void show_exact_columns(word_entry *words_list, int line, char *t,
//                         int first_show, int second_show, int third_show)
// {
//     show_exact_single_column(words_list, t, line, first_show);
//     show_exact_single_column(words_list, t, line, second_show);
//     show_exact_single_column(words_list, t, line, third_show);
//     printf("\n\n");
// }
// // 这是包含打印的单列显示函数！
// void show_contains_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     //  一个一个凑起来
//     // 本列不显示，打印空格
//     if (column_content == 0)
//     {
//         print_one_column("");
//     }

//     // 本列显示包含单词
//     else if (column_content == 1)
//     {
//         // 高亮显示匹配到的单词片段，并打印剩余部分，注意，这里统一左对齐40字符再打印
//     }
//     // 第一列音标！
//     else if (column_content == 2)
//     {
//         print_one_column(words_list[line].phonetic);
//     }
//     // 第一列显示释义！
//     else if (column_content == 3)
//     {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 打印包含指定查询的单词的三列内容
// void show_contains_columns(word_entry *words_list, int line, char *t,
//                            int first_show, int second_show, int third_show)
// {
//     show_contains_single_column(words_list, t, line, first_show);
//     show_contains_single_column(words_list, t, line, second_show);
//     show_contains_single_column(words_list, t, line, third_show);
//     printf("\n");
// }

// // 这是前缀查询打印的单列显示函数！
// void show_prefix_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     //  一个一个凑起来
//     // 本列不显示，打印空格
//     if (column_content == 0)
//     {
//         print_one_column("");
//     }
//     // 本列显示包含单词
//     else if (column_content == 1)
//     {
//         // 高亮显示匹配到的单词片段，并打印剩余部分，注意，这里统一左对齐40字符再打印
//     }
//     // 第一列音标！
//     else if (column_content == 2)
//     {
//         print_one_column(words_list[line].phonetic);
//     }
//     // 第一列显示释义！
//     else if (column_content == 3)
//     {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 打印前缀指定查询的单词的三列内容
// void show_prefix_columns(word_entry *words_list, int line, char *t,
//                          int first_show, int second_show, int third_show)
// {
//     show_prefix_single_column(words_list, t, line, first_show);
//     show_prefix_single_column(words_list, t, line, second_show);
//     show_prefix_single_column(words_list, t, line, third_show);
//     printf("\n");
// }

// // 这是后缀查询打印的单列显示函数！
// void show_suffix_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     //  一个一个凑起来
//     // 本列不显示，打印空格
//     if (column_content == 0)
//     {
//         print_one_column("");
//     }

//     // 本列显示包含单词
//     else if (column_content == 1)
//     {
//         // 高亮显示匹配到的单词片段，并打印剩余部分，注意，这里统一左对齐40字符再打印
//     }
//     // 第一列音标！
//     else if (column_content == 2)
//     {
//         print_one_column(words_list[line].phonetic);
//     }
//     // 第一列显示释义！
//     else if (column_content == 3)
//     {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 打印后缀指定查询的单词的三列内容
// void show_suffix_columns(word_entry *words_list, int line, char *t,
//                          int first_show, int second_show, int third_show)
// {
//     show_suffix_single_column(words_list, t, line, first_show);
//     show_suffix_single_column(words_list, t, line, second_show);
//     show_suffix_single_column(words_list, t, line, third_show);
//     printf("\n");
// }

// int main()
// {

//     print_one_column("hello");
//     print_one_column("hello");
//     print_one_column("hello");
//     printf("\n");
//     print_one_column("你好");
//     print_one_column("你好");
//     print_one_column("你好\n");
// }

// 请你实现我的左对齐打印需求和匹配字符高亮显示的功能，注意我的word_set定义如下：
// typedef struct
// {
//     const char *index;
//     const char *word;
//     const char *phonetic;
//     const char *meaning;
// } word_entry;








// #include "../../include/display.h"
// #include <string.h>
// #include <ctype.h>

// // #define COL1_WIDTH 40
// #define HIGHLIGHT_START "\033[1;33m"  // 黄色加粗
// #define HIGHLIGHT_END "\033[0m"       // 重置样式

// // 单独打印一列的函数（左对齐）
// void print_one_column(const char *words)
// {
//     printf("%-*s", COL1_WIDTH, words);
// }

// // 高亮显示匹配的单词部分
// void print_highlighted_word(const char *word, const char *match, int is_prefix, int is_suffix)
// {
//     const char *pos = NULL;
//     int match_len = strlen(match);
    
//     if (is_prefix) {
//         // 前缀匹配
//         if (strncasecmp(word, match, match_len) == 0) {
//             printf(HIGHLIGHT_START "%.*s" HIGHLIGHT_END "%s", 
//                    match_len, word, word + match_len);
//             return;
//         }
//     } 
//     else if (is_suffix) {
//         // 后缀匹配
//         int word_len = strlen(word);
//         if (word_len >= match_len && 
//             strncasecmp(word + word_len - match_len, match, match_len) == 0) {
//             printf("%.*s" HIGHLIGHT_START "%s" HIGHLIGHT_END,
//                    word_len - match_len, word, word + word_len - match_len);
//             return;
//         }
//     } 
//     else {
//         // 精确匹配或包含匹配
//         pos = strcasestr(word, match);
//         if (pos) {
//             printf("%.*s" HIGHLIGHT_START "%.*s" HIGHLIGHT_END "%s",
//                    (int)(pos - word), word, 
//                    match_len, pos, 
//                    pos + match_len);
//             return;
//         }
//     }
    
//     // 没有匹配则正常打印
//     printf("%s", word);
// }

// // 精确查询打印的单列显示函数
// void show_exact_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     if (column_content == 0) {
//         print_one_column("");
//     }
//     else if (column_content == 1) {
//         printf("%-*s", COL1_WIDTH, "");
//         print_highlighted_word(words_list[line].word, t, 0, 0);
//     }
//     else if (column_content == 2) {
//         print_one_column(words_list[line].phonetic);
//     }
//     else if (column_content == 3) {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 包含查询打印的单列显示函数
// void show_contains_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     if (column_content == 0) {
//         print_one_column("");
//     }
//     else if (column_content == 1) {
//         printf("%-*s", COL1_WIDTH, "");
//         print_highlighted_word(words_list[line].word, t, 0, 0);
//     }
//     else if (column_content == 2) {
//         print_one_column(words_list[line].phonetic);
//     }
//     else if (column_content == 3) {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 前缀查询打印的单列显示函数
// void show_prefix_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     if (column_content == 0) {
//         print_one_column("");
//     }
//     else if (column_content == 1) {
//         printf("%-*s", COL1_WIDTH, "");
//         print_highlighted_word(words_list[line].word, t, 1, 0);
//     }
//     else if (column_content == 2) {
//         print_one_column(words_list[line].phonetic);
//     }
//     else if (column_content == 3) {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 后缀查询打印的单列显示函数
// void show_suffix_single_column(word_entry *words_list, const char *t, int line, int column_content)
// {
//     if (column_content == 0) {
//         print_one_column("");
//     }
//     else if (column_content == 1) {
//         printf("%-*s", COL1_WIDTH, "");
//         print_highlighted_word(words_list[line].word, t, 0, 1);
//     }
//     else if (column_content == 2) {
//         print_one_column(words_list[line].phonetic);
//     }
//     else if (column_content == 3) {
//         print_one_column(words_list[line].meaning);
//     }
// }

// // 打印精确查询的三列内容
// void show_exact_columns(word_entry *words_list, int line, char *t,
//                         int first_show, int second_show, int third_show)
// {
//     show_exact_single_column(words_list, t, line, first_show);
//     show_exact_single_column(words_list, t, line, second_show);
//     show_exact_single_column(words_list, t, line, third_show);
//     printf("\n\n");
// }

// // 打印包含查询的三列内容
// void show_contains_columns(word_entry *words_list, int line, char *t,
//                            int first_show, int second_show, int third_show)
// {
//     show_contains_single_column(words_list, t, line, first_show);
//     show_contains_single_column(words_list, t, line, second_show);
//     show_contains_single_column(words_list, t, line, third_show);
//     printf("\n");
// }

// // 打印前缀查询的三列内容
// void show_prefix_columns(word_entry *words_list, int line, char *t,
//                          int first_show, int second_show, int third_show)
// {
//     show_prefix_single_column(words_list, t, line, first_show);
//     show_prefix_single_column(words_list, t, line, second_show);
//     show_prefix_single_column(words_list, t, line, third_show);
//     printf("\n");
// }

// // 打印后缀查询的三列内容
// void show_suffix_columns(word_entry *words_list, int line, char *t,
//                          int first_show, int second_show, int third_show)
// {
//     show_suffix_single_column(words_list, t, line, first_show);
//     show_suffix_single_column(words_list, t, line, second_show);
//     show_suffix_single_column(words_list, t, line, third_show);
//     printf("\n");
// }


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

