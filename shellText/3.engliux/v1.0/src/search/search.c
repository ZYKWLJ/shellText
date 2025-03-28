#include "../../include/search.h"

// 计算单个单词集的长度
int words_len(const char **word_set)
{
    if (word_set == NULL)
        return 0;

    int len = 0;
    while (word_set[len] != NULL)
    {
        len++;
    }
    return len;
}
// // 单个库的条数！
// // 单个库的条数！
// int is_exist_in_single_library(const char ****single_library, char *str, int lib_index, int search_mod)
// {
//     printf("%s%s来到%d库查询\n", RED, BOLD, lib_index);

//     if (single_library == NULL)
//     {
//         return 0;
//     }
//     printf("1通过这里了\n");
//     int total = 0;
//     for (int i = 0; single_library[i] != NULL; i++)
//     {
//         // 正确解引用指针：single_library[i]是三级指针，我们需要传递二级指针
//         total += find_if_exist(*single_library[i],  // 解引用一次得到二级指针
//                              words_len(*single_library[i]),
//                              str,
//                              search_mod);
//     }
//     printf("2通过这里了\n");
//     return total;
// }

// int search_in_single_library(const char ****single_library, char *str, int lib_index, int search_mod,
//                             int first_show, int second_show, int third_show)
// {
//     printf("查询%d级库\n", lib_index);
//     int total = is_exist_in_single_library(single_library, str, lib_index, search_mod);
//     if (!total)
//     {
//         printf("%s%s%d级库未查询到结果\n", RED, BOLD, lib_index);
//     }
//     else
//     {
//         printf("%s%s%d级库查询到%d条结果\n", BLUE, BOLD, lib_index, total);
//     }

//     for (int i = 0; single_library[i] != NULL; i++)
//     {
//         printf("打印%s%s%d库%d条结果%s\n", BLUE, BOLD, lib_index, i, RESET);
//         // 同样需要解引用指针
//         find_and_highlight(*single_library[i],
//                           words_len(*single_library[i]),
//                           str,
//                           search_mod,
//                           first_show,
//                           second_show,
//                           third_show);
//     }
//     return total;
// }

// 搜索函数
int search_word(const char *target, int lib_index, int mode,
                int col1, int col2, int col3)
{
    if (!target || !*target)
        return 0;

    if (lib_index == 0)
    { // 搜索所有库
        int count = 0;
        for (int i = 4; i <= 6; i += 2)
        {
            if (library[i])
            {
                // printf("查询%d级库:\n", i);
                const char ***lib = library[i];
                for (int j = 0; lib[j]; j++)
                {
                    const char **words = lib[j];
                    int len = words_len(words);
                    count += find_if_exist(words, len, target, mode);
                    printf("%d级库查询到%s%s%d%s条结果\n", i, BLUE, BOLD, count, RESET);
                    find_and_highlight(words, len, target, mode, col1, col2, col3);
                }
            }
        }
        return count;
    }
    else if (lib_index == 4 || lib_index == 6)
    {
        if (!library[lib_index])
            return 0;
        printf("查询%d级库:\n", lib_index);

        int count = 0;
        const char ***lib = library[lib_index];
        for (int j = 0; lib[j]; j++)
        {
            const char **words = lib[j];
            int len = words_len(words);
            count += find_if_exist(words, len, target, mode);
            printf("%d级库查询到%s%s%d%s条结果\n", lib_index, BLUE, BOLD, count, RESET);
            find_and_highlight(words, len, target, mode, col1, col2, col3);
        }
        return count;
    }
    return 0;
}
