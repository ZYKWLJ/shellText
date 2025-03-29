#include "../../include/search.h"
// 辅助函数：在单个库中搜索单词

// 单个单词集的长度！
int words_len(word_entry **single_library)
{
    printf("进入了单个单词集的长度函数\n");
    int len = 0;
    while (single_library[len])
    {
        len++;
    }
    printf("%s%s单词集个数为:%d%s\n", RED, BOLD, len, RESET);
    return len;
}
// 单个库的条数！
int is_exist_in_single_library(word_entry ***single_library/*单个四六级库*/, char *str, int lib_index, int search_mod)
{
    printf("%s%s来到%d库查询\n", RED, BOLD, lib_index);

    if (single_library == NULL)
    {
        return 0;
    }
    printf("1通过这里了\n");
    int total = 0;
    for (int i = 0; single_library[i] != NULL /*以字母开头的单词集合*/; i++)
    {
        // 即时调用判存函数，有一个库有一个单词就返回1，否则返回0
        total += find_if_exist(single_library[i] /*这里是每一个库每一个开头单词集合*/, words_len(single_library[i]) /*返回单个单词集的个数*/, str, search_mod);
    }
    printf("2通过这里了\n");
    return total; // 返回一个库的总匹配条数
}
void search_in_single_library(word_entry ***single_library, char *str, int lib_index, int search_mod, int first_show, int second_show, int third_show)
{
    printf("查询%d级库\n", lib_index);
    int total = is_exist_in_single_library(single_library, str, lib_index, search_mod);
    if (!total)
    {
        printf("%s%s%d级库未查询到结果\n", RED, BOLD, lib_index);
    }
    else
    {
        printf("%s%s%d级库查询到%d条结果\n", BLUE, BOLD, lib_index, total);
    }

    for (int i = 0; single_library[i] != NULL /*单个库的列表里面就是二维数组，直接用高亮函数*/; i++)
    {
        printf("打印%s%s%d库%d条结果%s\n", BLUE, BOLD, lib_index, i, RESET);
        // 即时调用 find_and_highlight 函数
        find_and_highlight(single_library[i] /*这里是每一个库每一个开头单词集合，二维数组*/, words_len(single_library[i]), str, search_mod, first_show, second_show, third_show);
    }
}

// 查找特定单词,不管是前中后缀，都是相同的！搜出来就OK了！
void search_word(char *str, int library_index, int search_mod, int first_show, int second_show, int third_show)
{
    printf("%s%s查询单词:%s%s\n", BLUE, BOLD, str, RESET);

    if (library_index == 0)
    {
        printf("%s%s查询所有词库\n", BLUE, BOLD);
        search_in_single_library(library[0], str, 0, search_mod, first_show, second_show, third_show);
        search_in_single_library(library[1], str, 1, search_mod, first_show, second_show, third_show);
    }
    else if (library_index > 0)
    {
        library_index==4?0:1;//只有两个库！
        printf("%s%s查询%d级词库\n", BLUE, BOLD, library_index);
        search_in_single_library(library[library_index], str, library_index, search_mod, first_show, second_show, third_show);
    }
    return;
}
