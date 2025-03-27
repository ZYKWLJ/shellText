# ifndef CHAPTER1_H
# define CHAPTER1_H
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include "common.h"
// # include "color.h"

// 定义章节宏
#define CHAPTER_1(title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "%s%s第 1 章  %s%s.................................................",BOLD,BLUE, title,RESET); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义一级小节宏
#define CHAPTER_1_SUB_SECTION_1(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "  %d.%d  %s", 1, num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义二级小节宏
#define CHAPTER_1_SUB_SECTION_2(num, title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "    %d.%d.%d  %s", 1, 2, num, title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)

// 定义思考训练和参考文献宏
#define CHAPTER_1_EXERCISE_REF(title, page) \
    do { \
        char buf[256]; \
        snprintf(buf, sizeof(buf), "%s", title); \
        printf("%s", buf); \
        print_dots(buf, RIGHT_ALIGN_POS - 3); \
        printf(" %d\n", page); \
    } while(0)
void display_chapter1() ;
// int main() {
    

//     return 0;
// }
#endif