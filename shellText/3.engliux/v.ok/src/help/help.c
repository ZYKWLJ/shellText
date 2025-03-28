# include "../../include/help.h"
void help_list()
{
    printf("%s%s<<[........指令表.......]>> \n\n%s", BOLD, GREEN, RESET);
    printf("%s%s[通用指令] \n%s", BOLD, BLUE, RESET);
    printf("%s%s[help...........展示全部指令] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[clear.................清屏] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[exit...............退出程序] \n\n%s", BOLD, YELLOW, RESET);

    printf("%s%s[查找指令] \n%s", BOLD, BLUE, RESET);
    printf("%s%s[find text............查找指定单词text] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[find text%%..........查找以text为前缀的单词] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[find %%text..........查找以text为后缀的单词] \n%s", BOLD, YELLOW, RESET);
    printf("%s%s[find %%text%%........查找包含text的单词] \n\n%s", BOLD, YELLOW, RESET);
    printf("%s%s[find可简写为f] \n\n%s", BOLD, YELLOW, RESET);
}