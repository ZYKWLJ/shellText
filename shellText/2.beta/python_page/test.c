#include "pages.h"
extern char *all_pages[500];
int main()
{
    while (1)
    {

        int page;
        printf("请输入要查看的页数:");
        if(scanf("%d", &page)!=1){
            printf("输入错误,请输入数字\n");
            while(getchar()!='\n');
            continue;
        }
        
        if (page > 430 || page < 0)
        {
            printf("页数超出范围\n");
            continue;
        }
        else
        {
            printf("%s", all_pages[page-1]);
        }
        while(getchar()!='\n');
        printf("\n");
    }
}