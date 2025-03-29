#include "../../include/execute.h"

char *instructions_all[50] = {
    // 全局指令
    "help",  // 帮助指令 0
    "find",  // 查找知识点 1
    "clear", // 清屏 2
    "exit",  // 退出程序 3
    // "find",  // 查找单词4
    "f",     // 同find 5
    "NULL"};


// 执行命令的函数
void execute(char *str)
{
    // printf("执行前命令: %s\n", str);
    trim(str);
    // printf("减枝后命令: %s\n", str);

    char full_command[256] = {0};
    strcpy(full_command, str);

    // 分割命令为单词
    // 第一个单词
    char *token = strtok(str, " ");
    if (token == NULL)
    {
        printf("提示：命令不存在！\n请重新输入！\n");
        return;
    }
    // int library = 0;
    // int search_mod = 0;
    // int first_show = 1, second_show = 0, third_show = 3; // 默认显示单词和释义
    // 1.判读find指令
    // printf("第一个单词为:%s\n", token);
    if (strcasecmp(token, "find") == 0 || strcasecmp(token, "f") == 0)
    {
        // printf("第一个单词为find指令\n");
        find_parser(token, full_command);

    }
    // 2.判断exit指令
    else if (strcasecmp(token, "exit") == 0)
    {
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            // printf("%s%s退出程序！%s\n", RED, BOLD, RESET);
            exit_signal_handler(2); // 和ctrl+c一样的效果
        }
        else
        {
            printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("exit "), RESET, BOLD, RED, RESET);
        }
    }
    // 3.判断help指令
    else if (strcasecmp(token, "help") == 0)
    {
        help_list();
    }
    // 4.判断clear指令
    else if (strcasecmp(token, "clear") == 0)
    {
        clear();
    }
    // 4.判断其他指令
    else
    {
        printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command, RESET, BOLD, RED, RESET);
        find_similar_commands(full_command);
    }
}

