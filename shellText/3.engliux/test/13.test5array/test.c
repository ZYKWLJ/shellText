#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// 颜色定义
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define UNDERLINE "\033[4m"

/* ====================== 词库分类定义 ====================== */
// 4级词库
// 修改词库定义为指针数组形式
const char ***lib4_words_a = (const char*[]){
    (const char*[]){"abandon", "/əˈbændən/", "v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    (const char*[]){"ability", "/əˈbɪləti/", "n. 能力，能耐；才能"},
    NULL
};

const char ***lib4_words_b = {
    {"baby", "/ˈbeɪbi/", "n. 婴儿；宝贝儿；孩子气的人"},
    {"back", "/bæk/", "n. 后面；背部；靠背；足球后卫"},
    NULL,  // 结束标记
};

// 需要类型转换，因为二维数组和三级指针类型不同
const char ***lib4[] = {
    (const char ***)lib4_words_a,
    (const char ***)lib4_words_b,
    NULL};

// 6级词库
const char *lib6_words_a[][3] = {
    {"abandon", "/əˈbændən/", "v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {"ability", "/əˈbɪləti/", "n. 能力，能耐；才能"},
    {"ax", "/æks/", "v. 削减，删除；用斧修整；解雇；询问n. 斧头；爵士乐器（尤指吉他或萨克斯管）n. (Ax) （德、芬）阿克斯（人名）"},
    {"axis", "/ˈæksɪs/", "n. 轴；轴线；轴心国"},
    {NULL, NULL, NULL} // 结束标记
};

const char *lib6_words_b[][3] = {
    {"banana", "/bəˈnɑːnə/", "n. 香蕉；喜剧演员"},
    {"band", "/bænd/", "n. 带；乐队；范围；价值"},
    {NULL, NULL, NULL} // 结束标记
};

const char ***lib6[] = {
    (const char ***)lib6_words_a,
    (const char ***)lib6_words_b,
    NULL};

// 主词库分类
const char ****library_categories[] = {
    lib4, // 4级词库
    lib6, // 6级词库
    NULL};

/* ====================== 遍历函数 ====================== */
// 打印单个词库内容
void print_library(const char ****lib, int level)
{
    printf("\n%s%s %d级词库 %s\n", BOLD, GREEN, level, RESET);
    printf("%s====================%s\n", GREEN, RESET);

    for (int set = 0; lib[set] != NULL; set++)//单词集
    {
        printf("  %s词集 %c:%s\n", BLUE, 'A' + set, RESET);

        for (int word = 0; lib[set][word] != NULL; word++)//单词
        {
            printf("    %s%-10s%s %s%-12s%s %s\n",
                   MAGENTA, lib[set][word][0], RESET, // 单词
                   CYAN, lib[set][word][1], RESET,    // 音标
                   lib[set][word][2]);                // 释义
        }
    }
}

// 分类遍历所有词库
void print_all_categorized()
{
    const int levels[] = {4, 6};

    for (int cat = 0; library_categories[cat] != NULL; cat++)
    {
        print_library(library_categories[cat], levels[cat]);
    }
}

// 按词库级别搜索单词
void search_in_library(const char ****lib, int level, const char *target)
{
    bool found = false;

    for (int set = 0; lib[set] != NULL; set++)
    {
        for (int word = 0; lib[set][word] != NULL; word++)
        {
            if (strstr(lib[set][word][0], target))
            {
                if (!found)
                {
                    printf("\n%s在%d级词库中找到匹配：%s\n",
                           YELLOW, level, RESET);
                    found = true;
                }
                printf("  %s%-10s%s %s%-12s%s %s\n",
                       MAGENTA, lib[set][word][0], RESET,
                       CYAN, lib[set][word][1], RESET,
                       lib[set][word][2]);
            }
        }
    }

    if (!found)
    {
        printf("%s%d级词库中未找到匹配%s\n", RED, level, RESET);
    }
}

/* ====================== 主函数 ====================== */
int main()
{
    printf("%s=== 词库分类访问演示 ===%s\n\n", BOLD, RESET);

    // 1. 打印所有分类词库
    print_all_categorized();

    // 2. 分类搜索演示
    printf("\n%s=== 分类搜索演示 ===%s\n", BOLD, RESET);

    // 在4级词库中搜索
    printf("\n%s[在4级词库中搜索 \"ab\"]%s\n", UNDERLINE, RESET);
    search_in_library(lib4, 4, "ab");

    // 在6级词库中搜索
    printf("\n%s[在6级词库中搜索 \"ba\"]%s\n", UNDERLINE, RESET);
    search_in_library(lib6, 6, "ba");

    return 0;
}