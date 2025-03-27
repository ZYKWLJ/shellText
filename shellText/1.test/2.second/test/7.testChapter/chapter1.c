#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

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

#define RIGHT_ALIGN_POS 60 // 右侧页码对齐的位置

// 定义章节宏
#define CHAPTER(title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "第 1 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  %d.%d  %s", 1, num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    %d.%d.%d  %s", 1, 2, num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义思考训练和参考文献宏
#define EXERCISE_REF(title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "%s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

int main() {
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符
    CHAPTER("绪论", 1);
    SUB_SECTION_1(1, "概述", 1);
    SUB_SECTION_1(2, "对流层中的传输效应及其产生机理", 3);
    SUB_SECTION_2(1, "折射和反射", 3);
    SUB_SECTION_2(2, "散射", 3);
    SUB_SECTION_2(3, "吸收、衰减、相移", 4);
    SUB_SECTION_2(4, "去极化", 5);
    SUB_SECTION_2(5, "噪声、干扰", 6);
    SUB_SECTION_2(6, "其他", 6);
    SUB_SECTION_1(3, "对流层传播模式", 7);
    SUB_SECTION_2(1, "对流层视距传播", 7);
    SUB_SECTION_2(2, "对流层超视距传播", 7);
    SUB_SECTION_1(4, "对流层传输对无线系统的影响", 8);
    SUB_SECTION_1(5, "本书的总结构分布", 9);
    EXERCISE_REF("思考和训练1", 10);
    EXERCISE_REF("本章参考文献", 10);

    return 0;
}