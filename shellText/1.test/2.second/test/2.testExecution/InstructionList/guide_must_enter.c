#include "guide_must_enter.h"
#include "../EliminateSpace/EliminateSpace.h"
// 在指引阶段必须要输入指令！因为演示效果所致！
int guide_must_enter(char **currentInstructionSet /*期望的指令集*/, char *currentFunction /*当前的功能*/)
{

    int ret = 0;
    int flag = 1;
    while (flag)
    {
        char enterInstruction[100];
        fgets(enterInstruction, sizeof(enterInstruction), stdin);
        eliminateSpace(enterInstruction); // 空格去除、连续空格压缩，并且全部转化为小写
        if (strcmp(enterInstruction, "\n") == 0)
        {
            return 0; // 表示跳过当前指引步骤
        }

        size_t len = strlen(enterInstruction);
        if (len > 0 && enterInstruction[len - 1] == '\n')
        {
            enterInstruction[len - 1] = '\0';
        }
        eliminateSpace(enterInstruction);
        // printf("语法选择的命令为:%s\n", enterInstruction);调试信息，现在不用了！
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(enterInstruction, currentInstructionSet[i]) == 0)
            {
                flag = 0;
                ret = i;
            }
        }
        if (flag)
        {
            char *InstructionSetStr = "";
            for (int i = 0; currentInstructionSet[i]; i++)
            {
                InstructionSetStr = strcat(InstructionSetStr, "\t");
                InstructionSetStr = strcat(InstructionSetStr, currentInstructionSet[i]);
            }
            printf("%s%s[guide......%s]> %s 输入错误，请重新输入\n%s\n", BOLD, PURPLE, currentFunction, RESET, InstructionSetStr);
        }
    }
    return ret;
}