#ifndef CHAPTER6_H
#define CHAPTER6_H
#include "text_common.h"

// 定义章节宏
#define CHAPTER_6(title, page)                                                     \
    do                                                                             \
    {                                                                              \
        char buf[256];                                                             \
        snprintf(buf, sizeof(buf), "%s%s第 6 章  %s%s...........................", BOLD, BLUE, title, RESET); \
                                                                                   \
        printf("%s", buf);                                                         \
        print_dots(buf, RIGHT_ALIGN_POS - 3);                                      \
        printf(" %d\n", page);                                                     \
    } while (0)

// 定义一级小节宏
#define CHAPTER_6_SUB_SECTION_1(num, title, page)             \
    do                                                        \
    {                                                         \
        char buf[256];                                        \
        snprintf(buf, sizeof(buf), "  6.%d  %s", num, title); \
        printf("%s", buf);                                    \
        print_dots(buf, RIGHT_ALIGN_POS - 3);                 \
        printf(" %d\n", page);                                \
    } while (0)

// 定义二级小节宏
#define CHAPTER_6_SUB_SECTION_2(num, title, page)                 \
    do                                                            \
    {                                                             \
        char buf[256];                                            \
        snprintf(buf, sizeof(buf), "    6.1.%d  %s", num, title); \
        printf("%s", buf);                                        \
        print_dots(buf, RIGHT_ALIGN_POS - 3);                     \
        printf(" %d\n", page);                                    \
    } while (0)

// 定义思考训练和参考文献宏
#define CHAPTER_6_EXERCISE_REF(title, page)      \
    do                                           \
    {                                            \
        char buf[256];                           \
        snprintf(buf, sizeof(buf), "%s", title); \
        printf("%s", buf);                       \
        print_dots(buf, RIGHT_ALIGN_POS - 3);    \
        printf(" %d\n", page);                   \
    } while (0)

void display_chapter6();
// int main() {

//     return 0;
// }
#endif