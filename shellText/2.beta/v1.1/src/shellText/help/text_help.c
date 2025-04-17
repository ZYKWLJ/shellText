# include "../../../include/shellText/text_help.h"
void help_list()
{
    printf("%s%s<<[........指令表.......]>> \n%s", BOLD, GREEN, RESET);
    // printf("%s%s[guide........新手手把手教学] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[help...........展示全部指令] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list...........列出所有章节] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[clear.................清屏] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[exit...............退出程序] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[story..............软件故事] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[author.............作者信息] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[subject............学科介绍] \n%s", BOLD, YELLOW, RESET);
    // printf("%s%s[chinese.......设置语言为中文] \n%s", BOLD, YELLOW, RESET);
    // printf("%s%s[english.......设置语言为英文] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 1 ls 1......列出第一章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 2/ls 2......列出第二章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 3/ls 3......列出第三章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 4/ls 4......列出第四章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 5/ls 5......列出第五章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 6/ls 6......列出第六章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 7/ls 7......列出第七章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 8/ls 8......列出第八章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[list 9/ls 9......列出第九章] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[find text/f text............查找知识点] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[page num/p num............查找页面内容] \n%s", BOLD, YELLOW, RESET);
}