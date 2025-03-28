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
                const char ***lib = library[i];//三维数组！四六级库！a-z所有数据
                for (int j = 0; lib[j]/*这是以某个单词开头的集合*/; j++)//二维数组，即每一条数据！
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
        for (int j = 0; lib[j]; j++)//三维数组的遍历！就是一个分库——四六级库！这是一个二维数组！即每一条数据！
        {
            const char **words = lib[j];
            int len = words_len(words);
            // 这里先查询到所有匹配的元素条数了！因为方便提前显示！
            count += find_if_exist(words, len, target, mode);
            printf("%d级库查询到%s%s%d%s条结果\n", lib_index, BLUE, BOLD, count, RESET);
            find_and_highlight(words, len, target, mode, col1, col2, col3);
        }
        return count;
    }
    return 0;
}
