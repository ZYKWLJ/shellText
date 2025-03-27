// 对流层ASCII
#define GREEN "\033[32m"  // 绿色专用于请输入指令提示信息
#define RED "\033[31m"    // 红色专用于错误提示信息
#define BLUE "\033[34m"   // 蓝色专用于章节名
#define PURPLE "\033[35m" // 紫色专用于指引信息
#define YELLOW "\033[33m" // 黄色专用于各个指令执行前缀！
#define RESET "\033[0m"
#define BOLD "\033[1m" // 加粗

#define TROPOSPHERE_ASCII                                   \
    "                           #            \n"            \
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

// 定义包含ASCII艺术字的宏
#define ENDSAY                                               \
    "                        _   _                \n"        \
    "                       | | | |               \n"        \
    "   __ _  ___   ___   __| | | |__  _   _  ___ \n"        \
    "  / _` |/ _ \\ / _ \\ / _` | | '_ \\| | | |/ _ \\ \n"   \
    " | (_| | (_) | (_) | (_| | | |_) | |_| |  __/ \n"       \
    "  \\__, |\\___/ \\___/ \\__,_| |_.__/ \\__, |\\___| \n" \
    "   __/ |                           __/ |     \n"        \
    "  |___/                           |___/      \n\n"

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// 函数声明
void exit_signal_handler(int signum);
void acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep);
void copyright_print(const char *matched_machine, const char *author, int sleep_time, int interval_num_to_sleep);
void fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep);
void eliminateSpace(char *str);
void print();
void help();
void list();
void find();
void clear_screen();
void exit_program();
void story();
void author_info();
void subject_intro();
void list_chapter(int chapter);
void set_language(char *language);
void instruction_one_by_one();
void guide();
int isValidInstruction(char *str);
void executeInstruction(int Instruction_index);
void execute(char *str);
int guide_must_enter(char **currentInstructionSet, char *currentFunction, char *prompt);
void choose_language();
void enter_help();

// 全局指令数组
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

// 信号处理函数
void exit_signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        printf("%s%s\n%s\n%s", BOLD,GREEN,ENDSAY,RESET);
        exit(0);
    }
}

// 徽标打印函数定义
void acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep)
{
    fast_Dynamic_input_green(define_str, sleep_time, interval_num_to_sleep);
}

// 版权打印函数定义
void print()
{
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
        fflush(stdout);
        if (i % interval_num_to_sleep == 0)
        {
            usleep(sleep_time * 100);
        }
    }
}

void eliminateSpace(char *str)
{
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

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
    char *slow = start;
    char *fast = slow;

    while (fast <= end)
    {
        if (*fast == ' ')
        {
            *slow = *fast;
            slow++;
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

    memmove(str, start, slow - start + 1);

    // 全部转化为小写
    len = slow - start;
    for (int i = 0; i < len; i++)
    {
        if (isupper((unsigned char)str[i]))
        {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
}

int isValidInstruction(char *str)
{
    eliminateSpace(str);
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
        executeInstruction(Instruction_index);
    }
    else
    {
        printf("%s%s%s--无效指令！%s(按下%s%shelp%s可以获取帮助)\n",
               BOLD, RED, str, RESET, BOLD, YELLOW, RESET);
    }
}

int guide_must_enter(char **currentInstructionSet, char *currentFunction, char *prompt)
{
    while (1)
    {
        printf("%s", prompt);
        char enterInstruction[100] = {0}; // 初始化为全0
        if (!fgets(enterInstruction, sizeof(enterInstruction), stdin))
        {
            return 0; // 读取失败时返回
        }

        // printf("当前传进来的命令:%s\n", enterInstruction);

        // 处理空输入或换行符
        if (strcmp(enterInstruction, "\n") == 0)
        {
            return 0;
        }

        // 移除末尾的换行符
        size_t len = strlen(enterInstruction);
        if (len > 0 && enterInstruction[len - 1] == '\n')
        {
            enterInstruction[len - 1] = '\0';
        }

        eliminateSpace(enterInstruction);
        // printf("修正后，当前传进来的命令:%s\n", enterInstruction);

        // 检查指令是否在允许的指令集中
        for (int i = 1; currentInstructionSet[i] != "NULL"; i++)
        {
            // printf("当前指令集的命令为:%s\t比较的命令为%s\n",currentInstructionSet[i], enterInstruction);
            if (strcmp(enterInstruction, currentInstructionSet[i]) == 0)
            {
                printf("匹配成功:%s\n", currentInstructionSet[i]);
                return i;
            }
        }
        printf("%s%s输入错误,请重新输入:%s\n", BOLD, RED, RESET);
    }
}
// void prompt(char **currentInstructionSet, char *currentFunction,char *prompt)
// {

// }
void choose_language()
{
    char *chooseLanguage[5] = {"\n", "exit", "chinese", "english", "NULL" /*标志位*/};
    char *currentFunction = "语言选择";
    char prompt[200];
    snprintf(prompt, sizeof(prompt), "%s%s[guide......%s]> %s 键入%sChinese%s设置中文,键入%sEnglish%s设置英文,键入%s回车%s跳过,键入%sexit%s退出指引\n",
             BOLD, PURPLE, currentFunction, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET, YELLOW, RESET);
    // printf("%s%s[guide......语言选择]> %s 键入Chinese设置中文,键入English设置英文,键入回车跳过,键入exit退出指引\n",
    //       BOLD, PURPLE, RESET);

    int ret = guide_must_enter(chooseLanguage, currentFunction, prompt);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    default:
        set_language(chooseLanguage[ret]);
        break;
    }
}

void enter_help()
{

    char prompt[150];
    snprintf(prompt, sizeof(prompt), "%s%s[guide......指令集]> %s 键入help获取指令表,键入回车跳过,键入exit退出指引\n",
             BOLD, PURPLE, RESET);
    char *help_instructions_set[4] = {"\n", "exit", "help", "NULL"};
    char *currentFunction = "指令集";
    int ret = guide_must_enter(help_instructions_set, currentFunction, prompt);
    switch (ret)
    {
    case 0:
        printf("%s%s[跳过当前指引步骤......]> %s\n", BOLD, PURPLE, RESET);
        break;
    case 1:
        printf("%s%s[退出指引程序......]> %s\n", BOLD, PURPLE, RESET);
        break;
    default:
        help();
        break;
    }
}

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
    printf("%s%s[目录 ......]> \n%s", BOLD, YELLOW, RESET);
}

void find()
{
    printf("%s%s[查找知识点 ......]> \n%s", BOLD, YELLOW, RESET);
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
    printf("%s%s[退出程序 ......]> \n%s", BOLD, YELLOW, RESET);
    exit(0);
}

void story()
{
    printf("%s%s[软件背后的故事 ......]> \n%s", BOLD, YELLOW, RESET);
}

void author_info()
{
    printf("%s%s[作者信息 ......]> \n%s", BOLD, YELLOW, RESET);
}

void subject_intro()
{
    printf("%s%s[学科介绍 ......]> \n%s", BOLD, YELLOW, RESET);
}

void list_chapter(int chapter)
{
    printf("%s%s[第 %d 章目录 ......]> \n%s", BOLD, YELLOW, chapter, RESET);
}

void set_language(char *language)
{
    if (strcmp(language, "chinese") == 0)
    {
        printf("%s%s[设置语言为中文 ......]> \n%s", BOLD, YELLOW, RESET);
    }
    else if (strcmp(language, "english") == 0)
    {
        printf("%s%s[set to English. ......]> \n%s", BOLD, YELLOW, RESET);
    }
}

void instruction_one_by_one()
{
    choose_language();
    enter_help();
}

void guide()
{
    printf("%s%s[guide......]> %s\n", BOLD, PURPLE, RESET);
    instruction_one_by_one();
    printf("%s%s[guide......指引结束]> %s\n", BOLD, PURPLE, RESET);
}

int main()
{
    signal(SIGINT, exit_signal_handler);
    char str[100];
    print();

    while (1)
    {
        printf("%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
        fgets(str, sizeof(str), stdin);
        if (strlen(str) == 1 && str[0] == '\n')
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