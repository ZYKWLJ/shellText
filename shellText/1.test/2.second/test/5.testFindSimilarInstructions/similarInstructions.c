#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 颜色宏定义
#define YELLOW "\x1B[33m"
#define RESET "\x1B[0m"

// 系统命令列表
char *instructions_all[50] = {
    // 全局指令
    "help",    // 帮助指令 0
    "list",    // 列出所有章节 1
    "find",    // 查找知识点 2
    "clear",   // 清屏 3
    "exit",    // 退出程序 4
    "story",   // 软件背后的故事 5
    "author",  // 作者信息 6
    "subject", // 学科介绍 7
    // 一级目录指令
    "list 1",  // 列出第一章 8
    "list 2",  // 列出第二章 9
    "list 3",  // 列出第三章 10
    "list 4",  // 列出第四章 11
    "list 5",  // 列出第五章 12
    "list 6",  // 列出第六章 13
    "list 7",  // 列出第七章 14
    "list 8",  // 列出第八章 15
    "list 9",  // 列出第九章 16
    "ls 1",    // 17
    "ls 2",    // 18
    "ls 3",    // 19
    "ls 4",    // 20
    "ls 5",    // 21
    "ls 6",    // 22
    "ls 7",    // 23
    "ls 8",    // 24
    "ls 9",    // 25
    "guide",   // 26
    "chinese", // 27
    "english"  // 28
};

// 计算两个字符串的重复字符数
int count_common_chars(const char *str1, const char *str2)
{
    int common = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int visited[len2];//如果正确的指令被访问过了，就置为1，否则为0！正确的！
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (tolower(str1[i]) == tolower(str2[j]) && !visited[j]/*防止重复访问*/)
            {
                common++;
                visited[j] = 1;
                break;
            }
        }
    }
    return common;
}

// 查找相似命令
void find_similar_commands(const char *input)
{
    int input_len = strlen(input);
    int found = 0;

    for (int i = 0; i < 29; i++)
    {
        int common = count_common_chars(input, instructions_all[i]);
        if (common > input_len / 2)
        {
            if (!found)
            {
                printf("你可能想输入的命令是：\n");
                found = 1;
            }
            printf(YELLOW "%s\t" RESET, instructions_all[i]);
        }
    }
    if (!found)
    {
        printf("未找到相似命令。\n");
    }
    else
    {
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        char input[100];
        printf("请输入命令：");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // 去除换行符

        find_similar_commands(input);
    }
    return 0;
}