#include "../../../include/englinux/execute/eg_execute_four_token.h"
void execute_four_token(char *token[], int token_num, char *origin_str)
{
    if (!parser_first_token(token[0], origin_str))
        return;
    int library_index = 0;                                        // 超找的词库
    int find_mod = 0;                                             // 查找的模式
    char *word = (char *)malloc(sizeof(char) * strlen(token[1])); // 查找的单词
    // 解析第二个token！
    char *subquerys[1024];
    if (parser_second_token(token[1], origin_str, &find_mod, word, subquerys) == 2)
    {
        if (!parser_third_token(token[2], origin_str, &library_index))
            return;
        // 查询每一个中文子串！
        for (int i = 0; subquerys[i]; i++)
        {
            // 存放4、6级查到的单词块！
            word_entry *result = (word_entry *)malloc(sizeof(word_entry) * 5000);
            // int *result_size = 0;
            int firstcol_show = 1;
            int secondcol_show = 1;
            int thirdcol_show = 1;
            int fourthcol_show = 1;
            if (!parser_fourth_token(token[3], origin_str, &firstcol_show, &secondcol_show, &thirdcol_show, &fourthcol_show))
                return;
            int result_size = 0;
            // printf("word:%s\n", word);
            eg_find(subquerys[i], library_index, find_mod, result, &result_size);
            eg_display(library_index, find_mod, subquerys[i], result, result_size, firstcol_show, secondcol_show, thirdcol_show, fourthcol_show);
            // free(result);
        }
    }
    // 只查询英文
    else if (parser_second_token(token[1], origin_str, &find_mod, word, subquerys) == 1)
    {
        if (!parser_third_token(token[2], origin_str, &library_index))
            return;
        // 存放4、6级查到的单词块！
        word_entry *result = (word_entry *)malloc(sizeof(word_entry) * 5000);
        // int *result_size = 0;
        int firstcol_show = 1;
        int secondcol_show = 1;
        int thirdcol_show = 1;
        int fourthcol_show = 1;
        if (!parser_fourth_token(token[3], origin_str, &firstcol_show, &secondcol_show, &thirdcol_show, &fourthcol_show))
            return;
        int result_size = 0;
        // printf("word:%s\n", word);
        eg_find(word, library_index, find_mod, result, &result_size);
        eg_display(library_index, find_mod, word, result, result_size, firstcol_show, secondcol_show, thirdcol_show, fourthcol_show);
    }
    else
    {
        return;
    }
}