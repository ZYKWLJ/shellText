#include <stdio.h>

typedef struct
{
    int index;
    const char *word;
    const char *phonetic;
    const char *meaning;
} word_entry;

// 移除多余的 NULL
word_entry words_4_a[] = {
    {0, "abandon", "/əˈbændən/", "v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {1, "ability", "/əˈbɪləti/", "n. 能力，能耐；才能"},
    {2, "able", "/əˈblə/", "adj. 能干的；能干的；能干的"},
    {3, "abandoned", "/əˈbændən/", "v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {4, "ability", "/əˈbɪləti/", "n. 能力，能耐；才能"},
    {-1, NULL, NULL, NULL},
};

int main()
{
    // 根据数组长度控制循环
    for (int i = 0; words_4_a[i].index != -1; i++)
    { // 标记结尾！数组都不好结尾的！
        printf("%s\n", words_4_a[i].word);
        printf("%s\n", words_4_a[i].phonetic);
        printf("%s\n", words_4_a[i].meaning);
        printf("\n");
    }

    return 0;
}
