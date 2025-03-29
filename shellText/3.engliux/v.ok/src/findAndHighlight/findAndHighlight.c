#include "../../include/findAndHighlight.h"

// 计算部分匹配表（next 数组）
void computeLPSArray(const char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP 搜索算法
int KMPSearch(const char *pat, const char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int) * M);
    if (lps == NULL)
    {
        perror("malloc");
        return 0;
    }
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            count++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    free(lps);
    return count;
}

int find_if_exist(word_entry *word_list /*单个单词集*/, int list_size, const char *target, int search_mode)
{
    printf("1--find_if_exist--通过这里了\n");
    
    // 参数检查
    if (word_list == NULL || target == NULL || *target == '\0')
    {
        fprintf(stderr, "错误：无效的输入参数！\n");
        return 0;
    }

    // printf("正在查找: %s (模式: %d)\n", target, search_mode);
    int total_count = 0;

    for (int i = 0; i < list_size; i++)
    {
        // 获取单词条目
        printf("检查单词列表中的第 %d 个条目...\n", i);
        const char *word = word_list[i].word;
        // printf("检查单词: %s\n", word);
        int match = 0;
        switch (search_mode)
        {
        case 1: // 精确匹配
            match = (strcmp(word, target) == 0);
            break;
        case 2: // 包含
            match = (strstr(word, target) != NULL);
            break;
        case 3: // 前缀
            match = (strncmp(word, target, strlen(target)) == 0);
            break;
        case 4: // 后缀
        {
            size_t target_len = strlen(target);
            size_t word_len = strlen(word);
            match = (word_len >= target_len) &&
                    (strcmp(word + word_len - target_len, target) == 0);
        }
        break;
        default:
            fprintf(stderr, "错误：无效的搜索模式 %d\n", search_mode);
            return -1;
        }

        if (match)
        {
            total_count++;
            // printf(">>> 匹配 #%d: %s\n", total_count, word);
        }
    }
    printf("3--find_if_exist--通过这里了\n");

    // printf("查找完成，共找到 %d 个匹配项\n", total_count);
    return total_count;
}

// 高亮显示匹配的字符串
int find_and_highlight(word_entry *word_list /*单个单词集*/, int s_size, char *t, int search_mod, int first_show, int second_show, int third_show)
{
    // printf("进入高亮显示阶段：\n");
    // int flag = 0;//因为查找在上面已经完成了，所以这里就不用判断了！只需要高亮显示即可！
    int first = 1;
    // int count = 0;
    for (int i = 0; word_list[i].index; i++)
    {
        // printf("检查单词列表中的第 %d 个条目...%s\n", i, word_list[i].word);

        int found = 0;
        switch (search_mod)
        {
        case 1: // 精确查找单词
            found = strcmp(word_list[i].word, t) == 0;
            break;
        case 2: // 包含查找
            found = KMPSearch(t, word_list[i].word) > 0;
            break;
        case 3: // 前缀查找
            found = strncmp(word_list[i].word, t, strlen(t)) == 0;
            break;
        case 4: // 后缀查找
        {
            size_t suffix_len = strlen(t);
            size_t word_len = strlen(word_list[i].word);
            found = word_len >= suffix_len && strcmp(word_list[i].word + word_len - suffix_len, t) == 0;
        }
        break;
        default:
            fprintf(stderr, "无效的查找模式: %d\n", search_mod);
            break;
        }

        // printf("该单词%s对比完毕...\n", word_list[i].word);
        // 已经能找到了！
        if (found)
        {
            // printf("该单词%s查找完毕...\n", word_list[i].word);

            if (!first)
            {
                // putchar(',');
                // puts("");
            }
            const char *p = word_list[i].word;
            // 包含查找
            if (search_mod == 2)
            {
                // printf("进入包含显示阶段：\n");
                show_contains_columns(word_list, i, t, first_show, second_show, third_show);
            }
            else if (search_mod == 3) // 前缀查找
            {
                // printf("进入前缀显示阶段：\n");
                show_prefix_columns(word_list, i, t, first_show, second_show, third_show);
            }
            else if (search_mod == 4) // 后缀查找
            {
                // printf("进入后缀显示阶段：\n");
                show_suffix_columns(word_list, i, t, first_show, second_show, third_show);
            }
            // 精确查找
            else
            {
                // printf("进入精确显示阶段：\n");
                show_exact_columns(word_list, i, t, first_show, second_show, third_show);
            }
            first = 0;
            printf("\n\n");
        }
    }
    // printf("高亮完毕！\n");
    // return flag;
}

// int main()
// {
//     word_entry s1[] = {
//         {
//             "378",
//             "baby",
//             "/ˈbeɪbi/",
//             "n. 婴儿，婴孩；孩子气的人vt. 纵容，娇纵；把……当婴儿般对待adj. 婴儿的；幼小的n. (Baby)人名；(法、葡)巴比；(英)巴比，芭比(女名)；(俄)巴贝",
//         },
//         {
//             "379",
//             "bachelor",
//             "/ˈbætʃələr/",
//             "n. 学士；单身汉；（尚未交配的）小雄兽n. (Bachelor)人名；(英)巴彻勒",
//         },
//         {NULL, NULL, NULL, NULL}};
//     word_entry s2[] = {
//         {
//             "378",
//             "baby",
//             "/ˈbeɪbi/",
//             "n. 婴儿，婴孩；孩子气的人vt. 纵容，娇纵；把……当婴儿般对待adj. 婴儿的；幼小的n. (Baby)人名；(法、葡)巴比；(英)巴比，芭比(女名)；(俄)巴贝",
//         },
//         {
//             "379",
//             "bachelor",
//             "/ˈbætʃələr/",
//             "n. 学士；单身汉；（尚未交配的）小雄兽n. (Bachelor)人名；(英)巴彻勒",
//         },
//         {NULL, NULL, NULL, NULL}

//     };
//     word_entry *s[] = {
//         s1,
//         s2,
//         NULL,
//     };

//     char t[] = "baby";
//     int s_size = sizeof(s1) / sizeof(s1[0]); // 每一个指针的大小相等！所以这里可以借此得到长度！
//     puts("精确查找:");
//     // printf("find_if_exist(s, s_size, t, 1) = %d\n", find_if_exist(s, s_size, t, 1));
//     find_and_highlight(s1, s_size, t, 1, 1, 1, 1);
//     puts("包含查找:");

//     find_and_highlight(s1, s_size, t, 2, 1, 1, 1);
//     puts("前缀查找:");

//     find_and_highlight(s1, s_size, t, 3, 1, 2, 3);
//     puts("后缀查找:");

//     find_and_highlight(s1, s_size, t, 4, 3, 3, 3);

//     return 0;
// }