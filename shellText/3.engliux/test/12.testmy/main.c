#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

// 颜色定义
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

// 函数声明
void execute(char *str);
int add_history(const char *str);
int find_if_exist(const char ***word_list, int list_size, const char *target, int search_mode);
int find_and_highlight(const char ***s, int s_size, char *t, int search_mod, int first_show, int second_show, int third_show);
int search_word(char *str, int library_index, int search_mod, int first_show, int second_show, int third_show);
int words_len(const char ***single_lwords_set);
int is_exist_in_single_library(const char ****single_library, char *str, int lib_index, int search_mod);
int search_in_single_library(const char ****single_library, char *str, int lib_index, int search_mod, int first_show, int second_show, int third_show);
void show_contains_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);
void show_prefix_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);
void show_suffix_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);
void show_own_columns(const char ***words, int line, char *t, int first_show, int second_show, int third_show);

// 数据定义
const char ****library[] = {
    NULL, // 代替 "NO"
    NULL, // 代替 "NO"
    NULL, // 代替 "NO"
    NULL, // 代替 "NO"
    (const char****)&words_4,
    NULL, // 代替 "NO"
    (const char****)&words_6,
    NULL // 结束标记
};

const char ***words_4[] = {
    a_4,
    NULL,
};

const char ***words_6[] = {
    NULL,
};

const char *a_4[][3] = {
    {"abandon", "/əˈbændən/", "v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {"ability", "/əˈbɪləti/", "n. 能力，能耐；才能"},
    NULL
};

const char *a_6[][3] = {
    {"abandon", "/əˈbændən/", "v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {"ability", "/əˈbɪləti/", "n. 能力，能耐；才能"},
    {"ax", "/æks/", "v. 削减，删除；用斧修整；解雇；询问n. 斧头；爵士乐器（尤指吉他或萨克斯管）n. (Ax) （德、芬）阿克斯（人名）"},
    {"axis", "/ˈæksɪs/", "n. 轴；轴线；轴心国"},
    NULL
};

// 执行指令函数
void execute(char *str) {
    // 这里可以根据输入的指令进行相应的操作，目前只是简单地打印输入
    printf("执行指令: %s\n", str);
    // 假设指令是搜索单词，这里调用search_word函数
    int library_index = 0; // 搜索所有词库
    int search_mod = 2; // 包含查找
    int first_show = 1;
    int second_show = 2;
    int third_show = 3;
    search_word(str, library_index, search_mod, first_show, second_show, third_show);
}

// 主函数
int main() {
    // 注册信号处理函数
    // signal(SIGINT, exit_signal_handler);
    char *str;
    // print();
    while (1) {
        char prompt[100];
        sprintf(prompt, "%s%s[请输入指令]> %s", BOLD, GREEN, RESET);
        str = readline(prompt);

        if (str == NULL) {
            // 用户按下 Ctrl+D
            printf("\n程序终止\n");
            break;
        }

        if (strlen(str) == 0) {
            // 空输入，继续循环
            free(str);
            continue;
        }

        // 复制 str
        char *str_copy = strdup(str);
        if (str_copy == NULL) {
            perror("内存分配失败");
            free(str);
            continue;
        }

        // 执行指令
        execute(str);// 这里传入的是原始字符串，可能会被修改

        // 添加到历史记录
        add_history(str_copy);// 这里传入的是原始复制字符串，原始字符串的修改对我没影响

        // 释放复制的字符串
        free(str_copy);
        // 释放 readline 分配的内存
        free(str);
    }
    return 0;
}

// 搜索文件中的函数实现
int words_len(const char ***single_lwords_set) {
    printf("进入了单个单词集的长度函数\n");
    int len = 0;
    while (single_lwords_set[len] != NULL) {
        len++;
    }

    printf("%s%s单词集个数为:%d%s\n", RED, BOLD, len, RESET);
    return len;
}

int is_exist_in_single_library(const char ****single_library, char *str, int lib_index, int search_mod) {
    // 返回在一个库中匹配到的总条数
    // 调用find_if_exist()
    int list_size = words_len(*single_library);
    return find_if_exist(*single_library, list_size, str, search_mod);
}

int search_in_single_library(const char ****single_library, char *str, int lib_index, int search_mod, int first_show, int second_show, int third_show) {
    // 打印每一个中的匹配数据！
    int list_size = words_len(*single_library);
    int count = find_and_highlight(*single_library, list_size, str, search_mod, first_show, second_show, third_show);
    return count;
}

int search_word(char *str, int library_index, int search_mod, int first_show, int second_show, int third_show) {
    printf("%s%s查询单词:%s%s\n", BLUE, BOLD, str, RESET);

    if (library_index == 0) {
        printf("%s%s查询所有词库\n", BLUE, BOLD);
        return search_in_single_library(library[4], str, 4, search_mod, first_show, second_show, third_show) + search_in_single_library(library[6], str, 6, search_mod, first_show, second_show, third_show);
    }
    else if (library_index > 0 && library[library_index] != NULL) {
        printf("%s%s查询%d级词库\n", BLUE, BOLD, library_index);
        return search_in_single_library(library[library_index], str, library_index, search_mod, first_show, second_show, third_show);
    }
    return 0;
}

// 高亮与判存、打印文件中的函数实现
int find_if_exist(const char ***word_list, int list_size, const char *target, int search_mode) {
    // 参数检查
    if (word_list == NULL || target == NULL || *target == '\0') {
        fprintf(stderr, "错误：无效的输入参数！\n");
        return 0;
    }

    printf("正在查找: %s (模式: %d)\n", target, search_mode);
    int total_count = 0;

    for (int i = 0; i < list_size && word_list[i] != NULL; i++) {
        // 获取单词条目
        printf("检查单词列表中的第 %d 个条目...\n", i);
        const char *word = word_list[i][0];
        if (word == NULL) continue;

        printf("检查单词: %s\n", word);

        int match = 0;
        switch (search_mode) {
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

        if (match) {
            total_count++;
            printf(">>> 匹配 #%d: %s\n", total_count, word);
        }
    }

    printf("查找完成，共找到 %d 个匹配项\n", total_count);
    return total_count;
}

int find_and_highlight(const char ***s, int s_size, char *t, int search_mod, int first_show, int second_show, int third_show) {
    printf("进入高亮显示阶段：\n");
    int first = 1;
    for (int i = 0; i < s_size; i++) {
        int found = 0;
        switch (search_mod) {
        case 1: // 精确查找单词
            found = strcmp(s[i][0], t) == 0;
            break;
        case 2: // 包含查找
            found = strstr((char *)s[i][0], t) != NULL;
            break;
        case 3: // 前缀查找
            found = strncmp(s[i][0], t, strlen(t)) == 0;
            break;
        case 4: // 后缀查找
        {
            size_t suffix_len = strlen(t);
            size_t word_len = strlen(s[i][0]);
            found = word_len >= suffix_len && strcmp(s[i][0] + word_len - suffix_len, t) == 0;
        }
        break;
        default:
            fprintf(stderr, "无效的查找模式: %d\n", search_mod);
            break;
        }

        // 已经能找到了！
        if (found) {
            if (!first) {

            }
            const char *p = s[i][0];
            // 包含查找
            if (search_mod == 2) {
                printf("进入包含查找高亮阶段：\n");
                show_contains_columns(s, i, t, first_show, second_show, third_show);
            }
            else if (search_mod == 3) // 前缀查找
            {
                printf("进入前缀查找高亮阶段：\n");
                show_prefix_columns(s, i, t, first_show, second_show, third_show);
            }
            else if (search_mod == 4) // 后缀查找
            {
                printf("进入后缀查找高亮阶段：\n");
                show_suffix_columns(s, i, t, first_show, second_show, third_show);
            }
            // 精确查找
            else {
                printf("进入精确查找高亮阶段：\n");
                show_own_columns(s, i, t, first_show, second_show, third_show);
            }
            first = 0;
            printf("\n\n");
        }
    }
    printf("高亮完毕！\n");
    return 0;
}

// 打印文件中的函数实现
void show_contains_columns(const char ***words, int line, char *t,
                           int first_show, int second_show, int third_show) {
    // 搜索到的单词(单词片段)，会高亮显示
    // 2、自定义显示
    // col1, col2, col3是指定了在该列显示什么，共有字段单词、音标、释义
    // 其中    1代表单词   2代表音标      3代表释义
    // 其中，先后按下的顺序是在电脑上显示的顺序，电脑上一共最多显示3列，但是可以自定义显示方式！从数量上，可以自定义显示1~3列，从位置上，可以自定义1~3列的位置显示什么内容！并且可以重复显示
    // 每一列都可以以0~3的数字表示，分别表示该列显示什么内容，0代表不显示，1代表显示单词，2代表显示音标，3代表显示释义
    // ，每一列向左对齐40，即%-40s
    // col1col2col3    first_show    second_show    third_show    显示内容
    // 001    0    0    1    显示释义
    // 002    0    0    2    显示音标
    // 010    0    1    0    显示音标
    // 012    0    1    2    显示音标 - 释义
    // 013    0    1    3    显示音标 - 单词
    // 020    0    2    0    显示音标
    // 021    0    2    1    显示音标 - 单词
    // 023    0    2    3    显示音标 - 释义
    // 030    0    3    0    显示释义
    // 031    0    3    1    显示释义 - 单词
    // 032    0    3    2    显示释义 - 音标
    // 100    1    0    0    显示单词
    // 102    1    0    2    显示单词 - 音标
    // 103    1    0    3    显示单词 - 释义
    // 120    1    2    0    显示单词 - 音标
    // 123    1    2    3    显示单词 - 音标 - 释义
    // 130    1    3    0    显示单词 - 释义
    // 132    1    3    2    显示单词 - 释义 - 音标
    // 200    2    0    0    显示音标
    // 201    2    0    1    显示音标 - 单词
    // 203    2    0    3    显示音标 - 释义
    // 210    2    1    0    显示音标 - 单词
    // 213    2    1    3    显示音标 - 单词 - 释义
    // 230    2    3    0    显示音标 - 释义
    // 231    2    3    1    显示音标 - 释义 - 单词
    // 300    3    0    0    显示释义
    // 301    3    0    1    显示释义 - 单词
    // 302    3    0    2    显示释义 - 音标
    // 310    3    1    0    显示释义 - 单词
    // 312    3    1    2    显示释义 - 单词 - 音标
    // 320    3    2    0    显示释义 - 音标
    // 321    3    2    1    显示释义 - 音标 - 单词
    // 330    3    3    0    显示释义 - 音标 - 释义
    // 这里简单打印单词、音标和释义
    if (first_show == 1) printf("%-40s", words[line][0]);
    if (first_show == 2) printf("%-40s", words[line][1]);
    if (first_show == 3) printf("%-40s", words[line][2]);
    if (second_show == 1) printf("%-40s", words[line][0]);
    if (second_show == 2) printf("%-40s", words[line][1]);
    if (second_show == 3) printf("%-40s", words[line][2]);
    if (third_show == 1) printf("%-40s", words[line][0]);
    if (third_show == 2) printf("%-40s", words[line][1]);
    if (third_show == 3) printf("%-40s", words[line][2]);
    printf("\n");
}

// 以下为未实现函数的简单占位，实际中根据需求完善
// int KMPSearch(char *pattern, char *text) {
//     return 0;
// }
// void show_prefix_columns(const char ***words, int line, char *t, int first_show