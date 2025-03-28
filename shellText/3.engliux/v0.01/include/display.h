#ifndef DISPLAY_H
#define DISPLAY_H
#include <string.h>

#include <stdio.h>
#include "color.h"
// 列宽定义
#define COL1_WIDTH 20
#define COL2_WIDTH 25
#define COL3_WIDTH 35

/**
 * @brief 显示指定列的内容
 * @param words 单词表二维数组
 * @param line 行号
 * @param first_show 第一列显示控制
 * @param second_show 第二列显示控制
 * @param third_show 第三列显示控制
 */
void show_contains_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);
void show_prefix_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);
void show_suffix_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);
void show_own_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);
#endif