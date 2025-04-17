#include "../../../include/englinux/display/eg_print_words.h"
// 计算字符串的显示宽度（中文算2，英文算1）

int display_width_words(const char *str)
{
    if (str == NULL)
        return 0;

    setlocale(LC_ALL, "en_US.utf8"); // 确保宽字符处理正确
    mbstate_t state = {0};
    const char *ptr = str;
    size_t bytes;
    wchar_t wc;
    int width = 0;

    while ((bytes = mbrtowc(&wc, ptr, MB_CUR_MAX, &state)) > 0)
    {
        if (bytes == (size_t)-1 || bytes == (size_t)-2)
        {
            // 非法UTF-8序列，按单字节处理
            width += 1;
            ptr += 1;
            continue;
        }
        #include <wchar.h> // 再次明确包含
        // 判断字符宽度
        int char_width = wcwidth(wc);
        if (char_width < 0)
        {
            // 控制字符等，按0宽度处理
            char_width = 0;
        }
        width += char_width;
        ptr += bytes;
    }

    return width;
}
// 打印固定宽度的字符串，考虑中文字符和高亮
void print_padded_words(const char *str, int width, const char *highlight_start, const char *highlight_end)
{
    if (str == NULL)
        str = "";

    if (highlight_start == NULL || highlight_end == NULL)
    {
        // 没有高亮部分
        int str_width = display_width_words(str);
        printf("%s", str);
        for (int i = str_width; i < width; i++)
        {
            printf(" ");
        }
    }
    else
    {
        // 有高亮部分
        const char *ptr = str;
        int printed_width = 0;

        while (*ptr)
        {
            if (ptr == highlight_start)
            {
                printf(RED);
            }

            if ((unsigned char)*ptr >= 0x80)
            {                        // 中文字符
                printf("%.3s", ptr); // 打印UTF-8中文字符
                printed_width += 2;
                ptr += 3;
            }
            else
            {
                printf("%c", *ptr);
                printed_width += 1;
                ptr += 1;
            }

            if (ptr == highlight_end)
            {
                printf(RESET);
            }
        }

        for (int i = printed_width; i < width; i++)
        {
            printf(" ");
        }
    }
}

// 获取高亮部分的起始和结束位置
void get_highlight_positions(const char *word, const char *search_str, int match_mod,
                             const char **highlight_start, const char **highlight_end)
{
    *highlight_start = NULL;
    *highlight_end = NULL;

    if (word == NULL || search_str == NULL || strlen(search_str) == 0)
    {
        return;
    }

    if (isAllChinese(search_str))
    {
        // 中文查询全是包含查询
        const char *match_pos = strstr(word, search_str);
        if (match_pos != NULL)
        {
            *highlight_start = match_pos;
            *highlight_end = match_pos + strlen(search_str);
        }
    }
    else
    {
        // 英文查询！
        size_t search_len = strlen(search_str);

        switch (match_mod)
        {
        case 0: // 精确匹配
            if (strcmp(word, search_str) == 0)
            {
                *highlight_start = word;
                *highlight_end = word + strlen(word);
            }
            break;
        case 1: // 前缀匹配
            if (strncmp(word, search_str, search_len) == 0)
            {
                *highlight_start = word;
                *highlight_end = word + search_len;
            }
            break;
        case 2: // 后缀匹配
            if (strlen(word) >= search_len &&
                strcmp(word + strlen(word) - search_len, search_str) == 0)
            {
                *highlight_start = word + strlen(word) - search_len;
                *highlight_end = word + strlen(word);
            }
            break;
        case 3: // 包含
            const char *match_pos = strstr(word, search_str);
            if (match_pos != NULL)
            {
                *highlight_start = match_pos;
                *highlight_end = match_pos + search_len;
            }
            break;
        default:
            // 处理非法的 match_mod
            fprintf(stderr, "Invalid match mode: %d\n", match_mod);
            break;
        }
    }
}

// 打印表格内容的函数
void print_words(word_entry *words, int word_count, char *str, int match_mod,
                 int firstcol_show, int secondcol_show,
                 int thirdcol_show, int fourthcol_show)
{
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 确定要显示的列数和每列的内容
    int columns_num = 0;
    int column_sources[4]; // 记录每列对应的word_entry字段
    const char *column_titles[4];

    if (firstcol_show != 0)
    {
        column_sources[columns_num] = firstcol_show;
        switch (firstcol_show)
        {
        case 1:
            column_titles[columns_num] = "Index";
            break;
        case 2:
            column_titles[columns_num] = "Word";
            break;
        case 3:
            column_titles[columns_num] = "Phonetic";
            break;
        case 4:
            column_titles[columns_num] = "Meaning";
            break;
        }
        columns_num++;
    }
    if (secondcol_show != 0)
    {
        column_sources[columns_num] = secondcol_show;
        switch (secondcol_show)
        {
        case 1:
            column_titles[columns_num] = "Index";
            break;
        case 2:
            column_titles[columns_num] = "Word";
            break;
        case 3:
            column_titles[columns_num] = "Phonetic";
            break;
        case 4:
            column_titles[columns_num] = "Meaning";
            break;
        }
        columns_num++;
    }
    if (thirdcol_show != 0)
    {
        column_sources[columns_num] = thirdcol_show;
        switch (thirdcol_show)
        {
        case 1:
            column_titles[columns_num] = "Index";
            break;
        case 2:
            column_titles[columns_num] = "Word";
            break;
        case 3:
            column_titles[columns_num] = "Phonetic";
            break;
        case 4:
            column_titles[columns_num] = "Meaning";
            break;
        }
        columns_num++;
    }
    if (fourthcol_show != 0)
    {
        column_sources[columns_num] = fourthcol_show;
        switch (fourthcol_show)
        {
        case 1:
            column_titles[columns_num] = "Index";
            break;
        case 2:
            column_titles[columns_num] = "Word";
            break;
        case 3:
            column_titles[columns_num] = "Phonetic";
            break;
        case 4:
            column_titles[columns_num] = "Meaning";
            break;
        }
        columns_num++;
    }

    if (columns_num == 0)
        return; // 没有列要显示

    // 1. 计算每列的最大宽度（包括标题）
    int col_max_widths[columns_num];
    for (int i = 0; i < columns_num; i++)
    {
        col_max_widths[i] = display_width_words(column_titles[i]);

        for (int j = 0; j < word_count; j++)
        {
            const char *content = NULL;
            switch (column_sources[i])
            {
            case 1:
                content = words[j].index;
                break;
            case 2:
                content = words[j].word;
                break;
            case 3:
                content = words[j].phonetic;
                break;
            case 4:
                content = words[j].meaning;
                break;
            }
            int width = display_width_words(content);
            if (width > col_max_widths[i])
            {
                col_max_widths[i] = width;
            }
        }
    }
    if (word_count == 0 && isAllChinese(str))
    { // 中文的没查到就不打印了，否则打印出一大堆！
        return;
    }
    else
    {

        // 2. 打印上边框
        for (int i = 0; i < columns_num; i++)
        {
            printf("+");
            for (int j = 0; j < col_max_widths[i] + 2; j++)
            {
                printf("-");
            }
        }
        printf("+\n");

        // 3. 打印标题行
        printf("|");
        for (int i = 0; i < columns_num; i++)
        {
            printf(" ");
            print_padded_words(column_titles[i], col_max_widths[i], NULL, NULL);
            printf(" |");
        }
        printf("\n");

        // 4. 打印标题和内容之间的分隔线
        for (int i = 0; i < columns_num; i++)
        {
            printf("+");
            for (int j = 0; j < col_max_widths[i] + 2; j++)
            {
                printf("-");
            }
        }
        printf("+\n");

        // 5. 打印表格内容
        for (int row = 0; row < word_count; row++)
        {
            printf("|");
            for (int i = 0; i < columns_num; i++)
            {
                printf(" ");
                const char *content = NULL;
                switch (column_sources[i])
                {
                case 1:
                    content = words[row].index;
                    break;
                case 2:
                    content = words[row].word;
                    break;
                case 3:
                    content = words[row].phonetic;
                    break;
                case 4:
                    content = words[row].meaning;
                    break;
                }

                const char *highlight_start = NULL;
                const char *highlight_end = NULL;

                // 如果是word列且需要高亮，如果中文查询也需要高亮匹配中文
                if (isAllChinese(str))
                { // 高亮中文
                    if (column_sources[i] == 4 && str != NULL && strlen(str) > 0)
                    {
                        get_highlight_positions(content, str, match_mod, &highlight_start, &highlight_end);
                    }
                }
                else
                {
                    if (column_sources[i] == 2 && str != NULL && strlen(str) > 0)
                    {
                        get_highlight_positions(content, str, match_mod, &highlight_start, &highlight_end);
                    }
                }
                print_padded_words(content, col_max_widths[i], highlight_start, highlight_end);
                printf(" |");
            }
            printf("\n");
        }

        // 6. 打印下边框
        for (int i = 0; i < columns_num; i++)
        {
            printf("+");
            for (int j = 0; j < col_max_widths[i] + 2; j++)
            {
                printf("-");
            }
        }
        printf("+\n\n");
    }
}
// git commit -a -m "二级Token指令实现了"

// void print_words_chinese(word_entry *words, int word_count, char *str, int match_mod,
//                  int firstcol_show, int secondcol_show,
//                  int thirdcol_show, int fourthcol_show)
// {
//     setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

//     // 确定要显示的列数和每列的内容
//     int columns_num = 0;
//     int column_sources[4]; // 记录每列对应的word_entry字段
//     const char *column_titles[4];

//     if (firstcol_show != 0)
//     {
//         column_sources[columns_num] = firstcol_show;
//         switch (firstcol_show)
//         {
//         case 1:
//             column_titles[columns_num] = "Index";
//             break;
//         case 2:
//             column_titles[columns_num] = "Word";
//             break;
//         case 3:
//             column_titles[columns_num] = "Phonetic";
//             break;
//         case 4:
//             column_titles[columns_num] = "Meaning";
//             break;
//         }
//         columns_num++;
//     }
//     if (secondcol_show != 0)
//     {
//         column_sources[columns_num] = secondcol_show;
//         switch (secondcol_show)
//         {
//         case 1:
//             column_titles[columns_num] = "Index";
//             break;
//         case 2:
//             column_titles[columns_num] = "Word";
//             break;
//         case 3:
//             column_titles[columns_num] = "Phonetic";
//             break;
//         case 4:
//             column_titles[columns_num] = "Meaning";
//             break;
//         }
//         columns_num++;
//     }
//     if (thirdcol_show != 0)
//     {
//         column_sources[columns_num] = thirdcol_show;
//         switch (thirdcol_show)
//         {
//         case 1:
//             column_titles[columns_num] = "Index";
//             break;
//         case 2:
//             column_titles[columns_num] = "Word";
//             break;
//         case 3:
//             column_titles[columns_num] = "Phonetic";
//             break;
//         case 4:
//             column_titles[columns_num] = "Meaning";
//             break;
//         }
//         columns_num++;
//     }
//     if (fourthcol_show != 0)
//     {
//         column_sources[columns_num] = fourthcol_show;
//         switch (fourthcol_show)
//         {
//         case 1:
//             column_titles[columns_num] = "Index";
//             break;
//         case 2:
//             column_titles[columns_num] = "Word";
//             break;
//         case 3:
//             column_titles[columns_num] = "Phonetic";
//             break;
//         case 4:
//             column_titles[columns_num] = "Meaning";
//             break;
//         }
//         columns_num++;
//     }

//     if (columns_num == 0)
//         return; // 没有列要显示

//     // 1. 计算每列的最大宽度（包括标题）
//     int col_max_widths[columns_num];
//     for (int i = 0; i < columns_num; i++)
//     {
//         col_max_widths[i] = display_width_words(column_titles[i]);

//         for (int j = 0; j < word_count; j++)
//         {
//             const char *content = NULL;
//             switch (column_sources[i])
//             {
//             case 1:
//                 content = words[j].index;
//                 break;
//             case 2:
//                 content = words[j].word;
//                 break;
//             case 3:
//                 content = words[j].phonetic;
//                 break;
//             case 4:
//                 content = words[j].meaning;
//                 break;
//             }
//             int width = display_width_words(content);
//             if (width > col_max_widths[i])
//             {
//                 col_max_widths[i] = width;
//             }
//         }
//     }

//     // 2. 打印上边框
//     for (int i = 0; i < columns_num; i++)
//     {
//         printf("+");
//         for (int j = 0; j < col_max_widths[i] + 2; j++)
//         {
//             printf("-");
//         }
//     }
//     printf("+\n");

//     // 3. 打印标题行
//     printf("|");
//     for (int i = 0; i < columns_num; i++)
//     {
//         printf(" ");
//         print_padded_words(column_titles[i], col_max_widths[i], NULL, NULL);
//         printf(" |");
//     }
//     printf("\n");

//     // 4. 打印标题和内容之间的分隔线
//     for (int i = 0; i < columns_num; i++)
//     {
//         printf("+");
//         for (int j = 0; j < col_max_widths[i] + 2; j++)
//         {
//             printf("-");
//         }
//     }
//     printf("+\n");

//     // 5. 打印表格内容
//     for (int row = 0; row < word_count; row++)
//     {
//         printf("|");
//         for (int i = 0; i < columns_num; i++)
//         {
//             printf(" ");
//             const char *content = NULL;
//             switch (column_sources[i])
//             {
//             case 1:
//                 content = words[row].index;
//                 break;
//             case 2:
//                 content = words[row].word;
//                 break;
//             case 3:
//                 content = words[row].phonetic;
//                 break;
//             case 4:
//                 content = words[row].meaning;
//                 break;
//             }

//             const char *highlight_start = NULL;
//             const char *highlight_end = NULL;

//             // 如果是word列且需要高亮，如果中文查询也需要高亮匹配中文
//             if (isAllChinese(str))
//             { // 高亮中文
//                 if (column_sources[i] == 4 && str != NULL && strlen(str) > 0)
//                 {
//                     get_highlight_positions(content, str, match_mod, &highlight_start, &highlight_end);
//                 }
//             }
//             else
//             {
//                 if (column_sources[i] == 2 && str != NULL && strlen(str) > 0)
//                 {
//                     get_highlight_positions(content, str, match_mod, &highlight_start, &highlight_end);
//                 }
//             }
//             print_padded_words(content, col_max_widths[i], highlight_start, highlight_end);
//             printf(" |");
//         }
//         printf("\n");
//     }

//     // 6. 打印下边框
//     for (int i = 0; i < columns_num; i++)
//     {
//         printf("+");
//         for (int j = 0; j < col_max_widths[i] + 2; j++)
//         {
//             printf("-");
//         }
//     }
//     printf("+\n\n");
// }