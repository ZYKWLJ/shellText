#ifndef CHAPTER4_H
#define CHAPTER4_H
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include "text_common.h"

// 定义章节宏
#define CHAPTER_4(title, page)                                                     \
    do                                                                             \
    {                                                                              \
        char buf[256];                                                             \
        snprintf(buf, sizeof(buf), "%s%s第 4 章  %s%s.................................", BOLD, BLUE, title, RESET); \
                                                                                   \
        printf("%s", buf);                                                         \
        print_dots(buf, RIGHT_ALIGN_POS - 3);                                      \
        printf(" %d\n", page);                                                     \
    } while (0)

// 定义一级小节宏
#define CHAPTER_4_SUB_SECTION_1(num, title, page)             \
    do                                                        \
    {                                                         \
        char buf[256];                                        \
        snprintf(buf, sizeof(buf), "  4.%d  %s", num, title); \
        printf("%s", buf);                                    \
        print_dots(buf, RIGHT_ALIGN_POS - 3);                 \
        printf(" %d\n", page);                                \
    } while (0)

// 定义二级小节宏
#define CHAPTER_4_SUB_SECTION_2(num, title, page)                 \
    do                                                            \
    {                                                             \
        char buf[256];                                            \
        snprintf(buf, sizeof(buf), "    4.1.%d  %s", num, title); \
        printf("%s", buf);                                        \
        print_dots(buf, RIGHT_ALIGN_POS - 3);                     \
        printf(" %d\n", page);                                    \
    } while (0)

// 定义思考训练和参考文献宏
#define CHAPTER_4_EXERCISE_REF(title, page)      \
    do                                           \
    {                                            \
        char buf[256];                           \
        snprintf(buf, sizeof(buf), "%s", title); \
        printf("%s", buf);                       \
        print_dots(buf, RIGHT_ALIGN_POS - 3);    \
        printf(" %d\n", page);                   \
    } while (0)
void display_chapter4();

// int main()
// {

//     return 0;
// }
#endif