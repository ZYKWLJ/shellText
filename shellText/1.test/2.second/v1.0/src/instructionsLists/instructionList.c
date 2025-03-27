#include "instructionList.h"
void help()
{
    printf("%s%s<<[........指令表.......]>> \n%s", BOLD, GREEN, RESET);
    printf("%s%s[guide........新手手把手教学] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[help... .......展示全部指令] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list... .......列出所有章节] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[find........ ....查找知识点] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[clear.................清屏] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[exit...............退出程序] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[story..............软件故事] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[author.............作者信息] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[subject............学科介绍] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[chinese.......设置语言为中文] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[english.......设置语言为英文] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 1 ls 1......列出第一章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 2/ls 2......列出第二章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 3/ls 3......列出第三章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 4/ls 4......列出第四章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 5/ls 5......列出第五章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 6/ls 6......列出第六章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 7/ls 7......列出第七章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 8/ls 8......列出第八章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 9/ls 9......列出第九章] \n%s", BOLD, YELLOW, RESET);
}

void list()
{
    // printf("%s%s[contents ......]> \n%s",BOLD,YELLOW,RESET);
    printf("%s%s[目录 ......]> \n%s", BOLD, YELLOW, RESET);
}
void find(char *str)
{
    printf("%s%s[查找知识点 ......]> \n%s", BOLD, YELLOW, RESET);
    // printf("查找特定的知识点。\n");
    
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void exit_program()
{
    // printf("退出程序。\n");
    printf("%s%s[退出程序 ......]> \n%s", BOLD, YELLOW, RESET);
    exit(0);
}

void story()
{
    printf("%s%s[软件背后的故事 ......]> \n%s", BOLD, YELLOW, RESET);
    // printf("讲述软件背后的故事。\n");
}

void author_info()
{
    // printf("显示软件作者的相关信息。\n");
    printf("%s%s[作者信息 ......]> \n%s", BOLD, YELLOW, RESET);
}

void subject_intro()
{
    // printf("介绍学科的基本信息和内容范畴。\n");
    printf("%s%s[学科介绍 ......]> \n%s", BOLD, YELLOW, RESET);
}

void list_chapter(int chapter)
{
    // printf("列出第 %d 章的内容。\n", chapter);
    printf("%s%s[第 %d 章目录 ......]> \n%s", BOLD, YELLOW, chapter, RESET);
}
void set_language(char* language)
{
    if (strcmp(language,"chinese")== 0)
    {
        // printf("设置语言为中文。\n");
        printf("%s%s[设置语言为中文 ......]> \n%s", BOLD, YELLOW, RESET);
    }
    else if (strcmp(language,"english")== 0)
    {
        // printf("set to English.\n");
        printf("%s%s[set to English. ......]> \n%s", BOLD, YELLOW, RESET);
    }
}

void instruction_one_by_one()
{
    choose_language(); // 语言选择
    enter_help();      // 展示help页面的所有指令！
}

void guide()
{
    printf("%s%s[guide......]> %s\n", BOLD, PURPLE, RESET);
    instruction_one_by_one();
    printf("%s%s[guide......指引结束]> %s\n", BOLD, PURPLE, RESET);
}
