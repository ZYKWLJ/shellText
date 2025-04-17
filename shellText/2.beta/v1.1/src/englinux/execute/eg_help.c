#include "../../../include/englinux/execute/eg_help.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

// 定义指令名称
const char *cmd = "指令";

const char *help_cmd = "help";
const char *exit_cmd = "exit";
const char *clear_cmd = "clear";
// const char *story_cmd = "story";
const char *author_cmd = "author";
const char *find_cmd = "find|f word";

// 定义指令对应的说明
const char *description = "指令功能";
const char *help_description = "查看指令表";
const char *exit_description = "退出程序";
const char *clear_description = "清空屏幕";
// const char *story_description = "软件故事";
const char *author_description = "作者信息";
const char *find_description = "搜索单词";

void eg_help()
{
    const char *cmds[] = {cmd, help_cmd, exit_cmd, clear_cmd,  author_cmd, find_cmd, NULL};
    const char *descriptions[] = {description, help_description, exit_description, clear_description, 
    author_description, find_description, NULL};
    const char **columns[] = {cmds, descriptions};
    eg_print_help(columns, sizeof(columns) / sizeof(columns[0]));
}


// int main()
// {
//     help();
//     return 0;
// }