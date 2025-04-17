#include "../../../include/shellText/text_instructionList.h"
void text_help()
{
    help_list();
}

void list()
{
    // printf("%s%s[contents ......]> \n%s",BOLD,YELLOW,RESET);
    printf("%s%s[目录 ......]> \n%s", BOLD, YELLOW, RESET);
    display_chapters(0);
}
// 函数用于获取除第一个单词外的剩余字符，给find函数使用！
void get_remaining_chars(char *input, char *output)
{
    // 找到第一个空格的位置
    char *first_space = strchr(input, ' ');
    if (first_space != NULL)
    {
        // 跳过空格
        first_space++;
        // 将剩余字符复制到输出字符串
        strcpy(output, first_space);
    }
    else
    {
        // 如果没有空格，输出空字符串
        output[0] = '\0';
    }
}

void text_find(char *str)
{
    // printf("%s%s[查找知识点 ......]> \n%s", BOLD, YELLOW, RESET);
    // printf("查找特定的知识点。\n");
    int size = 0;
    for (int i = 0; strcmp(all_pages[i], "NULL"); i++)
    {
        size++;
        // printf("size:%d\n",size);
    }
    // printf("这一步开始查找size:%d\n",size);
    // 为 output 分配内存
    char *output = (char *)malloc(1024); // 假设最大长度为 1024
    if (output == NULL)
    {
        fprintf(stderr, "内存分配失败\n");
        return;
    }
    // printf("%s%s待查找内容为text: %s%s", BOLD, YELLOW, output, RESET);
    get_remaining_chars(str, output);
    // printf("%s%s待查找内容为text: %s%s", BOLD, YELLOW, output, RESET);
    if (!find_and_highlight(all_pages, size, output))
    {
        printf("%s%s暂无与%s相关知识点\n%s", BOLD, RED, output, RESET);
    }
    free(output);
    // 这里也需要将find命令一分为二！先在前面判断出，后面再进行查找！
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
    printf("%s%s[退出程序 ......]> 感谢您的使用!\n%s", BOLD, YELLOW, RESET);
    printf(ENDSAY);
    exit(0);
}

void story()
{
    printf("%s%s[软件背后的故事 ......]> \n%s", BOLD, YELLOW, RESET);
    printf(STORY);
    // printf("讲述软件背后的故事。\n");
}

void author_info()
{
    // printf("显示软件作者的相关信息。\n");
    printf("%s%s[作者信息 ......]> \n%s", BOLD, YELLOW, RESET);
    printf(AUTHOR);
}

void subject_intro()
{
    // printf("介绍学科的基本信息和内容范畴。\n");
    printf("%s%s[学科介绍 ......]> \n%s", BOLD, YELLOW, RESET);
    printf(SUBJECT);
}

void list_chapter(int chapter)
{
    // printf("列出第 %d 章的内容。\n", chapter);
    printf("%s%s[第 %d 章目录 ......]> \n%s", BOLD, YELLOW, chapter, RESET);
    // printf("www.baidu.com\n");
    // printf("图像在CSDN里面，文字在本软件里面。\n");
    display_chapters(chapter);
}
void set_language(char *language)
{
    if (strcmp(language, "chinese") == 0)
    {
        // printf("设置语言为中文。\n");
        printf("%s%s[设置语言为中文 ......]> \n%s", BOLD, YELLOW, RESET);
    }
    else if (strcmp(language, "english") == 0)
    {
        // printf("set to English.\n");
        printf("%s%s[set to English. ......]> \n%s", BOLD, YELLOW, RESET);
    }
}

// void instruction_one_by_one()
// {
//     choose_language(); // 语言选择
//     enter_help();      // 展示help页面的所有指令！
// }

// void guide()
// {
//     printf("%s%s[guide......]> %s\n", BOLD, PURPLE, RESET);
//     instruction_one_by_one();
//     printf("%s%s[guide......指引结束]> %s\n", BOLD, PURPLE, RESET);
// }
