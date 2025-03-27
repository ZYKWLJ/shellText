// #include "my.h"

// void my()
// {
//     printf("my~~~\n");
//     printf(str);
// }

/**
 * 说白了就是这个问题，这是源文件：

# ifndef _MY_H_
# define _MY_H_
# include <stdio.h>
#include "main.h"
void my();
#endif

#include "my.h"

void my()
{
    printf("my~~~\n");
    printf(str);
}

#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include "my.h"
#endif

#include "main.h"
char *str = "123456789";
int main()
{
    my();
}
这里my.c就一直报错：identifier "str" is undefined
 * 
 */

#include "my.h"

void my()
{
    printf("my~~~\n");
    // 使用 str 变量
    printf("%s\n", str);
}