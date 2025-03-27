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
        snprintf(buf, sizeof(buf), "第 4 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  4.%d  %s", num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    4.1.%d  %s", num, title); \
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

    // 第四章内容
    CHAPTER("对流层顶及其气候特征", 201);
    SUB_SECTION_1(1, "对流层顶概述", 201);
    SUB_SECTION_2(1, "对流层顶的发现、确定方法及其成因", 201);
    SUB_SECTION_2(2, "对流层顶判据", 202);
    SUB_SECTION_2(3, "对流层顶在大气过程中的作用", 203);
    SUB_SECTION_1(2, "对流层顶观测资料气候学整理方法", 203);
    SUB_SECTION_1(3, "对流层顶的特征参数", 204);
    SUB_SECTION_1(4, "对流层顶气候其他问题", 204);
    EXERCISE_REF("思考和训练4", 205);
    EXERCISE_REF("本章参考文献", 205);

    return 0;
}