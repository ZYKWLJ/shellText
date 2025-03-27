#include "../../include/chapters/chapter2.h"
void display_chapter2()
{
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 第二章内容
    CHAPTER_2("晴空大气的物理及电磁特性", 12);
    CHAPTER_2_SUB_SECTION_1(1, "大气组成及其物理特性", 12);
    CHAPTER_2_SUB_SECTION_2(1, "大气组成", 12);
    CHAPTER_2_SUB_SECTION_2(2, "物理特性及其时空分布", 14);
    CHAPTER_2_SUB_SECTION_2(2, "温度及其时空分布", 14);
    CHAPTER_2_SUB_SECTION_2(2, "大气压强及其时空分布", 19);
    CHAPTER_2_SUB_SECTION_2(2, "大气湿度及其时空分布", 22);
    CHAPTER_2_SUB_SECTION_1(2, "晴空大气电磁特性参数及时空分布", 36);
    CHAPTER_2_SUB_SECTION_2(1, "大气电磁特性参数", 37);
    CHAPTER_2_SUB_SECTION_2(2, "大气折射指数时空分布", 43);
    CHAPTER_2_SUB_SECTION_2(3, "大气折射指数的测量", 54);
    CHAPTER_2_SUB_SECTION_1(3, "大气湍流", 55);
    CHAPTER_2_SUB_SECTION_2(1, "大气湍流的形成机理", 56);
    CHAPTER_2_SUB_SECTION_2(2, "大气湍流的基本特征及研究理论", 57);
    CHAPTER_2_SUB_SECTION_2(3, "大气湍流电磁参数起伏的结构函数和空间谱", 59);
    CHAPTER_2_SUB_SECTION_1(4, "大气波导", 63);
    CHAPTER_2_SUB_SECTION_2(1, "大气波导的形成机理及分类", 63);
    CHAPTER_2_SUB_SECTION_2(2, "大气波导的特征参数", 65);
    CHAPTER_2_SUB_SECTION_2(3, "大气波导时空分布统计规律", 67);
    CHAPTER_2_SUB_SECTION_2(4, "大气波导的诊断和预报", 74);
    CHAPTER_2_SUB_SECTION_1(5, "对流层人工变态简介", 76);
    CHAPTER_2_SUB_SECTION_2(1, "对流层人工变态技术现状", 76);
    CHAPTER_2_SUB_SECTION_2(2, "相干声波扰动对流层及其应用机理", 77);
    CHAPTER_2_SUB_SECTION_2(3, "相干声波扰动大气折射指数理论", 79);
    CHAPTER_2_SUB_SECTION_2(4, "定性验证人工不均匀体的可行性", 81);
    CHAPTER_2_EXERCISE_REF("思考和训练2", 87);
    CHAPTER_2_EXERCISE_REF("本章参考文献", 88);
}