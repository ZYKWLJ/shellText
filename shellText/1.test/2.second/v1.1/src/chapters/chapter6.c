#include "../../include/chapters/chapter6.h"

void display_chapter6(){
     setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 第六章内容
    CHAPTER_6("大气沉降粒子中的传播与散射", 255);
    CHAPTER_6_SUB_SECTION_1(1, "大气沉降粒子中电磁波传播与散射的基本理论", 255);
    CHAPTER_6_SUB_SECTION_2(1, "单个粒子对电磁波的散射和吸收", 255);
    CHAPTER_6_SUB_SECTION_2(2, "沉降粒子环境中电磁波的传输问题分类", 259);
    CHAPTER_6_SUB_SECTION_2(3, "沉降粒子环境中的衰减及相移理论", 260);
    CHAPTER_6_SUB_SECTION_2(4, "沉降粒子环境中的去极化理论", 263);
    CHAPTER_6_SUB_SECTION_2(5, "沉降粒子环境中的视线传播理论", 265);
    CHAPTER_6_SUB_SECTION_2(6, "沉降粒子环境中的非视线传输理论", 266);
    CHAPTER_6_SUB_SECTION_1(2, "衰减特性实用模型", 268);
    CHAPTER_6_SUB_SECTION_2(1, "降雨衰减模型", 268);
    CHAPTER_6_SUB_SECTION_2(1, "降雨环境特征衰减计算模型", 269);
    CHAPTER_6_SUB_SECTION_2(1, "降雨环境等效路径计算模型", 282);
    CHAPTER_6_SUB_SECTION_2(1, "雨衰长期统计特性预报", 285);
    CHAPTER_6_SUB_SECTION_2(1, "基于测量数据确定α_H、α_V和b_H、b_V的方法", 285);
    CHAPTER_6_SUB_SECTION_2(1, "降雨衰减频率比例因子及其他问题", 292);
    CHAPTER_6_SUB_SECTION_2(1, "基于非1分钟累积时间降雨率的雨衰预报模型", 292);
    CHAPTER_6_SUB_SECTION_2(1, "降雨衰减实时预报模型", 293);
    CHAPTER_6_SUB_SECTION_2(1, "降雨衰减时间序列获取方法", 307);
    CHAPTER_6_SUB_SECTION_2(2, "降雪、冰晶(融化层)、冰雹环境中的衰减", 311);
    CHAPTER_6_SUB_SECTION_2(3, "云、雾环境中的衰减", 312);
    CHAPTER_6_SUB_SECTION_2(4, "沙尘环境中的衰减", 313);
    CHAPTER_6_SUB_SECTION_1(3, "去极化实用模型", 316);
    CHAPTER_6_SUB_SECTION_2(1, "降雨环境去极化模型", 316);
    CHAPTER_6_SUB_SECTION_2(1, "简化的雨致去极化理论模型", 316);
    CHAPTER_6_SUB_SECTION_2(1, "基于同极化衰减的雨致去极化预报模型", 318);
    CHAPTER_6_SUB_SECTION_2(2, "冰晶环境去极化效应", 321);
    CHAPTER_6_SUB_SECTION_2(3, "降雪及沙尘环境去极化模型", 321);
    CHAPTER_6_SUB_SECTION_1(4, "沉降粒子环境附加噪声", 322);
    CHAPTER_6_SUB_SECTION_1(5, "沉降粒子对多径信道包络概率密度的影响", 323);
    CHAPTER_6_SUB_SECTION_1(6, "沉降粒子的多普勒频偏", 332);
    CHAPTER_6_SUB_SECTION_1(7, "沉降粒子环境中非相干信号功率角分布", 334);
    CHAPTER_6_SUB_SECTION_1(8, "沉降粒子环境中的其他传输效应", 348);
    CHAPTER_6_EXERCISE_REF("思考和训练6", 348);
    CHAPTER_6_EXERCISE_REF("本章参考文献", 349);
}
// int main() {