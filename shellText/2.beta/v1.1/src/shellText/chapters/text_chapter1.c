
#include "../../../include/shellText/chapters/text_chapter1.h"
void display_chapter1() {
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符
    CHAPTER_1("绪论", 1);
    CHAPTER_1_SUB_SECTION_1(1, "概述", 1);
    CHAPTER_1_SUB_SECTION_1(2, "对流层中的传输效应及其产生机理", 3);
    CHAPTER_1_SUB_SECTION_2(1, "折射和反射", 3);
    CHAPTER_1_SUB_SECTION_2(2, "散射", 3);
    CHAPTER_1_SUB_SECTION_2(3, "吸收、衰减、相移", 4);
    CHAPTER_1_SUB_SECTION_2(4, "去极化", 5);
    CHAPTER_1_SUB_SECTION_2(5, "噪声、干扰", 6);
    CHAPTER_1_SUB_SECTION_2(6, "其他", 6);
    CHAPTER_1_SUB_SECTION_1(3, "对流层传播模式", 7);
    CHAPTER_1_SUB_SECTION_2(1, "对流层视距传播", 7);
    CHAPTER_1_SUB_SECTION_2(2, "对流层超视距传播", 7);
    CHAPTER_1_SUB_SECTION_1(4, "对流层传输对无线系统的影响", 8);
    CHAPTER_1_SUB_SECTION_1(5, "本书的总结构分布", 9);
    CHAPTER_1_EXERCISE_REF("思考和训练1", 10);
    CHAPTER_1_EXERCISE_REF("本章参考文献", 10);
}
