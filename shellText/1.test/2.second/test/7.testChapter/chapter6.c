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
        snprintf(buf, sizeof(buf), "第 6 章  %s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  6.%d  %s", num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    6.1.%d  %s", num, title); \
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

    // 第六章内容
    CHAPTER("大气沉降粒子中的传播与散射", 255);
    SUB_SECTION_1(1, "大气沉降粒子中电磁波传播与散射的基本理论", 255);
    SUB_SECTION_2(1, "单个粒子对电磁波的散射和吸收", 255);
    SUB_SECTION_2(2, "沉降粒子环境中电磁波的传输问题分类", 259);
    SUB_SECTION_2(3, "沉降粒子环境中的衰减及相移理论", 260);
    SUB_SECTION_2(4, "沉降粒子环境中的去极化理论", 263);
    SUB_SECTION_2(5, "沉降粒子环境中的视线传播理论", 265);
    SUB_SECTION_2(6, "沉降粒子环境中的非视线传输理论", 266);
    SUB_SECTION_1(2, "衰减特性实用模型", 268);
    SUB_SECTION_2(1, "降雨衰减模型", 268);
    SUB_SECTION_2(1, "降雨环境特征衰减计算模型", 269);
    SUB_SECTION_2(1, "降雨环境等效路径计算模型", 282);
    SUB_SECTION_2(1, "雨衰长期统计特性预报", 285);
    SUB_SECTION_2(1, "基于测量数据确定α_H、α_V和b_H、b_V的方法", 285);
    SUB_SECTION_2(1, "降雨衰减频率比例因子及其他问题", 292);
    SUB_SECTION_2(1, "基于非1分钟累积时间降雨率的雨衰预报模型", 292);
    SUB_SECTION_2(1, "降雨衰减实时预报模型", 293);
    SUB_SECTION_2(1, "降雨衰减时间序列获取方法", 307);
    SUB_SECTION_2(2, "降雪、冰晶(融化层)、冰雹环境中的衰减", 311);
    SUB_SECTION_2(3, "云、雾环境中的衰减", 312);
    SUB_SECTION_2(4, "沙尘环境中的衰减", 313);
    SUB_SECTION_1(3, "去极化实用模型", 316);
    SUB_SECTION_2(1, "降雨环境去极化模型", 316);
    SUB_SECTION_2(1, "简化的雨致去极化理论模型", 316);
    SUB_SECTION_2(1, "基于同极化衰减的雨致去极化预报模型", 318);
    SUB_SECTION_2(2, "冰晶环境去极化效应", 321);
    SUB_SECTION_2(3, "降雪及沙尘环境去极化模型", 321);
    SUB_SECTION_1(4, "沉降粒子环境附加噪声", 322);
    SUB_SECTION_1(5, "沉降粒子对多径信道包络概率密度的影响", 323);
    SUB_SECTION_1(6, "沉降粒子的多普勒频偏", 332);
    SUB_SECTION_1(7, "沉降粒子环境中非相干信号功率角分布", 334);
    SUB_SECTION_1(8, "沉降粒子环境中的其他传输效应", 348);
    EXERCISE_REF("思考和训练6", 348);
    EXERCISE_REF("本章参考文献", 349);

    return 0;
}