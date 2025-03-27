#include "../../include/chapters/common.h"
// 计算字符串的显示宽度（中文算2，英文算1）
int calc_display_width(const char *str) {
    int width = 0;
    while (*str) {
        if ((unsigned char)*str >= 0x80) { // 中文字符
            width += 2;
            str += 3; // UTF-8 中文字符占3字节（假设是UTF-8编码）
        } else { // 英文字符
            width += 1;
            str += 1;
        }
    }
    return width;
}

// 打印填充点，使总宽度达到 target_width
void print_dots(const char *text, int target_width) {
    int text_width = calc_display_width(text);
    int dots_needed = target_width - text_width;
    for (int i = 0; i < dots_needed; i++) {
        putchar('.');
    }
}