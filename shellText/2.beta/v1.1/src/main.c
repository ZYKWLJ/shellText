#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "../include/color.h"
#include "../include/execute.h"
#include "../include/endSay.h"
#include "../include/copyRight.h"
void text(){



}


void englinux(){
}


int main()
{
    // 注册信号处理函数
    signal(SIGINT, exit_signal_handler);
    char *str;
    print();
    while (1)
    {
        char prompt[100];
        sprintf(prompt, "%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
        str = readline(prompt);

        if (str == NULL) {
            // 用户按下 Ctrl+D
            printf("\n程序终止\n");
            break;
        }

        if (strlen(str) == 0) {
            // 空输入，继续循环
            free(str);
            continue;
        }

        // 执行指令
        execute(str);

        // 添加到历史记录
        add_history(str);

        // 释放 readline 分配的内存
        free(str);
    }
    
    return 0;
}

/*
// 页面跳转指令，实现page n/p n指令！
// 简单的，还是按照页面存储和搜索指令！
// 在完善find命令就over了！检索系统！
*/