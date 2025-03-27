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
        snprintf(buf, sizeof(buf), "第 2 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  2.%d  %s", num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    2.1.%d  %s", num, title); \
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

    // 第二章内容
    CHAPTER("晴空大气的物理及电磁特性", 12);
    SUB_SECTION_1(1, "大气组成及其物理特性", 12);
    SUB_SECTION_2(1, "大气组成", 12);
    SUB_SECTION_2(2, "物理特性及其时空分布", 14);
    SUB_SECTION_2(2, "温度及其时空分布", 14);
    SUB_SECTION_2(2, "大气压强及其时空分布", 19);
    SUB_SECTION_2(2, "大气湿度及其时空分布", 22);
    SUB_SECTION_1(2, "晴空大气电磁特性参数及时空分布", 36);
    SUB_SECTION_2(1, "大气电磁特性参数", 37);
    SUB_SECTION_2(2, "大气折射指数时空分布", 43);
    SUB_SECTION_2(3, "大气折射指数的测量", 54);
    SUB_SECTION_1(3, "大气湍流", 55);
    SUB_SECTION_2(1, "大气湍流的形成机理", 56);
    SUB_SECTION_2(2, "大气湍流的基本特征及研究理论", 57);
    SUB_SECTION_2(3, "大气湍流电磁参数起伏的结构函数和空间谱", 59);
    SUB_SECTION_1(4, "大气波导", 63);
    SUB_SECTION_2(1, "大气波导的形成机理及分类", 63);
    SUB_SECTION_2(2, "大气波导的特征参数", 65);
    SUB_SECTION_2(3, "大气波导时空分布统计规律", 67);
    SUB_SECTION_2(4, "大气波导的诊断和预报", 74);
    SUB_SECTION_1(5, "对流层人工变态简介", 76);
    SUB_SECTION_2(1, "对流层人工变态技术现状", 76);
    SUB_SECTION_2(2, "相干声波扰动对流层及其应用机理", 77);
    SUB_SECTION_2(3, "相干声波扰动大气折射指数理论", 79);
    SUB_SECTION_2(4, "定性验证人工不均匀体的可行性", 81);
    EXERCISE_REF("思考和训练2", 87);
    EXERCISE_REF("本章参考文献", 88);

    return 0;
}