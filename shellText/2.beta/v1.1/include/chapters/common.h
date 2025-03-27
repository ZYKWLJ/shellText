#ifndef CHAPTER_COMMON_H
#define CHAPTER_COMMON_H
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include "../color.h"
#define RIGHT_ALIGN_POS 65 // 右侧页码对齐的位置
// 计算字符串的显示宽度（中文算2，英文算1）
int calc_display_width(const char *str);

// 打印填充点，使总宽度达到 target_width
void print_dots(const char *text, int target_width);

#endif