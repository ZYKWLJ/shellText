# include "../../include/similarInstructions.h"
// 计算两个字符串的重复字符数
int count_common_chars(const char *str1, const char *str2)
{
    int common = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int visited[len2];//如果正确的指令被访问过了，就置为1，否则为0！正确的！
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (tolower(str1[i]) == tolower(str2[j]) && !visited[j]/*防止重复访问*/)
            {
                common++;
                visited[j] = 1;
                break;
            }
        }
    }
    return common;
}

// 查找相似命令
void find_similar_commands(char *input)
{
    int input_len = strlen(input);
    int found = 0;
    // printf("指令集长度:%d\n", sizeof(instructions_all)/sizeof(instructions_all[0]));
    for (int i = 0; i < 28; i++)
    {
        int common = count_common_chars(input, instructions_all[i]);
        if (common >input_len / 2)//只要超过一半正确的就认为命令是相似的！
        {
            if (!found)
            {
                printf("你可能想输入的命令是：\n");
                found = 1;
            }
            printf(YELLOW "%s\t" RESET, instructions_all[i]);
        }
    }
    if (!found)
    {
        printf("未找到相似命令。\n");
    }
    else
    {
        printf("\n");
    }
}

// int main()
// {
//     while (1)
//     {
//         char input[100];
//         printf("请输入命令：");
//         fgets(input, sizeof(input), stdin);
//         input[strcspn(input, "\n")] = 0; // 去除换行符

//         find_similar_commands(input);
//     }
//     return 0;
// }