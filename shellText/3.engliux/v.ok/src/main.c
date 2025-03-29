#include "../include/main.h"

int main() {
    // 注册信号处理函数
    signal(SIGINT, exit_signal_handler);
    char *str;
    print();
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
只实现find命令
*/


/*
清理cmake缓存的方法:
rm -rf CMakeCache.txt CMakeFiles

# 重新运行CMake生成构建文件
cmake ..

# 执行构建命令，这里以make为例
make
*/
