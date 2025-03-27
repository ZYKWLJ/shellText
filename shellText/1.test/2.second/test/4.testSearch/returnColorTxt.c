#include <stdio.h>
#include <string.h>

#define GREEN "\033[32m"  // 绿色专用于请输入指令提示信息
#define RED "\033[31m"    // 红色专用于错误提示信息
#define BLUE "\033[34m"   // 蓝色专用于章节名
#define PURPLE "\033[35m" // 紫色专用于指引信息
#define YELLOW "\033[33m" // 黄色专用于各个指令执行前缀！
#define RESET "\033[0m"
#define BOLD "\033[1m" // 加粗

// 查找并高亮显示匹配的字符串
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

int main()
{
    // char *s[] = {"ABCDDAB", "ABC","ABDCG","AD", "AM"};
    // char t[] = "AB";
    char *s[] = {"你好啊，你在干什么", "大家好", "你人真好", "使得", "江口", "好了不起的人啊", "对流层的人呢！"};
    char t[] = "好";
    int s_size = sizeof(s) / sizeof(s[0]); // 每一个指针的大小相等！所以这里可以借此得到长度！

    find_and_highlight(s, s_size, t);

    return 0;
}