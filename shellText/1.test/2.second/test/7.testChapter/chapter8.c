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
        snprintf(buf, sizeof(buf), "第 8 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  8.%d  %s", num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(parent_num, num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    8.%d.%d  %s", parent_num, num, title); \
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

    // 第八章内容
    CHAPTER("对流层环境对无线系统的影响", 369);
    SUB_SECTION_1(1, "对流层环境媒质信道响应系数", 369);
    SUB_SECTION_1(2, "\"凭借\"与\"限制\"效应及其应用与对抗", 375);
    SUB_SECTION_2(2, 1, "折射的\"凭借\"与\"限制\"效应及其应用与对抗", 375);
    SUB_SECTION_2(2, 1, "折射现象的\"凭借\"效应及其应用", 376);
    SUB_SECTION_2(2, 1, "折射现象的\"限制\"效应及其对抗", 377);
    SUB_SECTION_2(2, 2, "散射和反射的\"凭借\"与\"限制\"效应及其应用与对抗", 380);
    SUB_SECTION_2(2, 2, "散射和反射现象的\"凭借\"效应及其应用", 380);
    SUB_SECTION_2(2, 2, "散射和反射现象的\"限制\"效应及其对抗", 382);
    SUB_SECTION_2(2, 3, "衰减的\"凭借\"与\"限制\"效应及其应用与对抗", 384);
    SUB_SECTION_2(2, 3, "衰减现象的\"凭借\"效应及其应用", 384);
    SUB_SECTION_2(2, 3, "衰减现象的\"限制\"效应及其对抗", 385);
    SUB_SECTION_2(2, 4, "去极化的\"凭借\"与\"限制\"效应及其应用与对抗", 387);
    SUB_SECTION_2(2, 4, "去极化现象的\"凭借\"效应及其应用", 387);
    SUB_SECTION_2(2, 4, "去极化现象的\"限制\"效应及其对抗", 387);
    SUB_SECTION_2(2, 5, "附加噪声的\"凭借\"与\"限制\"效应及其应用与对抗", 390);
    SUB_SECTION_2(2, 5, "附加噪声的\"凭借\"效应及其应用", 390);
    SUB_SECTION_2(2, 5, "附加噪声的\"限制\"效应及其对抗", 390);
    SUB_SECTION_2(2, 6, "其他传输效应的\"凭借\"与\"限制\"效应及其应用与对抗", 390);
    SUB_SECTION_1(3, "散射衰落效应的应用实例——毫米波星 - 地MIMO通信技术......", 391);
    SUB_SECTION_2(3, 1, "毫米波星 - 地MIMO通信技术简介", 391);
    SUB_SECTION_2(3, 2, "星 - 地毫米波MIMO通信系统设置需要考虑的新问题", 392);
    SUB_SECTION_2(3, 2, "散射互耦", 393);
    SUB_SECTION_2(3, 2, "MIMO信道空间去相关技术", 403);
    SUB_SECTION_1(4, "基于晴空大气人工变态技术的应用设想", 404);
    SUB_SECTION_2(3, 1, "散射超视距通信及辐射源被动定位", 405);
    SUB_SECTION_2(3, 2, "蒸发波导超视距雷达隐身", 409);
    SUB_SECTION_2(3, 3, "光电干涉成像雷达的干扰对抗", 411);
    SUB_SECTION_2(3, 4, "其他方面的应用设想", 412);
    EXERCISE_REF("思考和训练8", 414);
    EXERCISE_REF("本章参考文献", 414);

    return 0;
}    