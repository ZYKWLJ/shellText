#include "../../include/search.h"
// 辅助函数：在单个库中搜索单词

// 单个单词集的长度！
int words_len(const char ***single_lwords_set)
{
    printf("进入了单个单词集的长度函数\n");
    int len = 0;
    while (single_lwords_set[len] != NULL)
    {
        len++;
    }

    printf("%s%s单词集个数为:%d%s\n", RED, BOLD, len,RESET);
    return len;
}
// 单个库的条数！
int is_exist_in_single_library(const char ****single_library, char *str, int lib_index,int search_mod)
{
    printf("%s%s来到%d库查询\n", RED, BOLD, lib_index);

    if (single_library == NULL)
    {
        return 0;
    }
    printf("1通过这里了\n");
    int total = 0;
    for (int i = 0; single_library[i] != NULL /*单个库的列表里面就是三维数组(含有释义音标等)，直接用高亮函数*/; i++)
    {
        // 即时调用判存函数，有一个库有一个单词就返回1，否则返回0
        total += find_if_exist(single_library[i] /*这里是每一个库每一个开头单词集合，三维数组*/, words_len(single_library[i]) /*返回单个单词集的个数*/, str, search_mod);
    }
    printf("2通过这里了\n");

    // printf("%s%s库%d查询到%d条结果\n", RED, BOLD, lib_index, total);
    // print
    return total; // 返回一个库的总匹配条数
}
// int search_in_single_library(const char ****single_library, char *str, int lib_index,int search_mod, int first_show, int second_show, int third_show)
// {
//     printf("查询%d级库\n", lib_index);
//     int total = is_exist_in_single_library(single_library, str, lib_index,search_mod);
//     if (!total)
//     {
//         printf("%s%s%d级库未查询到结果\n", RED, BOLD, lib_index);
//     }
//     else
//     {
//         printf("%s%s%d级库查询到%d条结果\n", BLUE, BOLD, lib_index, total);
//     }

//     for (int i = 0; single_library[i] != NULL /*单个库的列表里面就是二维数组，直接用高亮函数*/; i++)
//     {
//         printf("打印%s%s%d库%d条结果%s\n", BLUE, BOLD, lib_index, i, RESET);
//         // 即时调用 find_and_highlight 函数
//         find_and_highlight(single_library[i] /*这里是每一个库每一个开头单词集合，二维数组*/, words_len(single_library[i]), str, search_mod,first_show,second_show,third_show);
//     }
//     return total; // 返回单库的总匹配条数
// }

// 查找特定单词,不管是前中后缀，都是相同的！搜出来就OK了！
// int search_word(char *str, int library_index, int search_mod, int first_show, int second_show, int third_show)
// {
//     printf("%s%s查询单词:%s%s\n", BLUE, BOLD, str, RESET);

//     if (library_index == 0)
//     {
//         printf("%s%s查询所有词库\n", BLUE, BOLD);
//         return search_in_single_library(library[4], str, 4, search_mod,first_show,second_show,third_show) + search_in_single_library(library[6], str, 6,search_mod,first_show,second_show,third_show);
//     }
//     else if (library_index > 0 && library[library_index] != NULL)
//     {
//         printf("%s%s查询%d级词库\n", BLUE, BOLD, library_index);
//         return search_in_single_library(library[library_index], str, library_index,search_mod,first_show,second_show,third_show);
//     }
//     return 0;
// }

int search_in_single_library(const char ****library, const char *target, 
                            int lib_index, int search_mode,
                            int first_show, int second_show, int third_show) {
    // 参数检查
    if (library == NULL || library[lib_index] == NULL || target == NULL) {
        fprintf(stderr, "错误：无效的词库参数\n");
        return 0;
    }

    printf("\n正在搜索 %d 级词库...\n", lib_index);
    
    // 获取词库指针
    const char ***letter_tables = *library[lib_index];
    int total_matches = 0;

    // 遍历字母表
    for (int letter_idx = 0; letter_tables[letter_idx] != NULL; letter_idx++) {
        // 转换为正确的二维数组类型
        const char (*words)[3] = (const char (*)[3])letter_tables[letter_idx];
        
        // 计算当前字母表的单词数量
        int word_count = 0;
        while (words[word_count][0] != NULL) {
            word_count++;
        }

        // 在单个字母表中查找
        int matches = find_if_exist(letter_tables[letter_idx], word_count, target, search_mode);
        total_matches += matches;

        // 高亮显示匹配项
        if (matches > 0) {
            printf("\n在字母表 %c 中找到 %d 个匹配:\n", 'a' + letter_idx, matches);
            for (int i = 0; i < word_count; i++) {
                // 检查是否匹配
                int show = 0;
                const char *word = words[i][0];
                
                // 匹配逻辑（与find_if_exist相同）
                switch (search_mode) {
                case 1: show = (strcmp(word, target) == 0); break;
                case 2: show = (strstr(word, target) != NULL); break;
                case 3: show = (strncmp(word, target, strlen(target)) == 0); break;
                case 4: {
                    size_t len = strlen(target);
                    size_t wlen = strlen(word);
                    show = (wlen >= len) && (strcmp(word + wlen - len, target) == 0);
                    break;
                }
                }

                if (show) {
                    // 根据显示选项输出
                    if (first_show > 0) printf("%-20s", words[i][first_show-1]);
                    if (second_show > 0) printf("%-20s", words[i][second_show-1]);
                    if (third_show > 0) printf("%-20s", words[i][third_show-1]);
                    printf("\n");
                }
            }
        }
    }

    printf("\n在 %d 级词库中共找到 %d 个匹配\n", lib_index, total_matches);
    return total_matches;
}
int search_word(const char *target, int lib_index, int search_mode,
               int first_show, int second_show, int third_show) {
    // 参数检查
    if (target == NULL || *target == '\0') {
        fprintf(stderr, "错误：无效的搜索目标\n");
        return 0;
    }

    printf("\n=== 开始搜索 ===\n");
    printf("目标: %s\n模式: %d\n词库: %d\n显示: %d-%d-%d\n", 
          target, search_mode, lib_index, first_show, second_show, third_show);

    int total = 0;
    
    if (lib_index == 0) {
        // 搜索所有词库
        total += search_in_single_library(library, target, 4, search_mode, 
                                        first_show, second_show, third_show);
        total += search_in_single_library(library, target, 6, search_mode,
                                        first_show, second_show, third_show);
    } 
    else if (lib_index == 4 || lib_index == 6) {
        // 搜索指定词库
        total = search_in_single_library(library, target, lib_index, search_mode,
                                       first_show, second_show, third_show);
    }
    else {
        fprintf(stderr, "错误：无效的词库索引 %d\n", lib_index);
        return 0;
    }

    printf("\n=== 搜索完成 ===\n");
    printf("总计找到 %d 个匹配项\n", total);
    return total;
}