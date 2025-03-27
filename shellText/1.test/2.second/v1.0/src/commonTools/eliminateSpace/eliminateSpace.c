#include "EliminateSpace.h"

void eliminateSpace(char *str)
{
    int len = strlen(str);
    char *start = str;         // 首指针
    char *end = str + len - 1; // 尾指针

    // 去除首尾空格
    while (*start == ' ' && start < end)
    {
        start++;
    }
    while (*end == ' ' && start < end)
    {
        end--;
    }

    // 连续空格压缩
    char *slow = start; // 慢指针
    char *fast = slow;  // 快指针
                        // while (fast <= end) {
                        //     if (*fast == ' ' && *slow == ' ') {
                        //         fast++;
                        //     } else {
                        //         *slow = *fast;
                        //         slow++;
                        //         fast++;
                        //     }
                        // }
    while (fast <= end)//分组循环！
    {
        if (*fast == ' ')
        {
            // 当遇到空格时，保留一个空格
            *slow = *fast;
            slow++;
            // 跳过连续的空格
            while (*(fast + 1) == ' ' && fast + 1 <= end)
            {
                fast++;
            }
        }
        else
        {
            *slow = *fast;
            slow++;
        }
        fast++;
    }
    *slow = '\0';
    // printf("len(str)=%d\n", slow - start + 1);//调试长度正确吗？
    // 移动处理后的字符串到原字符串开头
    memmove(str, start, slow - start + 1); // 这里需要多复制一个\0

    // 全部转化为小写
    len = slow - start; // 更新字符串长度
    for (int i = 0; i < len; i++)
    {
        if (isupper((unsigned char)str[i]))
        {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
}