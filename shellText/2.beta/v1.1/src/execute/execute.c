#include "../../include/execute.h"
#include "../../include/similarInstructions.h"
// #include ""

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
    "page",    // 26
    "p",       // 27
    "f"        // 28同find
    // "guide",   // 26砍掉不关紧要的命令与功能呢！
    // "chinese", // 27
    // "english", // 28
};

int isValidInstruction(char *str)
{
    eliminateSpace(str); // 空格去除、连续空格压缩，并且全部转化为小写
    // printf("预处理后的指令为：%s\n", str);
    // 如果是page 和p指令，需要特判，因为page和p后面可能跟数字，而且数字很大！！！
    for (int i = 0; instructions_all[i]; i++)
    {
        if (strcmp(str, instructions_all[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void executeInstruction(int Instruction_index, char *str)
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
    case 28:
        find(str);
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
    case 27:
        page_preprocess(str);
        break;
    default:
        printf("%s%s暂无该指令%s\n", RED, BOLD, RESET);
        break;
    }
}

void execute(char *str)
{
    // 提前对页面指令进行预处理，拆分！即将之用空格分开，并且长度为2，第一个是page或者p，第二个是数字则认为正确!
    char *str0 = (char *)malloc(strlen(str) + 1);
    if (str0 == NULL)
    {
        fprintf(stderr, "内存分配失败\n");
        return;
    }
    strcpy(str0, str);

    eliminateSpace(str); // 空格去除、连续空格压缩，并且全部转化为小写
    char first_word[100];
    sscanf(str, "%99s", first_word); // 先把第一个单词提取出来，后面再进行判断！因为这里的sscanf遇到空格就会停止！

    int Instruction_index = -1;

    if (strcmp(first_word, "page") == 0 || strcmp(first_word, "p") == 0)
    {
        // printf("是页面查找命令且页面查找命令有效！执行有效的%s指令\n", str0);
        Instruction_index = isValidInstruction(first_word); // 必须消除page指令的无限性，所以只能先传入page或者p，然后再进行判断！
    }
    else if (strcmp(first_word, "find") == 0 || strcmp(first_word, "f") == 0)
    {
        // printf("是页面查找命令且页面查找命令有效！执行有效的%s指令\n", str0);
        Instruction_index = isValidInstruction(first_word); // 必须消除page指令的无限性，所以只能先传入page或者p，然后再进行判断！
    }
    else
    {
        Instruction_index = isValidInstruction(str0); // 传入原始字符串，因为还有其他的含有空格字符串
    }
    // 这里才开始执行！
    if (Instruction_index != -1)
    {
        // printf("现在前往执行有效的%s指令了\n", str0);
        executeInstruction(Instruction_index, str0); // page指令就必须先进行预处理！看能不能是page和p才有后续的页面判断操作！所以这里传入的是str0！及是原字符串Page 11  2！
    }
    else
    {
        printf("%s%s%s--无效指令！%s(按下%s%shelp%s可以获取帮助)\n", BOLD, RED, str0, RESET, BOLD, YELLOW, RESET); // 这里提示的信息也是原字符串！
        find_similar_commands(str0);                                                                               // 相似指令也是原始字符串！
    }

    free(str0);
}