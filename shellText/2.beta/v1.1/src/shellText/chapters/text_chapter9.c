#include "../../../include/shellText/chapters/text_chapter9.h"
void display_chapter9()
{
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符
    // 第九章内容
    CHAPTER_9("对流层中传输特性测量及模型分析", 421);
    CHAPTER_9_SUB_SECTION_1(1, "晴空大气折射效应测量及折射率剖面建模", 422);
    CHAPTER_9_SUB_SECTION_1(2, "晴空大气闪烁特性测量及模型修正", 422);
    CHAPTER_9_SUB_SECTION_1(3, "降雨衰减测量技术及雨衰模型修正", 423);
    CHAPTER_9_SUB_SECTION_1(4, "去极化特性测量技术及去极化计算模型修正", 424);
    CHAPTER_9_SUB_SECTION_1(5, "其他传输特性的测量", 425);
    CHAPTER_9_SUB_SECTION_1(6, "太赫兹波段电磁波传输特性测量及建模", 425);
    CHAPTER_9_EXERCISE_REF("思考和训练9", 427);
    CHAPTER_9_EXERCISE_REF("本章参考文献", 428);
}