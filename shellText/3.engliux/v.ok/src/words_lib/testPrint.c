#include <stdio.h>
#include <stdlib.h>
#include "../../include/words_lib/cet4.h"
#include "../../include/words_lib/cet6.h"
extern word_entry *cet4[100];
extern word_entry *cet6[100];
int main()
{
    for (int i = 0; cet6[i]; i++)//a~z中的其中一个
    {
        for (int j = 0; strcmp(cet6[i][j].index,"-1"); j++)//遍历这个数组
        {
            printf("%-30s", cet6[i][j].index);
            printf("%-30s", cet6[i][j].word);
            printf("%-30s", cet6[i][j].phonetic);
            printf("%-30s\n", cet6[i][j].meaning);
        }
    }
}