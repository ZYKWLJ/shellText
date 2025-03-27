#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

#define MAX_LINE_WIDTH 82  // 41个中文字符 ≈ 82字节

void formatText(const char *text) {
    setlocale(LC_ALL, "zh_CN.UTF-8"); // 设置中文环境
    
    int line_length = 0;
    const char *word_start = text;
    const char *p = text;
    
    while (*p) {
        int char_len = mblen(p, MB_CUR_MAX); // 计算当前字符的字节数（中文=3，英文=1）
        if (char_len <= 0) char_len = 1;     // 防止错误
        
        // 遇到换行符，直接换行
        if (*p == '\n') {
            while (word_start < p) {
                putchar(*word_start++);
            }
            putchar('\n');
            line_length = 0;
            word_start = p + 1;
            p++;
            continue;
        }
        
        // 遇到空格，检查是否需要换行
        if (*p == ' ') {
            int word_len = p - word_start;
            if (line_length + word_len > MAX_LINE_WIDTH) {
                putchar('\n');
                line_length = 0;
            }
            while (word_start < p) {
                putchar(*word_start++);
                line_length++;
            }
            putchar(' ');
            line_length++;
            word_start = p + 1;
        }
        
        p += char_len; // 跳到下一个字符
    }
    
    // 输出剩余部分
    if (word_start < p) {
        if (line_length + (p - word_start) > MAX_LINE_WIDTH) {
            putchar('\n');
        }
        while (word_start < p) {
            putchar(*word_start++);
        }
    }
}

// int main() {
//     const char *content =
//         "# 1.1 概  述\n\n"
//         "以地球为参照物，电磁波空间传播环境可以分为地、海面以下环境，地表环境，对流层环境，平流层环境，过渡层（中间层）环境，电离层环境，磁层及外太空环境。其中，地、海面以下环境和地表环境属于地球结构环境，其他环境可以归属于空间大气环境。\n\n"
//         "如图1.1所示，地球形似一略高的球体，平均半径为6370 km。根据地震波的传播证明，地球从里到外可分为地核、地幔和地壳三层。表层70~80 km厚的坚硬部分，称为地壳，地壳各处的厚度不同，海洋下面较薄，最薄处约5 km，陆地处的地壳较厚，总体的平均厚度约33 km。地壳的表面是电导率较大的冲积层。由于地球内部作用（如地壳运动、火山爆发等），以及外部的风化作用，地球表面形成了高山、深谷、江河、平原等地形地貌，再加上人为所创建的城镇田野等，这些不同的地质结构及地形地物，在一定程度上影响着无线电波的传播[1]。电磁波沿地球表层传播的理论和实验方面的内容可参见“地波传播”方面的资料。如果电磁波透过地球表层深入至地球内部传播，则需要了解透地传播方面的资料。\n\n"
//         "图1.1 地球结构示意图[2]\n\n"
//         "地球周围是厚达两万多千米的大气层，大气层里发生的运动变化对无线电波传播有很大影响，对人类的生存环境也有很大影响。地球周围的空间大气环境概况如图1.2所示。\n\n"
//         "对流层位于地球大气底层，自地面向上延伸，它的上边界高度随不同纬度、季节和天气状况而有所差别。在赤道附近，这个高度平均为16~18 km，在温带地区平均为10~12 km，在南北极平均为8~10 km，不同的参考文献对于对流层的高度描述有所差别[3]。对流层环境是人们最熟悉的空间环境，它集中了3/4大气质量和90%以上的水汽，我们熟知的云、";
    
//     formatText(content);
//     return 0;
// }