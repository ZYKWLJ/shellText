#include "execute.h"

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
    "english", // 28
};

int isValidInstruction(char *str)
{
    eliminateSpace(str); // 空格去除、连续空格压缩，并且全部转化为小写
    // printf("预处理后的指令为：%s\n", str);
    // puts("这是isValidInstruction函数，这里只需要遍历指令数组，进行匹配，不在就报错！在就执行，太屌丝了！");
    for (int i = 0; instructions_all[i]; i++)
    {
        if (strcmp(str, instructions_all[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void executeInstruction(int Instruction_index)
{
    switch (Instruction_index)
    {
    case 0:
        help();
        break;
    case 1:
        list();
        break;
    case 2:
        find();
        break;
    case 3:
        clear_screen();
        break;
    case 4:
        exit_program();
        break;
    case 5:
        story();
        break;
    case 6:
        author_info();
        break;
    case 7:
        subject_intro();
        break;
    case 8:
    case 17:
        list_chapter(1);
        break;
    case 9:
    case 18:
        list_chapter(2);
        break;
    case 10:
    case 19:
        list_chapter(3);
        break;
    case 11:
    case 20:
        list_chapter(4);
        break;
    case 12:
    case 21:
        list_chapter(5);
        break;
    case 13:
    case 22:
        list_chapter(6);
        break;
    case 14:
    case 23:
        list_chapter(7);
        break;
    case 15:
    case 24:
        list_chapter(8);
        break;
    case 16:
    case 25:
        list_chapter(9);
        break;
    case 26:
        guide();
        break;
    case 27:
    case 28:
        set_language(instructions_all[Instruction_index]);
        break;

    default:
        printf("无效的指令索引\n");
        break;
    }
}

void execute(char *str)
{
    int Instruction_index = isValidInstruction(str);
    if (Instruction_index != -1)
    {
        // printf("执行有效的%s指令\n", str);
        executeInstruction(Instruction_index);
    }
    else
    {
        printf("%s%s%s--无效指令！%s(按下%s%shelp%s可以获取帮助)\n", BOLD,RED,str,RESET,BOLD,YELLOW,RESET);
    }
}

// int main(int argc, char const *argv[])
// {
//     while (1)
//     {
//         instruction("help");
//     }

//     return 0;
// }
/*
gcc
gcc main.c ../2.testExecution/Execute.c ../2.testExecution/InstructionList/InstructionList.c ../2.testExecution/EliminateSpace/EliminateSpace.c -o main
*/
