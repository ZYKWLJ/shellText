#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonTools/color/color.h"
#include "execute/execute.h"
#include "endSay/endSay.h"
int main()
{
    // 注册信号处理函数
    signal(SIGINT, exit_signal_handler);
    char str[100];
    while (1)
    {
        printf("%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
        // 去除 fgets 读取的换行符
        fgets(str, sizeof(str), stdin);
        if (strlen(str) == 1 && str[0] == '\n') // 直接不执行，继续读取
        {
            continue;
        }
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }
        execute(str);
    }
    return 0;
}
/*
主程序流程
1.直接进入指令读取界面

2.按下help获取帮助后，可进入guide界面，进行学习

3.没了！

4.增加指令提示功能，就是看最接近的指令，然后提示正确指令！这是一个难点！
主打一个简洁！

gcc命令
gcc main.c ../2.testExecution/Execute.c ../2.testExecution/InstructionList/InstructionList.c ../2.testExecution/EliminateSpace/EliminateSpace.c -o main
 */