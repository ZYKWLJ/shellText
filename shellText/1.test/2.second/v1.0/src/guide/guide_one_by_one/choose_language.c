#include "choose_language.h"
void choose_language()
{
    printf("%s%s[guide......语言选择]> %s 键入Chinese设置中文,键入English设置英文,键入回车跳过,键入exit退出指引\n", BOLD, PURPLE, RESET);
    char *chooseLanguage[4] = {"\n", "exit", "chinese", "english"};
    // 指令预处理包含在里面了，只要返回0，1就是跳过或者退出！
    char *currentFunction = "语言选择";
    int ret = guide_must_enter(chooseLanguage, currentFunction);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 2:
        set_language(chooseLanguage[ret]);
        break;
    default:
        break;
    }
}