#ifndef DISPLAY_H
#define DISPLAY_H
#include <string.h>

#include <stdio.h>
#include "color.h"
#include "words.h"
// 列宽定义
#define COL1_WIDTH 20
#define COL2_WIDTH 25
#define COL3_WIDTH 35

/**
 * @brief 显示指定列的内容
 * @param words 单词表
 * @param line 行号
 * @param first_show 第一列显示控制，0表示不显示，1表示显示单词，2表示显示音标，3表示显示释义
 * @param second_show 第二列显示控制，0表示不显示，1表示显示单词，2表示显示音标，3表示显示释义
 * @param third_show 第三列显示控制，0表示不显示，1表示显示单词，2表示显示音标，3表示显示释义
 * @注意：每一列之间左对齐40空格，匹配到的字串高亮显示
 */
void show_contains_columns(word_entry *words_list, int line, char *t, int first_show, int second_show, int third_show);
void show_prefix_columns(word_entry *words_list, int line, char *t, int first_show, int second_show, int third_show);
void show_suffix_columns(word_entry *words_list, int line, char *t, int first_show, int second_show, int third_show);
void show_exact_columns(word_entry *words_list, int line, char *t, int first_show, int second_show, int third_show);
#endif