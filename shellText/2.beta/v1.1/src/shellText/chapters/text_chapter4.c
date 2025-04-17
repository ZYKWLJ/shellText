#include "../../../include/shellText/chapters/text_chapter4.h"
void display_chapter4()
{
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 第四章内容
    CHAPTER_4("对流层顶及其气候特征", 201);
    CHAPTER_4_SUB_SECTION_1(1, "对流层顶概述", 201);
    CHAPTER_4_SUB_SECTION_2(1, "对流层顶的发现、确定方法及其成因", 201);
    CHAPTER_4_SUB_SECTION_2(2, "对流层顶判据", 202);
    CHAPTER_4_SUB_SECTION_2(3, "对流层顶在大气过程中的作用", 203);
    CHAPTER_4_SUB_SECTION_1(2, "对流层顶观测资料气候学整理方法", 203);
    CHAPTER_4_SUB_SECTION_1(3, "对流层顶的特征参数", 204);
    CHAPTER_4_SUB_SECTION_1(4, "对流层顶气候其他问题", 204);
    CHAPTER_4_EXERCISE_REF("思考和训练4", 205);
    CHAPTER_4_EXERCISE_REF("本章参考文献", 205);
}