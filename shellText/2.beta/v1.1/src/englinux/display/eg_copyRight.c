#include "../../../include/englinux/display/eg_copyRight.h"
#define ENGLINUX_ASCII                                            \
    "  ______                   _   _                        \n"     \
    " |  ____|                 | | (_)                       \n"     \
    " | |__     _ __     __ _  | |  _   _ __    _   _  __  __\n"     \
    " |  __|   | '_ \\   / _` | | | | | | '_ \\  | | | | \\ \\//\n"  \
    " | |____  | | | | | (_| | | | | | | | | | | |_| |  >  < \n"     \
    " |______| |_| |_|  \\__, | |_| |_| |_| |_|  \\__,_| /_/\\_\\\n" \
    "                    __/ |                               \n"     \
    "                   |___/    \n"
#define ENGLINUX_COPYRIGHT_ASCII "TroposphereQuerySoftware Ver 1.0 Made by EthanYankang \
2025,03,25.\n    School of Physics,Xidian University.All rights reserved.\n\n"

// 打印函数声明
void eg_acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep);
// void copyright_print(const char *matched_machine, const char *author, int sleep_time, int interval_num_to_sleep);
void eg_fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep);

// 徽标打印函数定义
void eg_acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep)
{
    eg_fast_Dynamic_input_green(define_str, sleep_time, interval_num_to_sleep);
}

// 版权打印函数定义
void _eg_print_copyright()
{
    // printf("\n\n\n");
    eg_fast_Dynamic_input_green(ENGLINUX_ASCII, 1, 1);
    printf("\n\n");
    eg_fast_Dynamic_input_green(ENGLINUX_COPYRIGHT_ASCII, 1, 1);
    printf("\n\n\n");
}

// 动态打印函数定义
void eg_fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep)
{
    int len = strlen(input);

    for (size_t i = 0; i < len; ++i)
    {
        printf("%s%s%c%s", GREEN, BOLD, input[i], RESET);
        fflush(stdout); // Ensure character is immediately printed
        if (i % interval_num_to_sleep == 0)
        {
            usleep(sleep_time * 250); // usleep 的单位是微秒，将毫秒转换为微秒
        }
    }
}

// int main(int argc, char const *argv[])
// {
//     print();
//     return 0;
// }