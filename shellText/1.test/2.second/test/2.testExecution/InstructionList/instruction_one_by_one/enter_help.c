#include "enter_help.h"

void enter_help()
{
    printf("%s%s[guide......指令集]> %s 键入help获取指令表,键入回车跳过,键入exit退出指引\n", BOLD, PURPLE, RESET);
    // printf("%s%s[guide......help]> %s 键入help获取指令表,键入exit退出指引\n", BOLD, PURPLE, RESET);
   
    char *help_instructions_set[3] = {"\n", "exit","help"};
    char* currentFunction = "指令集";
    int ret = guide_must_enter(help_instructions_set,currentFunction);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 2:
        help();//具体的指令实现
        break;
    default:
        break;
    }
}