#include <stdio.h>
#include "../v1.0/include/words_lib/lib4_3/e_4.h"

extern const char *e_4[][3];

int main(){
    int count=0;
    for (int i = 0; e_4[i][0] != NULL; i++) {
        for (int j = 0; j < 3 && e_4[i][j] != NULL; j++) {
            if(j!=1)
           printf("%-40s", e_4[i][j]);
           
        }count++;
        puts("");
    }
    printf("共有%d条数据......\n",count);
    return 0;
}
// earthquake                              /ˈɜːrθkweɪk/                       n. 地震；大动荡
// /ˈedɪtər/                            
// /efff/edɪtər/                            
// n. 眼睛；视力；眼光；见解，观点vt. 注视，看n. (Eye)人名；(德)艾厄；(英)艾