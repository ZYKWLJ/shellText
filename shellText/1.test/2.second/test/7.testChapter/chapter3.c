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
        snprintf(buf, sizeof(buf), "第 3 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  3.%d  %s", num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    3.2.%d  %s", num, title); \
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

    // 第三章内容
    CHAPTER("大气沉降粒子物理及电磁特性", 91);
    SUB_SECTION_1(1, "大气沉降粒子概述", 91);
    SUB_SECTION_1(2, "大气水凝物", 92);
    SUB_SECTION_2(1, "雨", 92);
    SUB_SECTION_2(1, "降雨的形成和分类", 92);
    SUB_SECTION_2(1, "降雨强度", 94);
    SUB_SECTION_2(1, "雨滴的形状和尺寸", 94);
    SUB_SECTION_2(1, "雨滴尺寸分布", 96);
    SUB_SECTION_2(1, "雨滴沉降速度", 106);
    SUB_SECTION_2(1, "雨滴的最大直径与降雨率的关系", 109);
    SUB_SECTION_2(1, "雨滴倾角(雨滴沉降过程中的姿态)", 109);
    SUB_SECTION_2(1, "雨顶高度", 111);
    SUB_SECTION_2(1, "降雨率年时间概率分布统计特性", 115);
    SUB_SECTION_2(1, "不同累积时间降雨率转换", 120);
    SUB_SECTION_2(1, "最坏月及最坏年降雨率分布", 123);
    SUB_SECTION_2(1, "降雨率实时动态变化特性", 124);
    SUB_SECTION_2(1, "降雨率水平及垂直空间分布特性", 125);
    SUB_SECTION_2(2, "云、雾", 127);
    SUB_SECTION_2(2, "云、雾的形成及强度表征与分类", 128);
    SUB_SECTION_2(2, "云雾滴的形状和尺寸", 129);
    SUB_SECTION_2(2, "云雾能见度、含水量及相互关系", 130);
    SUB_SECTION_2(2, "云雾的空间高度", 132);
    SUB_SECTION_2(2, "云雾滴谱分布", 134);
    SUB_SECTION_2(2, "云雾及含水量时空统计分布", 137);
    SUB_SECTION_2(3, "冰晶、雪、冰雹", 156);
    SUB_SECTION_2(3, "冰晶", 156);
    SUB_SECTION_2(3, "雪", 159);
    SUB_SECTION_2(3, "冰雹", 163);
    SUB_SECTION_1(3, "沙尘", 165);
    SUB_SECTION_2(1, "沙尘暴的粒子形状、尺寸、取向、强度等级及化学成分", 166);
    SUB_SECTION_2(2, "沙尘暴的浓度", 167);
    SUB_SECTION_2(3, "沙尘粒子尺寸分布", 167);
    SUB_SECTION_2(4, "沙尘暴的时空分布", 168);
    SUB_SECTION_2(5, "沙尘暴垂直空间分布特性", 169);
    SUB_SECTION_1(4, "其他气溶胶沉降粒子", 170);
    SUB_SECTION_2(1, "概述", 170);
    SUB_SECTION_2(2, "气溶胶颗粒形状、尺寸和颗粒密度", 171);
    SUB_SECTION_2(3, "气溶胶浓度或者含量", 171);
    SUB_SECTION_2(4, "气溶胶粒子的尺寸分布", 175);
    SUB_SECTION_1(5, "沉降粒子介电特性", 176);
    SUB_SECTION_2(1, "水凝物粒子介电特性", 177);
    SUB_SECTION_2(1, "水 的介电特性", 177);
    SUB_SECTION_2(1, "冰的介电特性", 181);
    SUB_SECTION_2(1, "雪的介电特性", 182);
    SUB_SECTION_2(2, "沙尘及其他型气溶胶介电特性", 185);
    SUB_SECTION_2(3, "介电特性模型适用性分析", 185);
    SUB_SECTION_2(4, "混合物质等效介电特性", 188);
    SUB_SECTION_1(6, "对流层环境物理、电磁特性的测量", 190);
    SUB_SECTION_2(1, "晴空大气环境物理特性测量", 191);
    SUB_SECTION_2(2, "大气沉降粒子物理特性测量", 192);
    SUB_SECTION_2(3, "介电常数测量", 194);
    SUB_SECTION_2(4, "对流层环境物理及电磁特性研究超势", 195);
    EXERCISE_REF("思考和训练3", 196);
    EXERCISE_REF("本章参考文献", 197);

    return 0;
}