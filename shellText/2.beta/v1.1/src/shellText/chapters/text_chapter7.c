#include "../../../include/shellText/chapters/text_chapter7.h"
void display_chapter7(){
 setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 第七章内容
    CHAPTER_7("对流层大气中的光传输特性简介", 353);
    CHAPTER_7_SUB_SECTION_1(1, "对流层大气对光的衰减", 353);
    CHAPTER_7_SUB_SECTION_2(1, "气体分子的吸收衰减", 353);
    CHAPTER_7_SUB_SECTION_2(2, "气体分子的散射衰减", 356);
    CHAPTER_7_SUB_SECTION_2(3, "沉降粒子的衰减", 357);
    CHAPTER_7_SUB_SECTION_2(4, "对流层大气中光衰减实用模型", 357);
    CHAPTER_7_SUB_SECTION_1(2, "晴空分层大气对光的折射", 359);
    CHAPTER_7_SUB_SECTION_1(3, "大气湍流中的光传输理论", 360);
    CHAPTER_7_SUB_SECTION_2(1, "弱湍流中的光传输理论", 360);
    CHAPTER_7_SUB_SECTION_2(2, "强湍流中的光传输理论", 362);
    CHAPTER_7_SUB_SECTION_1(4, "对流层大气对光的去极化(偏振)效应", 366);
    CHAPTER_7_SUB_SECTION_1(5, "对流层中光的其他传输特性", 367);
    CHAPTER_7_EXERCISE_REF("思考和训练7", 367);
    CHAPTER_7_EXERCISE_REF("本章参考文献", 368);

}