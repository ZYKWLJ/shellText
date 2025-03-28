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
#include "../../v1.0/include/color.h"
// #include "../include/lib.h"

#include <stdio.h>
#include <stdlib.h>
// 假设search_word函数所在的头文件为search.h
#include "search.h" 

int main() {
    // 测试搜索所有库中的单词
    char *word = "a6";
    char **result = search_word(word, 0);
    if (result) {
        printf("Search results in all libraries for word '%s':\n", word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No results found in all libraries for word '%s'\n", word);
    }

    // 测试搜索特定库中的单词
    int libraryIndex = 1;
    result = search_word(word, libraryIndex);
    if (result) {
        printf("\nSearch results in library %d for word '%s':\n", libraryIndex, word);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    } else {
        printf("No results found in library %d for word '%s'\n", libraryIndex, word);
    }

    return 0;
} 
/*
// 页面跳转指令，实现page n/p n指令！
// 简单的，还是按照页面存储和搜索指令！
// 在完善find命令就over了！检索系统！
*/