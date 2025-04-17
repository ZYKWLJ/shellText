#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <readline/history.h>
#include <readline/readline.h>

#include "../include/shellText/text_color.h"
#include "../include/shellText/text_execute.h"
#include "../include/shellText/text_endSay.h"
#include "../include/shellText/text_copyRight.h"
#include "../include/shellText/englinux/englinux.h"

#include "../include/englinux/display/eg_color.h"
#include "../include/englinux/execute/eg_execute.h"
#include "../include/englinux/display/eg_endSay.h"
#include "../include/englinux/display/eg_copyRight.h"

// 教材内容
void text()
{
    // 注册信号处理函数
    signal(SIGINT, text_exit_signal_handler);
    char *str;
    // text_print_copyright();
    while (1)
    {
        char prompt[100];
        sprintf(prompt, "%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
        str = readline(prompt);

        if (str == NULL)
        {
            // 用户按下 Ctrl+D
            printf("\n程序终止\n");
            break;
        }

        if (strlen(str) == 0)
        {
            // 空输入，继续循环
            free(str);
            continue;
        }

        // 复制 str
        char *str_copy = strdup(str);
        if (str_copy == NULL)
        {
            perror("内存分配失败");
            free(str);
            continue;
        }

        // 执行指令
        text_execute(str); // 这里传入的是原始字符串，可能会被修改

        // 添加到历史记录
        add_history(str_copy); // 这里传入的是原始复制字符串，原始字符串的修改对我没影响

        // 释放复制的字符串
        free(str_copy);
        // 释放 readline 分配的内存
        free(str);
    }
}


// 主函数
int main()
{
    // 注册信号处理函数
    signal(SIGINT, text_exit_signal_handler);
    char *str;
    text_print_copyright();
    while (1)
    {
        char prompt[100];
        sprintf(prompt, "%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
        str = readline(prompt);
        if (strcmp(str, "eg") == 0)
        {
            englinux();
        }
        text(); // 默认进入text();
    }
    return 0;
}
