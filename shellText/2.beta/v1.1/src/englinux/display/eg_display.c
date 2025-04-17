#include "../../../include/englinux/display/eg_display.h"
void eg_display(int lib_index, int match_mod, char *str, word_entry *word_list, int list_size, int firstcol_show, int secondcol_show, int thirdcol_show, int fourthcol_show)
{
    int lib = 0;
    if (lib_index == 4 || lib_index == 6)
    {
        lib = lib_index;
    }
    else
    {
        lib = lib_index == 0 ? 4 : 6;
    }
    // 显示单词表
    if (list_size != 0||!isAllChinese(str))
    {
        printf("查询%s%s%d级%s库--[%s%s%d条%s]\n", BLUE, BOLD, lib, RESET, BLUE, BOLD, list_size, RESET);
    }
    // 第一列显示什么，第二列显示什么，第三列显示什么？
    // 先看有几列，再看显示什么
    // int count = 0;
    // count += firstcol_show != 0;
    // count += secondcol_show != 0;
    // count += thirdcol_show != 0;
    // count += fourthcol_show != 0;
    // 将全部的单词信息存在一个三维数组中
    if (isAllChinese(str)) // 中文查询！全是包含高亮！
    {
        print_words(word_list, list_size, str, 3, firstcol_show, secondcol_show, thirdcol_show, fourthcol_show);
    }
    else // 英文查询！
    {
        switch (match_mod)
        {
        case 0:
            // 全部高亮显示
            print_words(word_list, list_size, str, 0, firstcol_show, secondcol_show, thirdcol_show, fourthcol_show);
            break;
        case 1:
            // 前缀高亮显示
            print_words(word_list, list_size, str, 1, firstcol_show, secondcol_show, thirdcol_show, fourthcol_show);

            break;
        case 2:
            // 后缀高亮显示
            print_words(word_list, list_size, str, 2, firstcol_show, secondcol_show, thirdcol_show, fourthcol_show);

            break;
        case 3:
            // 包含高亮显示
            print_words(word_list, list_size, str, 3, firstcol_show, secondcol_show, thirdcol_show, fourthcol_show);

            break;
        default:
            break;
        }
    }
}

// 四级库查询结果    500条
