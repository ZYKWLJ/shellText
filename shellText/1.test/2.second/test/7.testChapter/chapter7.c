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

#define RIGHT_ALIGN_POS 65 // 右侧页码对齐的位置

// 定义章节宏
#define CHAPTER(title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "第 7 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  7.%d  %s", num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    7.1.%d  %s", num, title); \
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

    // 第七章内容
    CHAPTER("对流层大气中的光传输特性简介", 353);
    SUB_SECTION_1(1, "对流层大气对光的衰减", 353);
    SUB_SECTION_2(1, "气体分子的吸收衰减", 353);
    SUB_SECTION_2(2, "气体分子的散射衰减", 356);
    SUB_SECTION_2(3, "沉降粒子的衰减", 357);
    SUB_SECTION_2(4, "对流层大气中光衰减实用模型", 357);
    SUB_SECTION_1(2, "晴空分层大气对光的折射", 359);
    SUB_SECTION_1(3, "大气湍流中的光传输理论", 360);
    SUB_SECTION_2(1, "弱湍流中的光传输理论", 360);
    SUB_SECTION_2(2, "强湍流中的光传输理论", 362);
    SUB_SECTION_1(4, "对流层大气对光的去极化(偏振)效应", 366);
    SUB_SECTION_1(5, "对流层中光的其他传输特性", 367);
    EXERCISE_REF("思考和训练7", 367);
    EXERCISE_REF("本章参考文献", 368);

    return 0;
}