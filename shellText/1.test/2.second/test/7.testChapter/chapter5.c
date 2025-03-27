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
        snprintf(buf, sizeof(buf), "第 5 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  5.%d  %s", num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    5.1.%d  %s", num, title); \
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

    // 第五章内容
    CHAPTER("晴空大气中的传播与散射", 206);
    SUB_SECTION_1(1, "大气吸收", 206);
    SUB_SECTION_2(1, "大气吸收衰减率", 208);
    SUB_SECTION_2(2, "大气吸收衰减", 208);
    SUB_SECTION_1(2, "大气折射", 211);
    SUB_SECTION_2(1, "几何光学原理", 212);
    SUB_SECTION_2(2, "射线方程", 212);
    SUB_SECTION_2(3, "球面层大气中的大气折射效应", 213);
    SUB_SECTION_2(4, "大气折射的类型", 215);
    SUB_SECTION_2(5, "大气三维折射效应", 216);
    SUB_SECTION_2(6, "大气折射指数边界反射", 218);
    SUB_SECTION_1(3, "大气湍流与电磁波相互作用", 220);
    SUB_SECTION_2(1, "概述", 220);
    SUB_SECTION_2(2, "大气湍流散射传播理论", 221);
    SUB_SECTION_2(3, "晴空环境非视距传播的其他机理", 223);
    SUB_SECTION_2(4, "大气湍流的视距传播理论", 226);
    SUB_SECTION_1(4, "大气波导传输特性", 229);
    SUB_SECTION_2(1, "蒸发导环境中的射线描迹", 230);
    SUB_SECTION_2(2, "时延特性及距离误差", 233);
    SUB_SECTION_2(3, "覆盖盲区及覆盖范围", 234);
    SUB_SECTION_2(4, "传输损耗", 235);
    SUB_SECTION_2(5, "大气波导传输损耗工程模型", 241);
    SUB_SECTION_1(5, "晴空大气中的去极化效应", 242);
    SUB_SECTION_2(1, "去极化效应中的基本概念", 242);
    SUB_SECTION_2(2, "晴空大气去极化的计算理论", 243);
    SUB_SECTION_2(3, "晴空大气去极化效应统计预测模型", 245);
    SUB_SECTION_2(4, "晴空大气环境产生去极化效应的其他机理", 246);
    SUB_SECTION_2(5, "非理想双极化天线对去极化效应的影响", 248);
    SUB_SECTION_1(6, "晴空大气噪声", 248);
    SUB_SECTION_1(7, "晴空大气幅度闪烁统计特性", 250);
    SUB_SECTION_1(8, "晴空大气环境的其他传输特性", 251);
    EXERCISE_REF("思考和训练5", 253);
    EXERCISE_REF("本章参考文献", 253);

    return 0;
}