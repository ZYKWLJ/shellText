#include "../../include/find.h"
void find_and_highlight(char **s, int s_size, char *t)
{
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
            printf("第%d条搜索结果:\n", ++count);
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
    printf("\n");
}