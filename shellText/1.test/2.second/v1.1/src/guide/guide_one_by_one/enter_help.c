#include "../../../include/enter_help.h"
void enter_help()
{

    char prompt[150];
    snprintf(prompt, sizeof(prompt), "%s%s[guide......指令集]> %s 键入help获取指令表,键入回车跳过,键入exit退出指引\n",
             BOLD, PURPLE, RESET);
    char *help_instructions_set[4] = {"\n", "exit", "help", "NULL"};
    char *currentFunction = "指令集";
    int ret = guide_must_enter(help_instructions_set, currentFunction, prompt);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    default:
        help();
        break;
    }
}