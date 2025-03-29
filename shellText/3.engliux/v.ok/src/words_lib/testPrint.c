#include <stdio.h>
#include <stdlib.h>
#include "../../include/words.h"
// extern word_entry **library[];//这里仅仅需要三维数组即可。一维数组是单个数据的维度增加！这里的单个数据就是结构体，所以类似于{{},{}}其实是一维度数组！
extern word_entry *cet6[100];
// extern word_entry *cet4[100];
// int main()
// {
//     for (int i = 0; cet6[i]; i++)//a~z中的其中一个
//     {
//         for (int j = 0; cet6[i][j].index; j++)//遍历这个数组
//         {
//             printf("%-30s", cet6[i][j].index);
//             printf("%-30s", cet6[i][j].word);
//             printf("%-30s", cet6[i][j].phonetic);
//             printf("%-30s\n", cet6[i][j].meaning);
//         }
//     }
// }
//测试命令：gcc -I/home/eyk/1code/shellText/shellText/3.engliux/v.ok/include/words_lib/cet6 testPrint.c /home/eyk/1code/shellText/shellText/3.engliux/v.ok/src/words_lib/cet6.c /home/eyk/1code/shellText/shellText/3.engliux/v.ok/src/words_lib/cet6/cet6_*.c -o main