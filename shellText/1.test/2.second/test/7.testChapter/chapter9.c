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
        snprintf(buf, sizeof(buf), "第 9 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  9.%d  %s", num, title); \
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

    // 第九章内容
    CHAPTER("对流层中传输特性测量及模型分析", 421);
    SUB_SECTION_1(1, "晴空大气折射效应测量及折射率剖面建模", 422);
    SUB_SECTION_1(2, "晴空大气闪烁特性测量及模型修正", 422);
    SUB_SECTION_1(3, "降雨衰减测量技术及雨衰模型修正", 423);
    SUB_SECTION_1(4, "去极化特性测量技术及去极化计算模型修正", 424);
    SUB_SECTION_1(5, "其他传输特性的测量", 425);
    SUB_SECTION_1(6, "太赫兹波段电磁波传输特性测量及建模", 425);
    EXERCISE_REF("思考和训练9", 427);
    EXERCISE_REF("本章参考文献", 428);

    return 0;
}