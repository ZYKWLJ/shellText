#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h> // for strcasecmp
#include <ctype.h>
#include <string.h>
#define BLUE "\033[34m" // 蓝色专用于章节名
#include <time.h>
#define RED "\033[31m"
#define BOLD "\033[1m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void trim(char *str)
{
    int len = strlen(str);
    int start = 0;
    int end = len - 1;

    // 去除开头的空白字符
    while (start <= end && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
    {
        start++;
    }

    // 去除结尾的空白字符
    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
    {
        end--;
    }

    // 将处理后的字符串移到开头
    int i;
    for (i = 0; start <= end; i++, start++)
    {
        str[i] = str[start];
    }
    str[i] = '\0';
}
int is_all_alpha(char *token, int begin, int end)
{
    // %str% 形式
    for (int i = begin; i < end; i++)
    {
        if (!isalpha((unsigned char)token[i]))
        {
            return 0;
            break;
        }
    }
    return 1;
}
void search_word(const char *word, int library, int search_mod,
                 int first_show, int second_show, int third_show)
{
    // 这里只是一个占位实现，实际应根据需求完成
    printf("搜索单词: %s, 词库: %d, 搜索模式: %d, 第一列显示: %d, 第二列显示: %d, 第三列显示: %d\n", word, library, search_mod, first_show, second_show, third_show);
    // return 0;
}
void help_list(void){
    printf("-------------------------------帮助手册-------------------------------\n");
}
void clear(void){
    system("clear");
}
void find_similar_commands(const char *cmd){
    // 这里只是一个占位实现，实际应根据需求完成
    printf("查找相似命令: ------------%s\n", cmd);
    // return 0;
}
void exit_signal_handler(int sig){
    printf("收到退出信号，正在退出...\n");
}

void execute(char *str)
{
    // 参数检查
    if (str == NULL || *str == '\0')
    {
        printf("错误：空命令！\n");
        return;
    }

    // 去除前后空格并备份原始命令
    trim(str);
    char full_command[256] = {0};
    strncpy(full_command, str, sizeof(full_command) - 1);

    // 分割命令
    char *command = strtok(str, " ");
    if (command == NULL)
    {
        printf("提示：命令不存在！\n请重新输入！\n");
        return;
    }

    // 处理find/f命令
    if (strcasecmp(command, "find") == 0 || strcasecmp(command, "f") == 0)
    {
        char *word = strtok(NULL, " ");
        if (word == NULL)
        {
            printf("%s%s请输入要查找的单词！%s\n", RED, BOLD, RESET);
            return;
        }

        // 验证单词格式
        int is_valid = 0;
        int len = strlen(word);
        int start = 0, end = len;

        if (len > 0)
        {
            if (word[0] == '%')
                start++;
            if (len > 1 && word[len - 1] == '%')
                end--;

            if (end > start)
            {
                is_valid = 1;
                for (int i = start; i < end; i++)
                {
                    if (!isalpha((unsigned char)word[i]))
                    {
                        is_valid = 0;
                        break;
                    }
                }
            }
        }

        if (!is_valid)
        {
            printf("%s%s无效的查找参数格式！%s(输入%s%shelp%s查看手册)\n",
                   RED, BOLD, RESET, BOLD, YELLOW, RESET);
            return;
        }

        // 处理库参数
        int library = 0;
        char *lib_token = strtok(NULL, " ");
        if (lib_token != NULL)
        {
            if (lib_token[0] != '-' || !isdigit((unsigned char)lib_token[1]))
            {
                printf("%s%s无效的词库参数！%ss(输入%s%shelp%s查看手册)\n",
                       RED, BOLD, RESET, BOLD, YELLOW, RESET);
                return;
            }

            library = atoi(lib_token + 1);
            if (library != 4 && library != 6)
            {
                printf("%s%s当前仅支持4和6词库！%s\n", RED, BOLD, RESET);
                return;
            }
        }

        // 处理显示选项
        int first_show = 1, second_show = 0, third_show = 3;
        char *opt_token = strtok(NULL, " ");
        if (opt_token != NULL)
        {
            if (opt_token[0] != '-' || strlen(opt_token) > 4)
            {
                printf("%s%s无效的显示选项！%s(输入%s%shelp%s查看手册)\n",
                       RED, BOLD, RESET, BOLD, YELLOW, RESET);
                return;
            }

            char options[4] = "000";
            strncpy(options + 3 - (strlen(opt_token) - 1), opt_token + 1, strlen(opt_token) - 1);

            for (int i = 0; i < 3; i++)
            {
                if (options[i] < '0' || options[i] > '3')
                {
                    printf("%s%s无效的显示选项！(0-3)%s\n", RED, BOLD, RESET);
                    return;
                }
            }

            first_show = options[0] - '0';
            second_show = options[1] - '0';
            third_show = options[2] - '0';

            if (first_show + second_show + third_show == 0)
            {
                printf("%s%s至少选择一列显示！%s\n", RED, BOLD, RESET);
                return;
            }
        }

        // 确定搜索模式
        int search_mod = 0;
        if (strchr(word, '%') == NULL)
        {
            search_mod = 1; // 精确匹配
        }
        else
        {
            if (word[0] == '%' && word[len - 1] == '%')
            {
                search_mod = 2; // 包含
                memmove(word, word + 1, len - 2);
                word[len - 2] = '\0';
            }
            else if (word[len - 1] == '%')
            {
                search_mod = 3; // 前缀
                word[len - 1] = '\0';
            }
            else if (word[0] == '%')
            {
                search_mod = 4; // 后缀
                memmove(word, word + 1, len - 1);
                word[len - 1] = '\0';
            }
        }

        // 执行搜索
        search_word(word, library, search_mod, first_show, second_show, third_show);
    }
    // 处理exit命令
    else if (strcasecmp(command, "exit") == 0)
    {
        if (strtok(NULL, " ") == NULL)
        {
            exit_signal_handler(1);
        }
        else
        {
            printf("%s%s无效的exit命令！%s\n", RED, BOLD, RESET);
        }
    }
    // 处理help命令
    else if (strcasecmp(command, "help") == 0)
    {
        help_list();
    }
    // 处理clear命令
    else if (strcasecmp(command, "clear") == 0)
    {
        clear();
    }
    // 未知命令
    else
    {
        printf("%s%s未知命令：%s%s(输入%s%shelp%s查看帮助)\n",
               RED, BOLD, full_command, RESET, BOLD,YELLOW, RESET);
        find_similar_commands(full_command);
    }
}


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

// int main()
// {
//     srand(time(NULL));
//     char command[256];
//     int COMMOD_NUM = 1000000;
//     for (int i = 0; i < COMMOD_NUM; i++)
//     {
//         puts("");
//         char str0[256] = {0};

//         generate_random_command(command);
//         strcpy(str0, command);
//         printf("第%s%s%d%s条测试命令--\t%s%s%s%s\ttesting\n", BLUE, BOLD, i, RESET, BLUE, BOLD, command, RESET);
//         execute(command);
//         printf("第%s%s%d%s条测试命令--\t%s%s%s%s\t正常通过!\n", BLUE, BOLD, i, RESET, BLUE, BOLD, str0, RESET);
//     }
//     puts("");
//     printf("%s%s%d条测试正常通过!%s", BLUE, BOLD, COMMOD_NUM, RESET);
//     return 0;
// }

int main(){

    while (1)
    {
        char str[256] = {0};
        fgets(str, sizeof(str), stdin);
        if(str[strlen(str)-1]=='\n'){
            str[strlen(str)-1]='\0';
        }
        char str0[256] = {0};
        strcpy(str0, str);
        printf("第%s%s条测试命令--\t%s%s%s%s\ttesting\n", BLUE, BOLD, BLUE, BOLD, str, RESET);
        execute(str);
        printf("第%s%s条测试命令--\t%s%s%s%s\t正常通过!\n", BLUE, BOLD, BLUE, BOLD, str0, RESET);
    }
}