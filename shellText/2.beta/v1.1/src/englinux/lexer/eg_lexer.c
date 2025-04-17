#include "../../../include/englinux/lexer/eg_lexer.h"


void lexer(char *str, char *token[100], int *token_num)
{
    char *ptr = strtok(str, " "); // 自动分割，消除空格！这是一个很好的函数！它的本质是将匹配到的第一个分隔符替换为\0，然后返回一个指向该分隔符之前的字符串的指针。
    token[0] = ptr;
    int i = 1;
    while (ptr)
    {
        ptr = strtok(NULL, " ");
        token[i] = ptr;
        i++;
    }
    token[i] = NULL;
    *token_num = i - 1;
    // for(int i=0;token[i];i++){
    //     // printf("token[%d]=%s\n",i,token[i]);
    // }
}
