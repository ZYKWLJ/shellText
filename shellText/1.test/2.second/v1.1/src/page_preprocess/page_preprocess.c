#include "../../include/page_preprocess.h"
// void strtokWithSpaceForPage(char *str, char *delimiters, char *tokens[], int *page_num)
// { // 专门为查找页面指令设计的，因为指令实在太多了只能分离先判断page、p,这里主要是先抽取出page_num！
//     char *token = strtok(str, delimiters);
//     while (token != NULL)
//     {
//         *tokens++ = token;
//         token = strtok(NULL, delimiters);
//     }
//     // 计算tokens数组的长度
//     int tokens_len = 0;
//     for (int i = 0; tokens[i]; i++)
//     {
//         tokens_len++;
//     }
//     if (tokens_len == 2) // 首单词是page或者p已经在前面判断过了，这里只需要判断后面的数字是否合法即可,未接数字，在下面判断tokens长度即可！
//     {

//         for (int i = 0; i < strlen(tokens[1]); i++) // 如果后面的不是数字，直接报错！页面为-2表示输入的不是数字
//         {
//             if (!isdigit(tokens[1][i]))
//             {
//                 *page_num = -2;
//                 printf("您输入的页面号有误!\n");
//                 return;
//             }
//         }
//         printf("这是正确的page指令\n");
//         *page_num = atoi(tokens[1]);
//         return;
//     }
// }
// void page_preprocess(char *str)
// {
//     printf("这是page指令的预处理，str=%s\n", str);
//     char *str0 = str;
//     char **tokens;
//     int page_num = -1; ///-1表示没有输入页面号
//     strtokWithSpaceForPage(str, " ", tokens, &page_num);
//     // 计算tokens数组的长度
//     int tokens_len = 0;
//     for (int i = 0; tokens[i]; i++)
//     {
//         tokens_len++;
//     }
//     // 长度为1，并且前面已经判断首字母是page或者p，这里只需要判断后面的数字是否合法即可
//     if (tokens_len == 1) // 如果没有输入页面号，提示出错！
//     {
//         printf("%s%s您未输出页面号!%s!\n", BOLD, RED, RESET);
//         return;
//     }
//     if (page_num == -2)
//     {
//         printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, tokens[1], RESET);
//         return;
//     }
//     if (tokens_len > 2)
//     { // 后面的一连串都是非法的！
//         int i = 0;
//         for (; str0[i] != ' '; i++)
//         {
//         }
//         char *str1;
//         for (int j = i + 1; j < strlen(str0); j++)
//         {
//             str1[j - i] = str[j];
//         }
//         printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, str1, RESET);
//         return;
//     }
//     // 有效的页面号！
//     else
//     {
//         if (page_num < 0)
//         {
//             printf("页面不能为负数!\n");
//             return;
//         }
//         else if (page_num > 500)
//         {
//             printf("本书仅有%s%s400%s页，%s%s%d%s超页\n", BOLD, GREEN, RESET, BOLD, RED, page_num, RESET);
//             return;
//         }
//         else
//         {
//             show_page(page_num);
//         }
//     }
// }

// void strtokWithSpaceForPage(char *str, char *delimiters, char *tokens[], int *page_num) {
//     // 专门为查找页面指令设计的，因为指令实在太多了只能分离先判断page、p,这里主要是先抽取出page_num！
//     int i = 0;
//     char *token = strtok(str, delimiters);
//     while (token != NULL && i < 2) {
//         tokens[i++] = token;
//         token = strtok(NULL, delimiters);
//     }
//     tokens[i] = NULL;

//     if (i == 2) { // 首单词是page或者p已经在前面判断过了，这里只需要判断后面的数字是否合法即可,未接数字，在下面判断tokens长度即可！
//         int len = strlen(tokens[1]);
//         for (int j = 0; j < len; j++) { // 如果后面的不是数字，直接报错！页面为-2表示输入的不是数字
//             if (!isdigit(tokens[1][j])) {
//                 *page_num = -2;
//                 printf("您输入的页面号有误!\n");
//                 return;
//             }
//         }
//         printf("这是正确的page指令\n");
//         *page_num = atoi(tokens[1]);
//         return;
//     }
// }

// void page_preprocess(char *str) {
//     printf("这是page指令的预处理，str=%s\n", str);
//     char*str0=str;
//     char *tokens[3]; // 最多两个有效参数，最后一个为NULL
//     int page_num = -1; ///-1表示没有输入页面号
//     strtokWithSpaceForPage(strdup(str), " ", tokens, &page_num);

//     int tokens_len = 0;
//     while (tokens[tokens_len] != NULL) {
//         tokens_len++;
//     }

//     if (tokens_len == 1) { // 如果没有输入页面号，提示出错！
//         printf("%s%s您未输出页面号!%s!\n", BOLD, RED, RESET);
//         return;
//     }

//     if (page_num == -2) {
//         printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, tokens[1], RESET);
//         return;
//     }

//     if (tokens_len > 2) { // 后面的一连串都是非法的！
//         int i = 0;
//         while (str0[i] != ' ' && str0[i] != '\0') {
//             i++;
//         }
//         char *str1;
//         // if (str[i] != '\0') {
//         //     char *str1 = str + i + 1;

//         // }
//         for(int j=i+1;j<strlen(str);j++){
//             str1[j-i]=str0[j];
//             printf("%s%s%c%s",BOLD, RED,str0[j],RESET);
//         }
//         // printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, str1, RESET);
//         printf("--非有效页面号!\n");
//         return;
//     }

//     // 有效的页面号！
//     if (page_num < 0) {
//         printf("页面不能为负数!\n");
//         return;
//     } else if (page_num > 400) {
//         printf("本书仅有%s%s400%s页，%s%s%d%s超页\n", BOLD, GREEN, RESET, BOLD, RED, page_num, RESET);
//         return;
//     } else {
//         show_page(page_num);
//     }
// }

// void strtokWithSpaceForPage(char *str, char *delimiters, char *tokens[], int *page_num) {
//     int i = 0;
//     char *token = strtok(str, delimiters);
//     while (token != NULL && i < 2) {
//         tokens[i++] = token;
//         token = strtok(NULL, delimiters);
//     }
//     tokens[i] = NULL;

//     if (i == 2) {
//         int len = strlen(tokens[1]);
//         for (int j = 0; j < len; j++) {
//             if (!isdigit(tokens[1][j])) {
//                 *page_num = -2;
//                 printf("您输入的页面号有误!\n");
//                 return;
//             }
//         }
//         printf("这是正确的page指令\n");
//         *page_num = atoi(tokens[1]);
//         return;
//     }
// }

// void page_preprocess(char *str) {
//     printf("这是page指令的预处理，str=%s\n", str);
//     char *tokens[3]; // 最多两个有效参数，最后一个为NULL
//     int page_num = -1; ///-1表示没有输入页面号
//     char *str_copy = strdup(str);
//     if (str_copy == NULL) {
//         perror("strdup");
//         return;
//     }
//     strtokWithSpaceForPage(str_copy, " ", tokens, &page_num);
//     free(str_copy);

//     int tokens_len = 0;
//     while (tokens[tokens_len] != NULL) {
//         tokens_len++;
//     }

//     if (tokens_len == 1) {
//         printf("%s%s您未输出页面号!%s!\n", BOLD, RED, RESET);
//         return;
//     }

//     if (page_num == -2) {
//         printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, tokens[1], RESET);
//         return;
//     }

//     if (tokens_len > 2) {
//         int i = 0;
//         while (str[i] != ' ' && str[i] != '\0') {
//             i++;
//         }
//         if (str[i] != '\0') {
//             char *str1 = str + i + 1;
//             printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, str1, RESET);
//         }
//         return;
//     }

//     // 有效的页面号！
//     if (page_num < 0) {
//         printf("页面不能为负数!\n");
//         return;
//     } else if (page_num > 400) {
//         printf("本书仅有%s%s400%s页，%s%s%d%s超页\n", BOLD, GREEN, RESET, BOLD, RED, page_num, RESET);
//         return;
//     } else {
//         show_page(page_num);
//     }
// }

// 专门处理 page 指令，提取页面号并检查合法性
// void strtokWithSpaceForPage(char *str, int *page_num) {
//     char *first_token = strtok(str, " ");
//     if (first_token == NULL) {
//         *page_num = -1;
//         return;
//     }

//     if (strcmp(first_token, "page") != 0 && strcmp(first_token, "p") != 0) {
//         *page_num = -1;
//         return;
//     }

//     char *second_token = strtok(NULL, " ");
//     if (second_token == NULL) {
//         *page_num = -1;
//         printf("%s%s您未输出页面号!%s!\n", BOLD, RED, RESET);
//         return;
//     }

//     // 检查第二个参数是否全为数字
//     for (int i = 0; second_token[i] != '\0'; i++) {
//         if (!isdigit(second_token[i])) {
//             *page_num = -2;
//             printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, second_token, RESET);
//             return;
//         }
//     }

//     // 检查是否还有其他参数
//     if (strtok(NULL, " ") != NULL) {
//         *page_num = -2;
//         printf("指令中包含多余内容，格式错误!\n");
//         return;
//     }

//     *page_num = atoi(second_token);
// }

// // 页面指令预处理函数
// void page_preprocess(char *str) {
//     printf("这是 page 指令的预处理，str=%s\n", str);
//     char *str_copy = strdup(str);
//     if (str_copy == NULL) {
//         perror("strdup");
//         return;
//     }

//     int page_num = -1;
//     strtokWithSpaceForPage(str_copy, &page_num);
//     free(str_copy);

//     if (page_num == -1) {
//         return;
//     }

//     if (page_num == -2) {
//         return;
//     }

//     // 有效的页面号！
//     if (page_num < 0) {
//         printf("页面不能为负数!\n");
//         return;
//     } else if (page_num > 400) {
//         printf("本书仅有%s%s400%s页，%s%s%d%s超页\n", BOLD, GREEN, RESET, BOLD, RED, page_num, RESET);
//         return;
//     } else {
//         show_page(page_num);
//     }
// }

// 示例的 show_page 函数实现
// void show_page(int page_num) {
//     printf("正在显示第 %d 页的内容...\n", page_num);
// }

// 专门处理 page 指令，提取页面号并检查合法性
// void strtokWithSpaceForPage(char *str, int *page_num) {
//     char *first_token = strtok(str, " ");
//     if (first_token == NULL) {
//         *page_num = -1;
//         return;
//     }

//     if (strcmp(first_token, "page") != 0 && strcmp(first_token, "p") != 0) {
//         *page_num = -1;
//         return;
//     }

//     char *second_token = strtok(NULL, " ");
//     if (second_token == NULL) {
//         *page_num = -1;
//         printf("%s%s您未输出页面号!%s!\n", BOLD, RED, RESET);
//         return;
//     }

//     // 检查第二个参数是否全为数字
//     for (int i = 0; second_token[i] != '\0'; i++) {
//         if (!isdigit(second_token[i])) {
//             *page_num = -2;
//             char *invalid_part = strstr(str, " ") + 1;
//             printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, invalid_part, RESET);
//             return;
//         }
//     }

//     // 检查是否还有其他参数
//     if (strtok(NULL, " ") != NULL) {
//         *page_num = -2;
//         char *invalid_part = strstr(str, " ") + 1;
//         printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, invalid_part, RESET);
//         return;
//     }

//     *page_num = atoi(second_token);
// }

// // 页面指令预处理函数
// void page_preprocess(char *str) {
//     printf("这是 page 指令的预处理，str=%s\n", str);
//     char *str_copy = strdup(str);
//     if (str_copy == NULL) {
//         perror("strdup");
//         return;
//     }

//     int page_num = -1;
//     strtokWithSpaceForPage(str_copy, &page_num);
//     free(str_copy);

//     if (page_num == -1) {
//         return;
//     }

//     if (page_num == -2) {
//         return;
//     }

//     // 有效的页面号！
//     if (page_num < 0) {
//         printf("页面不能为负数!\n");
//         return;
//     } else if (page_num > 400) {
//         printf("本书仅有%s%s400%s页，%s%s%d%s超页\n", BOLD, GREEN, RESET, BOLD, RED, page_num, RESET);
//         return;
//     } else {
//         show_page(page_num);
//     }
// }

/*
void page_preprocess(char *str)
作用：伪代码
背景：str是用户输入的字符串，可能包含多个单词，每个单词之间用空格分隔
其中，str在前面已经确定以page或者p开头，接下来的单词可能是数字，也可能是其他字符
任务：检查接下来的字符：
0. 如果没有任何字符，输出“您未输出页面号!”
1. 如果是单独的一个数字num，输出“这是num页面内容”
2. 其余任何情况(包括多个单词、跟一个包含非数字的单词)，请你输出除了第一个单词之后的所有命令(之间的空格也不能省略)，并指示非有效页面。如printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, invalid_part, RESET);

*/

// 去除字符串头尾的空格
void trim(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    // 去除开头的空格
    while (start < len && isspace(str[start]))
    {
        start++;
    }

    // 去除结尾的空格
    while (end > start && isspace(str[end]))
    {
        end--;
    }

    // 移动字符串内容
    int i;
    for (i = 0; i <= end - start; i++)
    {
        str[i] = str[start + i];
    }
    str[i] = '\0';
}

void page_preprocess(char *str)
{
    trim(str);

    // 跳过开头的 "page" 或 "p" 以及后面的空格
    if (strncmp(str, "page", 4) == 0)
    {
        str += 4;
    }
    else if (strncmp(str, "p", 1) == 0)
    {
        str += 1;
    }
    while (*str == ' ')
    {
        str++;
    }

    // 如果没有任何字符
    if (*str == '\0')
    {
        printf("%s%s您未输出页面号!%s\n",RED,BOLD,RESET);
        return;
    }

    // 检查是否为单独的一个数字
    int is_digit = 1;
    char *start = str;
    while (*str != '\0' && *str != ' ')
    {
        if (!isdigit(*str))
        {
            is_digit = 0;
            break;
        }
        str++;
    }

    if (is_digit && *str == '\0')
    {
        
        if (atoi(start) > 400)
        {
            printf("本书仅有%s%s400%s页，%s%s%d%s超页\n", BOLD, GREEN, RESET, BOLD, RED, atoi(start), RESET);
        }
        else
        {
            show_page(atoi(start));
        }

        // printf("这是%s页面内容\n", start);
    }
    else
    {
        // 其余情况
        printf("%s%s%s%s--非有效页面号!\n", BOLD, RED, start, RESET);
    }
}
