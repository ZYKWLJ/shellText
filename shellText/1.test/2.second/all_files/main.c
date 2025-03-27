// 对流层ASCII
#define GREEN "\033[32m"//绿色专用于请输入指令提示信息
#define RED "\033[31m"//红色专用于错误提示信息
#define BLUE "\033[34m"//蓝色专用于章节名
#define PURPLE "\033[35m"//紫色专用于指引信息
#define YELLOW "\033[33m"//黄色专用于各个指令执行前缀！
#define RESET "\033[0m"
#define BOLD "\033[1m"//加粗
#define TROPOSPHERE_ASCII  \
"                           #            \n" \
"            ##      #     ####       ############# \n" \
" #######    ##      ## ##########    ##        ##  \n" \
" #   ##     ## #    ##    ##         ##        ##  \n" \
"  #  ## ########  #      ##  ##      ############  \n" \
"  #  ##     ##     #    ##    ##     ##        #   \n" \
"   # #  #   ##     ##  ##########    ##         #  \n" \
"   ###  ##  ##     ## # ## # # #     ## #########  \n" \
"    #    ## ##       #  ## # ##      ##          # \n" \
"   ###   ## ##       #  ## # ##      ############# \n" \
"   # ##  #  ##    # ##  ## # ##      ##   ## #     \n" \
"  ##  ##    ##     ##   ## # ##      ##  ##   #    \n" \
"  #   #     ##     ##   ## # ## #    #   ##   ##   \n" \
" #          ##     ### ##  # ## #   ##  ##     ##  \n" \
"          ####      ## #   # ####   #  ########### \n" \
"            #       # #    #  ##   #    #       #   \n\n"

#define COPYRIGHT_ASCII "TroposphereQuerySoftware Ver 1.0 Made by EthanYankang \
2025,03,25.\n    School of Physics,Xidian University.All rights reserved.\n\n"
#include<stdio.h>
#include <signal.h>
#include <stdlib.h>

// 定义包含ASCII艺术字的宏
#define ENDSAY \
"                        _   _                \n" \
"                       | | | |               \n" \
"   __ _  ___   ___   __| | | |__  _   _  ___ \n" \
"  / _` |/ _ \\ / _ \\ / _` | | '_ \\| | | |/ _ \\ \n" \
" | (_| | (_) | (_) | (_| | | |_) | |_| |  __/ \n" \
"  \\__, |\\___/ \\___/ \\__,_| |_.__/ \\__, |\\___| \n" \
"   __/ |                           __/ |     \n" \
"  |___/                           |___/      \n\n"

void exit_signal_handler(int signum);
// 打印函数声明
void acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep);
void copyright_print(const char *matched_machine, const char *author, int sleep_time, int interval_num_to_sleep);
void fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep);

// 徽标打印函数定义
void acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep)
{
    fast_Dynamic_input_green(define_str, sleep_time, interval_num_to_sleep);
}

// 版权打印函数定义
void print()
{
    // printf("\n\n\n");
    fast_Dynamic_input_green(TROPOSPHERE_ASCII, 1, 1);
    printf("\n\n\n");
    fast_Dynamic_input_green(COPYRIGHT_ASCII, 1, 1);
    printf("\n\n\n");
}

// 动态打印函数定义
void fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep)
{
    int len = strlen(input);

    for (size_t i = 0; i < len; ++i)
    {
        printf("%s%c%s", GREEN, input[i], RESET);
        fflush(stdout); // Ensure character is immediately printed
        if (i % interval_num_to_sleep == 0)
        {
            usleep(sleep_time * 100); // usleep 的单位是微秒，将毫秒转换为微秒
        }
    }
}


void eliminateSpace(char *str)
{
    int len = strlen(str);
    char *start = str;         // 首指针
    char *end = str + len - 1; // 尾指针

    // 去除首尾空格
    while (*start == ' ' && start < end)
    {
        start++;
    }
    while (*end == ' ' && start < end)
    {
        end--;
    }

    // 连续空格压缩
    char *slow = start; // 慢指针
    char *fast = slow;  // 快指针
                        // while (fast <= end) {
                        //     if (*fast == ' ' && *slow == ' ') {
                        //         fast++;
                        //     } else {
                        //         *slow = *fast;
                        //         slow++;
                        //         fast++;
                        //     }
                        // }
    while (fast <= end)//分组循环！
    {
        if (*fast == ' ')
        {
            // 当遇到空格时，保留一个空格
            *slow = *fast;
            slow++;
            // 跳过连续的空格
            while (*(fast + 1) == ' ' && fast + 1 <= end)
            {
                fast++;
            }
        }
        else
        {
            *slow = *fast;
            slow++;
        }
        fast++;
    }
    *slow = '\0';
    // printf("len(str)=%d\n", slow - start + 1);//调试长度正确吗？
    // 移动处理后的字符串到原字符串开头
    memmove(str, start, slow - start + 1); // 这里需要多复制一个\0

    // 全部转化为小写
    len = slow - start; // 更新字符串长度
    for (int i = 0; i < len; i++)
    {
        if (isupper((unsigned char)str[i]))
        {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
}

// #include "../../include/endSay.h"

// 信号处理函数
void exit_signal_handler(int signum) {
    if (signum == SIGINT) {
        // printf("\n这里将来会做告别语了~~~\n");
        printf("%s\n"ENDSAY);
        exit(0);
    }
}
// 测试函数！
// int main() {
//     // 注册信号处理函数
//     signal(SIGINT, signal_handler);

//     printf("程序正在运行，按 Ctrl + C 退出...\n");
//     while (1) {
//         // 程序持续运行
//         puts("i am running...");
//         sleep(1);
//     }

//     return 0;
// }
    
// #include "../../include/execute.h"

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
// #include "../../include/guide_must_enter.h"
// 在指引阶段必须要输入指令！因为演示效果所致！
int guide_must_enter(char **currentInstructionSet /*期望的指令集*/, char *currentFunction /*当前的功能*/)
{

    int ret = 0;
    // int flag = 1;
    while (1)
    {
        char enterInstruction[100];
        fgets(enterInstruction, sizeof(enterInstruction), stdin);
        printf("当前传进来的命令:%s\n", enterInstruction);
        if (strcmp(enterInstruction, "\n") == 0)
        {
            return 0; // 表示跳过当前指引步骤
        }

        size_t len = strlen(enterInstruction);
        if (len > 0 && enterInstruction[len - 1] == '\n')
        {
            enterInstruction[len - 1] = '\0';
        }
        eliminateSpace(enterInstruction); // 空格去除、连续空格压缩，并且全部转化为小写
        // printf("语法选择的命令为:%s\n", enterInstruction);调试信息，现在不用了！
        printf("修正后，当前传进来的命令:%s\n", enterInstruction);
        for (int i = 1; currentInstructionSet[i]; i++)
        {
            printf("当前指令集的命令为:%s\t比较的命令为%s\n", currentInstructionSet[i], enterInstruction); // 调试信息，现在不用了！
            if (strcmp(enterInstruction, currentInstructionSet[i]) == 0)
            {
                return i;
            }
        }
        
        puts("xxxxx错误命令");
        char *InstructionSetStr = (char *)malloc(sizeof(char) * 1000);
        for (int i = 0; currentInstructionSet[i]; i++)
        {
            InstructionSetStr = strcat(InstructionSetStr, "\t");
            InstructionSetStr = strcat(InstructionSetStr, currentInstructionSet[i]);
        }
        printf("%s%s[guide......%s]> %s 输入错误，请重新输入\n%s\n", BOLD, PURPLE, currentFunction, RESET, InstructionSetStr);
    }
    return ret;
}
// #include "../../../include/choose_language.h"
void choose_language()
{
    printf("%s%s[guide......语言选择]> %s 键入Chinese设置中文,键入English设置英文,键入回车跳过,键入exit退出指引\n", BOLD, PURPLE, RESET);
    char *chooseLanguage[4] = {"\n", "exit", "chinese", "english","\0"};
    // 指令预处理包含在里面了，只要返回0，1就是跳过或者退出！
    char *currentFunction = "语言选择";
    int ret = guide_must_enter(chooseLanguage, currentFunction);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 2:
        set_language(chooseLanguage[ret]);
        break;
    default:
        break;
    }
}

// #include "../../../include/enter_help.h"

void enter_help()
{
    printf("%s%s[guide......指令集]> %s 键入help获取指令表,键入回车跳过,键入exit退出指引\n", BOLD, PURPLE, RESET);
    // printf("%s%s[guide......help]> %s 键入help获取指令表,键入exit退出指引\n", BOLD, PURPLE, RESET);
   
    char *help_instructions_set[3] = {"\n", "exit","help","\0"};
    char* currentFunction = "指令集";
    int ret = guide_must_enter(help_instructions_set,currentFunction);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 2:
        help();//具体的指令实现
        break;
    default:
        break;
    }
}


// #include "../../include/instructionList.h"
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
void find()
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
int main()
{
    // 注册信号处理函数
    signal(SIGINT, exit_signal_handler);
    char str[100];
    print();
    while (1)
    {
        printf("%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
        // 去除 fgets 读取的换行符
        fgets(str, sizeof(str), stdin);
        if (strlen(str) == 1 && str[0] == '\n') // 直接不执行，继续读取
        {
            continue;
        }
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n')
        {
            str[len - 1] = '\0';
        }
        execute(str);
    }
    return 0;
}
