#include "../../../include/shellText/text_find.h"
int find_and_highlight(char **s, int s_size, char *t)
{
    int flag=0;
    int first = 1;
    int count = 0;
    for (int i = 0; i < s_size; i++)
    {
        char *p = s[i];
        int found = 0;
        while (*p)
        {
            if (strncmp(p, t, strlen(t)) == 0)
            {
                found = 1;
                break;
            }
            p++;
        }
        if (found)
        {
            printf("%s%s\n第%d页搜索结果:%s\n", BOLD,BLUE,i+1,RESET);
            if (!first)
            {
                // putchar(',');
                // puts("");
            }
            p = s[i];
            while (*p)
            {
                if (strncmp(p, t, strlen(t)) == 0)
                {

                    printf("%s%s%s%s", BOLD, YELLOW, t, RESET);
                    p += strlen(t);
                    flag=1;
                }
                else
                {
                    putchar(*p);
                    p++;
                }
            }
            first = 0;
            printf("\n\n");
        }
    }
    // printf("\n");
    return flag;//判断是否找到！
}