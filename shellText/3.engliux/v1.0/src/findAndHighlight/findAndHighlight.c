#include "../../include/findAndHighlight.h"
int find_and_highlight(const char **s, int s_size, char *t)
{
    // printf("%s进入高亮函数%s\n", BOLD, BLUE);
    int flag = 0;
    int first = 1;
    int count = 0;
    for (int i = 0; i < s_size; i++)
    {
        const char *p = s[i];
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
            // printf("%s%s\n第%d搜索结果:%s\n", BOLD, BLUE, i + 1, RESET);
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
                    flag = 1;
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
    return flag; // 判断是否找到！
}

// 计算部分匹配表（next 数组）
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP 搜索算法
int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(sizeof(int) * M);
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            count++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    free(lps);
    return count;
}

// 在字符串数组 s 中查找字符串 t，返回匹配的条数
int find_if_exist(const char **s, int s_size, char *t)
{
    int total_count = 0;
    for (int i = 0; i < s_size; i++)
    {
        total_count += KMPSearch(t, (char *)s[i]);
    }
    return total_count;
}

// int main()
// {
//     // char *s[] = {"ABCDDAB", "ABC","ABDCG","AD", "AM"};
//     // char t[] = "AB";
//     const char *s[] = {"你好啊，你在干什么", "大家好", "你人真好", "使得", "江口", "好了不起的人啊", "对流层的人呢！"};
//     const char *t = "好";
//     int s_size = sizeof(s) / sizeof(s[0]); // 每一个指针的大小相等！所以这里可以借此得到长度！
//     printf("存在%d条\n", find_if_exist(s, s_size, t));
//     find_and_highlight(s, s_size, t);
//     return 0;
// }