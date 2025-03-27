#include "../../include/guide_must_enter.h"
// 在指引阶段必须要输入指令！因为演示效果所致！
// int guide_must_enter(char **currentInstructionSet /*期望的指令集*/, char *currentFunction /*当前的功能*/)
// {

//     int ret = 0;
//     // int flag = 1;
//     while (1)
//     {
//         char enterInstruction[100];
//         fgets(enterInstruction, sizeof(enterInstruction), stdin);
//         printf("当前传进来的命令:%s\n", enterInstruction);
//         if (strcmp(enterInstruction, "\n") == 0)
//         {
//             return 0; // 表示跳过当前指引步骤
//         }

//         size_t len = strlen(enterInstruction);
//         if (len > 0 && enterInstruction[len - 1] == '\n')
//         {
//             enterInstruction[len - 1] = '\0';
//         }
//         eliminateSpace(enterInstruction); // 空格去除、连续空格压缩，并且全部转化为小写
//         // printf("语法选择的命令为:%s\n", enterInstruction);调试信息，现在不用了！
//         printf("修正后，当前传进来的命令:%s\n", enterInstruction);
//         for (int i = 1; currentInstructionSet[i]; i++)
//         {
//             printf("当前指令集的命令为:%s\t比较的命令为%s\n", currentInstructionSet[i], enterInstruction); // 调试信息，现在不用了！
//             if (strcmp(enterInstruction, currentInstructionSet[i]) == 0)
//             {
//                 return i;
//             }
//         }
        
//         puts("xxxxx错误命令");
//         char *InstructionSetStr = (char *)malloc(sizeof(char) * 1000);
//         for (int i = 0; currentInstructionSet[i]; i++)
//         {
//             InstructionSetStr = strcat(InstructionSetStr, "\t");
//             InstructionSetStr = strcat(InstructionSetStr, currentInstructionSet[i]);
//         }
//         printf("%s%s[guide......%s]> %s 输入错误，请重新输入\n%s\n", BOLD, PURPLE, currentFunction, RESET, InstructionSetStr);
//     }
//     return ret;
// }


int guide_must_enter(char **currentInstructionSet, char *currentFunction, char *prompt)
{
    while (1)
    {
        printf("%s", prompt);
        char enterInstruction[100] = {0}; // 初始化为全0
        if (!fgets(enterInstruction, sizeof(enterInstruction), stdin))
        {
            return 0; // 读取失败时返回
        }

        // printf("当前传进来的命令:%s\n", enterInstruction);

        // 处理空输入或换行符
        if (strcmp(enterInstruction, "\n") == 0)
        {
            return 0;
        }

        // 移除末尾的换行符
        size_t len = strlen(enterInstruction);
        if (len > 0 && enterInstruction[len - 1] == '\n')
        {
            enterInstruction[len - 1] = '\0';
        }

        eliminateSpace(enterInstruction);
        // printf("修正后，当前传进来的命令:%s\n", enterInstruction);

        // 检查指令是否在允许的指令集中
        for (int i = 1; currentInstructionSet[i] != "NULL"; i++)
        {
            // printf("当前指令集的命令为:%s\t比较的命令为%s\n",currentInstructionSet[i], enterInstruction);
            if (strcmp(enterInstruction, currentInstructionSet[i]) == 0)
            {
                printf("匹配成功:%s\n", currentInstructionSet[i]);
                return i;
            }
        }
        printf("%s%s输入错误,请重新输入:%s\n", BOLD, RED, RESET);
    }
}