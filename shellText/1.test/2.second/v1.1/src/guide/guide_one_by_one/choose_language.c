#include "../../../include/choose_language.h"
void choose_language()
{
    char *chooseLanguage[5] = {"\n", "exit", "chinese", "english", "NULL" /*标志位*/};
    char *currentFunction = "语言选择";
    char prompt[200];
    snprintf(prompt, sizeof(prompt), "%s%s[guide......%s]> %s 键入%sChinese%s设置中文,键入%sEnglish%s设置英文,键入%s回车%s跳过,键入%sexit%s退出指引\n",
             BOLD, PURPLE, currentFunction, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET);
    // printf("%s%s[guide......语言选择]> %s 键入Chinese设置中文,键入English设置英文,键入回车跳过,键入exit退出指引\n",
    //       BOLD, PURPLE, RESET);

    int ret = guide_must_enter(chooseLanguage, currentFunction, prompt);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    default:
        set_language(chooseLanguage[ret]);
        break;
    }
}

