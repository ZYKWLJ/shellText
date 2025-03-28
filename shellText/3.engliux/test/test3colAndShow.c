#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// 颜色宏定义
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

// 假设的搜索函数
int search_word(char *token, int library, int search_mod, int first_show, int second_show, int third_show)
{
    // 这里只是一个占位实现，实际应根据需求完成
    printf("搜索单词: %s, 词库: %d, 搜索模式: %d, 第一列显示: %d, 第二列显示: %d, 第三列显示: %d\n", token, library, search_mod, first_show, second_show, third_show);
    return 0;
}

// 去除字符串两端的空格
void trim(char *str)
{
    char *end;
    // 去除开头空格
    while (isspace((unsigned char)*str))
        str++;
    // 去除结尾空格
    if (*str)
    {
        end = str + strlen(str) - 1;
        while (end > str && isspace((unsigned char)*end))
            end--;
        end[1] = '\0';
    }
}

// 帮助列表函数
void help_list()
{
    printf("帮助信息...\n");
}

// 清屏函数
void clear()
{
    system("clear"); // 假设是在类 Unix 系统上，Windows 可以改为 system("cls");
}

// 模拟的信号处理函数
void exit_signal_handler(int sig)
{
    printf("退出程序！\n");
    exit(0);
}

// 查找相似命令函数
void find_similar_commands(char *full_command)
{
    printf("未找到相似命令\n");
}

void execute(char *str)
{
    trim(str);
    char full_command[256] = {0};
    strcpy(full_command, str);

    // 分割命令为单词
    char *token = strtok(str, " ");
    if (token == NULL)
    {
        printf("提示：命令不存在！\n请重新输入！\n");
        return;
    }

    // 1.判读find指令
    if (strcasecmp(token, "find") == 0 || strcasecmp(token, "f") == 0)
    {
        token = strtok(NULL, " ");
        // 仅有f或者find时，提示输入要查找的单词
        if (token == NULL)
        {
            printf("%s%s请输入要查找的单词！%s\n", RED, BOLD, RESET);
            return;
        }
        // 单词形式判断，必须是str、%str、str%、%str% 的形式，并且 str 只能全是字母，不是则直接报错。
        else
        {
            int is_valid = 1;
            int len = strlen(token);
            if (len > 0)
            {
                if (token[0] == '%' && token[len - 1] == '%')
                {
                    // %str% 形式
                    for (int i = 1; i < len - 1; i++)
                    {
                        if (!isalpha((unsigned char)token[i]))
                        {
                            is_valid = 0;
                            break;
                        }
                    }
                }
                else if (token[0] == '%')
                {
                    // %str 形式
                    for (int i = 1; i < len; i++)
                    {
                        if (!isalpha((unsigned char)token[i]))
                        {
                            is_valid = 0;
                            break;
                        }
                    }
                }
                else if (token[len - 1] == '%')
                {
                    // str% 形式
                    for (int i = 0; i < len - 1; i++)
                    {
                        if (!isalpha((unsigned char)token[i]))
                        {
                            is_valid = 0;
                            break;
                        }
                    }
                }
                else
                {
                    // str 形式
                    for (int i = 0; i < len; i++)
                    {
                        if (!isalpha((unsigned char)token[i]))
                        {
                            is_valid = 0;
                            break;
                        }
                    }
                }
            }
            else
            {
                is_valid = 0;
            }

            if (!is_valid)
            {
                printf("%s%s无效的查找参数格式！(输入%s%shelp%s查看手册)\n", RED, BOLD, RESET, BOLD, YELLOW, RESET);
                return;
            }
        }

        int library = 0;
        int search_mod = 0;
        int first_show = 1, second_show = 0, third_show = 3; // 默认显示单词和释义

        char *third_token = strtok(NULL, " ");
        if (third_token != NULL)
        {

            if (third_token[0] == '-')
            {
                // 检查 - 后面是否为数字
                if (!isdigit((unsigned char)third_token[1]))
                {
                    printf("%s%s非数字！请输入有效的数字词库编号。(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                    return;
                }
                // 判断是否是 -4 或者 -6
                library = atoi(third_token + 1);
                if (library != 4 && library != 6)
                {
                    printf("%s%s当前%d库暂未录入！%s\n", RED, BOLD, library, RESET);
                    return;
                }
                if (library <= 0)
                {
                    printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("find "), RESET, BOLD, RED, RESET);
                    return;
                }
            } // 第三个指令不以-开头，报错！
            else
            {
                printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("find "), RESET, BOLD, RED, RESET);
                return;
            }
        }
        else // 第三个指令允许为空！为空就没有第四个指令的事了，返回！
        {
            return;
        }
        // 判断第四个指令是否以-开头
        char *fourth_token = strtok(NULL, " ");
        if (fourth_token != NULL)
        {
            int len = strlen(fourth_token);
            int has_dash = 0;
            if (fourth_token[0] == '-')
            {
                has_dash = 1;
                fourth_token++;
                len--;
            }
            else
            {
                printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                return; // 指令出错，必须以-开头！
            }
            // 只能最多显示3列，超出直接报错！
            if (len > 3)
            {
                printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                return;
            }
            // 补齐到3位
            char padded_token[4] = "000";
            strncpy(padded_token + 3 - len, fourth_token, len);

            // 检查每个字符是否为 0 - 3
            for (int i = 0; i < 3; i++)
            {
                if (padded_token[i] < '0' || padded_token[i] > '3')
                {
                    printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                    return;
                }
            }

            first_show = padded_token[0] - '0';
            second_show = padded_token[1] - '0';
            third_show = padded_token[2] - '0';

            if ((first_show + second_show + third_show == 0))
            {
                printf("%s%s无效的显示选项！(输入%s%shelp%s查看手册)\n", RED, BOLD, BOLD, RED, RESET);
                return;
            }
        }
        else
        {
            // 如果没有第四个指令，默认显示单词和释义
            first_show = 1;
            second_show = 0;
            third_show = 3;
        }

        // 这里是返回条数的判断
        // 精确查找
        if (strstr(token, "%") == NULL)
        {
            search_mod = 1; // 1代表查找单词
        }
        else if (token[0] == '%' && token[strlen(token) - 1] == '%')
        {
            // 去除前后的 %
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token + 1, len - 2);
                new_token[len - 2] = '\0';
                search_mod = 2; // 2代表查找包含单词
                token = new_token;
            }
        }
        else if (token[strlen(token) - 1] == '%')
        {
            // 查找以特定前缀结尾的单词
            // 因为%在后面，所以是前缀
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token, len - 1);
                new_token[len - 1] = '\0';
                search_mod = 3; // 3代表查找以单词为前缀
                token = new_token;
            }
        }
        else if (token[0] == '%')
        {
            // 查找以特定后缀结尾的单词
            // 因为%在前面，所以是后缀
            size_t len = strlen(token);
            char *new_token = (char *)malloc(len - 1);
            if (new_token != NULL)
            {
                strncpy(new_token, token + 1, len - 1);
                new_token[len - 1] = '\0';
                search_mod = 4; // 4代表查找以单词为后缀
                token = new_token;
            }
        }

        search_word(token, library, search_mod, first_show, second_show, third_show);
    }
    // 2.判断exit指令
    else if (strcasecmp(token, "exit") == 0)
    {
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            // printf("%s%s退出程序！%s\n", RED, BOLD, RESET);
            exit_signal_handler(1); // 和ctrl+c一样的效果
        }
        else
        {
            printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command + strlen("exit "), RESET, BOLD, RED, RESET);
        }
    }
    // 3.判断help指令
    else if (strcasecmp(token, "help") == 0)
    {
        help_list();
    }
    // 4.判断clear指令
    else if (strcasecmp(token, "clear") == 0)
    {
        clear();
    }
    // 4.判断其他指令
    else
    {
        printf("%s%s%s%s--错误指令！(输入%s%shelp%s查看手册)\n", RED, BOLD, full_command, RESET, BOLD, RED, RESET);
        find_similar_commands(full_command);
    }
}

// int main()
// {
//     while (1)
//     {
//         char str[256] = {0};
//         fgets(str, sizeof(str), stdin);
//         if (str[strlen(str) - 1] == '\n')
//         {
//             str[strlen(str) - 1] = '\0';
//         }
//         execute(str);
//     }
// }

// 生成随机字符串
void generate_random_string(char *str, int length)
{
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < length; i++)
    {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    str[length] = '\0';
}

// 生成随机命令
void generate_random_command(char *command)
{
    char word[20];
    int word_length = rand() % 10 + 1;
    generate_random_string(word, word_length);

    // 随机决定是否添加 %
    int add_percent = rand() % 4;
    switch (add_percent)
    {
    case 0:
        // 不添加 %
        break;
    case 1:
        // %str
        sprintf(command, "find %%%s", word);
        break;
    case 2:
        // str%
        sprintf(command, "find %s%%", word);
        break;
    case 3:
        // %str%
        sprintf(command, "find %%%s%%", word);
        break;
    }
    if (add_percent == 0)
    {
        sprintf(command, "find %s", word);
    }

    // 随机决定是否添加 -4 或 -6
    int add_num = rand() % 2;
    if (add_num)
    {
        int num = (rand() % 2) ? 4 : 6;
        sprintf(command + strlen(command), " -%d", num);
    }

    // 随机决定是否添加显示选项
    int add_display = rand() % 2;
    if (add_display)
    {
        int first = rand() % 4;
        int second = rand() % 4;
        int third = rand() % 4;
        sprintf(command + strlen(command), " %d%d%d", first, second, third);
    }
}

int main()
{
    srand(time(NULL));
    char command[256];
    int COMMOD_NUM = 1000000;
    for (int i = 0; i < COMMOD_NUM; i++)
    {
        puts("");
        char str0[256] = {0};

        generate_random_command(command);
        strcpy(str0, command);
        printf("第%s%s%d%s条测试命令--\t%s%s%s%s\ttesting\n", BLUE, BOLD, i, RESET, BLUE, BOLD, command, RESET);
        execute(command);
        printf("第%s%s%d%s条测试命令--\t%s%s%s%s\t正常通过!\n", BLUE, BOLD, i, RESET, BLUE, BOLD, str0, RESET);
    }
    puts("");
    printf("%s%s%d条测试正常通过!%s", BLUE, BOLD, COMMOD_NUM, RESET);
    return 0;
}
// 请你按照find str [-num] [-num]的命令形式随机生成命令，模拟命令判断健壮性，随机生成10000条，看呢能不能正常运行