# include "../../../include/englinux/execute/eg_match.h"
int find_exact(const char *str, int library_index, word_entry *result)
{
    int count=0;
    for (int i = 0; library[library_index][i] != NULL; i++)
    {
        for (int j = 0; library[library_index][i][j].index != NULL; j++)
        {
            if (strcmp(library[library_index][i][j].word, str) == 0)
            {
                count++;
                // printf("单词%s匹配成功\n", library[library_index][i][j].word);
                result->index = library[library_index][i][j].index;
                result->word = library[library_index][i][j].word;
                result->phonetic = library[library_index][i][j].phonetic;
                result->meaning = library[library_index][i][j].meaning;
                result++;
            }
        }
    }
    result = NULL; // 结尾标记！
    return count;
}

//  前缀匹配函数
int prefix_match(const char *str, const char *prefix)
{
    // 提前计算 prefix 的长度
    size_t prefix_len = strlen(prefix);
    // 提前计算 str 的长度
    size_t str_len = strlen(str);

    // 如果 str 的长度小于 prefix 的长度，直接返回 0
    if (str_len < prefix_len)
    {
        return 0;
    }

    // 遍历 prefix 中的每个字符进行匹配
    for (size_t i = 0; i < prefix_len; i++)
    {
        if (str[i] != prefix[i])
        {
            return 0;
        }
    }

    return 1;
}

// 前缀查找单词
int find_prefix(const char *str, int library_index, word_entry *result)
{
    int count=0;

    for (int i = 0; library[library_index][i] != NULL; i++)
    {
        for (int j = 0; library[library_index][i][j].index != NULL; j++)
        {
            if (prefix_match(library[library_index][i][j].word, str))
            {
                count++;
                // printf("单词%s匹配成功\n", library[library_index][i][j].word);

                result->index = library[library_index][i][j].index;
                result->word = library[library_index][i][j].word;
                result->phonetic = library[library_index][i][j].phonetic;
                result->meaning = library[library_index][i][j].meaning;
                result++;
            }
        }
    }
    result = NULL; // 结尾标记！
    return count++;
}

// 后缀匹配
int suffix_match(const char *str,const  char *suffix)
{
    size_t str_len = strlen(str);
    size_t suffix_len = strlen(suffix);

    // 若 str 的长度小于 suffix 的长度，直接返回 0
    if (str_len < suffix_len)
    {
        return 0;
    }

    size_t offset = str_len - suffix_len;
    for (size_t i = 0; i < suffix_len; i++)
    {
        if (str[offset + i] != suffix[i])
        {
            return 0;
        }
    }
    return 1;
}

// 后缀查找单词
int find_suffix(const char *str, int library_index, word_entry *result)
{
    int count=0;

    for (int i = 0; library[library_index][i] != NULL; i++)
    {
        for (int j = 0; library[library_index][i][j].index != NULL; j++)
        {
            if (suffix_match(library[library_index][i][j].word, str))
            {
                count++;
                // printf("单词%s匹配成功\n", library[library_index][i][j].word);

                result->index = library[library_index][i][j].index;
                result->word = library[library_index][i][j].word;
                result->phonetic = library[library_index][i][j].phonetic;
                result->meaning = library[library_index][i][j].meaning;
                result++;
            }
        }
    }
    result = NULL; // 结尾标记！
    return count;
}

// 包含匹配函数
int contains_match(const char *str,const char *sub_str)
{
    size_t str_len = strlen(str);
    size_t sub_str_len = strlen(sub_str);

    // 如果子字符串长度为 0，认为包含
    if (sub_str_len == 0)
    {
        return 1;
    }

    // 如果原字符串长度小于子字符串长度，不包含
    if (str_len < sub_str_len)
    {
        return 0;
    }

    // 外层循环遍历原字符串
    for (size_t i = 0; i <= str_len - sub_str_len; i++)
    {
        size_t j;
        // 内层循环比较子字符串
        for (j = 0; j < sub_str_len; j++)
        {
            if (str[i + j] != sub_str[j])
            {
                break;
            }
        }
        // 如果内层循环正常结束，说明找到了匹配的子字符串
        if (j == sub_str_len)
        {
            return 1;
        }
    }

    return 0;
}

int find_contain(const char *str, int library_index, word_entry *result)
{
    int count=0;
    for (int i = 0; library[library_index][i] != NULL; i++)
    {
        for (int j = 0; library[library_index][i][j].index != NULL; j++)
        {
            if (contains_match(library[library_index][i][j].word, str))
            {
                count++;
                // printf("单词%s匹配成功\n", library[library_index][i][j].word);

                result->index = library[library_index][i][j].index;
                result->word = library[library_index][i][j].word;
                result->phonetic = library[library_index][i][j].phonetic;
                result->meaning = library[library_index][i][j].meaning;
                result++;
            }
        }
    }
    result = NULL; // 结尾标记！
    return count;
}


int find_contain_chinese(const char *str, int library_index, word_entry *result)
{
    int count=0;
    for (int i = 0; library[library_index][i] != NULL; i++)
    {
        for (int j = 0; library[library_index][i][j].index != NULL; j++)
        {
            if (contains_match(library[library_index][i][j].meaning, str))//这里变成比较释义了！
            {
                count++;
                // printf("单词%s匹配成功\n", library[library_index][i][j].word);
                result->index = library[library_index][i][j].index;
                result->word = library[library_index][i][j].word;
                result->phonetic = library[library_index][i][j].phonetic;
                result->meaning = library[library_index][i][j].meaning;
                result++;
            }
        }
    }
    result = NULL; // 结尾标记！
    return count;
}