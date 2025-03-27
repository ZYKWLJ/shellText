/*
主程序流程
1.直接进入指令读取界面

2.按下help获取帮助后，可进入guide界面，进行学习

3.没了！

4.增加指令提示功能，就是看最接近的指令，然后提示正确指令！这是一个难点！
主打一个简洁！

cmake命令:假设当前是在main.c所在的目录下
cd ../build && make && ../bin/main


有的时候需要请你cmake缓存！————————
注意头文件不能包含函数实现,否则会重复定义

清理cmake缓存的方法:
rm -rf CMakeCache.txt CMakeFiles

# 重新运行CMake生成构建文件
cmake ..

# 执行构建命令，这里以make为例
make
*/


// 全部变量的定义问题，多文件链编！出错！！自己不会！！！

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "../v1.0/include/color.h"
#include "lib.h"
// int main()
// {
//     // 注册信号处理函数
//     // signal(SIGINT, exit_signal_handler);
//     char *str;
//     // print();
//     while (1)
//     {
//         char prompt[100];
//         sprintf(prompt, "%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
//         str = readline(prompt);
//         char *str0=str;
//         if (str == NULL) {
//             // 用户按下 Ctrl+D
//             printf("\n程序终止\n");
//             break;
//         }

//         if (strlen(str) == 0) {
//             // 空输入，继续循环
//             free(str);
//             continue;
//         }

//         // 执行指令
//         execute(str);

//         // 添加到历史记录
//         add_history(str);

//         // 释放 readline 分配的内存
//         free(str);
//     }
//     return 0;
// }

int main() {
    // 注册信号处理函数
    // signal(SIGINT, exit_signal_handler);
    char *str;
    // print();
    while (1) {
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

        // 复制 str
        char *str_copy = strdup(str);
        if (str_copy == NULL) {
            perror("内存分配失败");
            free(str);
            continue;
        }

        // 执行指令
        execute(str);// 这里传入的是原始字符串，可能会被修改

        // 添加到历史记录
        add_history(str_copy);// 这里传入的是原始复制字符串，原始字符串的修改对我没影响

        // 释放复制的字符串
        free(str_copy);
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