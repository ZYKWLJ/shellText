#include "../../include/search.h"
// 辅助函数：在单个库中搜索单词

int words_len(const char **single_lwords_set)
{
    int len = 0;
    while (single_lwords_set[len] != NULL)
    {
        len++;
    }
    return len;
}
int is_exist_in_single_library(const char ***single_library, char *str, int lib_index)
{
    // printf("%s%s来到%d库查询\n", RED, BOLD, lib_index);

    if (single_library == NULL)
    {
        return 0;
    }

    int total = 0;
    for (int i = 0; single_library[i] != NULL /*单个库的列表里面就是二维数组，直接用高亮函数*/; i++)
    {
        // 即时调用判存函数，有一个库有一个单词就返回1，否则返回0
        total += find_if_exist(single_library[i] /*这里是每一个库每一个开头单词集合，二维数组*/, words_len(single_library[i]) /*返回单个单词集的个数*/, str);
    }
    // printf("%s%s库%d查询到%d条结果\n", RED, BOLD, lib_index, total);
    // print
    return total; // 返回一个库的总匹配条数
}
int search_in_single_library(const char ***single_library, char *str, int lib_index)
{
    int total = is_exist_in_single_library(single_library, str, lib_index);
    if (!total)
    {
        printf("%s%s%d级库未查询到结果\n", RED, BOLD, lib_index);
    }
    else
    {
        printf("%s%s%d级库查询到%d条结果\n", RED, BOLD, lib_index, total);
    }

    for (int i = 0; single_library[i] != NULL /*单个库的列表里面就是二维数组，直接用高亮函数*/; i++)
    {
        // 即时调用 find_and_highlight 函数
        find_and_highlight(single_library[i] /*这里是每一个库每一个开头单词集合，二维数组*/, words_len(single_library[i]), str);
    }
    return total; // 返回单库的总匹配条数
}

// 查找特定单词,不管是前中后缀，都是相同的！搜出来就OK了！
int search_word(char *str, int library_index)
{

    if (library_index == 0)
    {
        return search_in_single_library(library[4], str, 4) + search_in_single_library(library[6], str, 6);
    }
    else if (library_index > 0 && library[library_index] != NULL)
    {
        return search_in_single_library(library[library_index], str, library_index);
    }
    return 0;
}
