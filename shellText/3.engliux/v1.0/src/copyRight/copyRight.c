#include "../../include/copyRight.h"
// 对流层ASCII
// #define TROPOSPHERE_ASCII "                      \u25C6                      \u25C6                      \u25C6\n              \u25C6\u25C6      \u25C6           \u25C6          \u25C6                      \u25C6\n               \u25C6\u25C6     \u25C6           \u25C6\u25C6         \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n               \u25C6\u25C6     \u25C6    \u25C6\u25C6     \u25C6\u25C6\u25C6        \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n         \u25C6     \u25C6\u25C6     \u25C6    \u25C6\u25C6\u25C6     \u25C6\u25C6   \u25C6    \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6\u25C6     \u25C6\n      \u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\u25C6     \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\u25C6 \u25C6   \u25C6      \u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6       \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6           \u25C6\u25C6\u25C6\u25C6\u25C6      \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6  \u25C6\u25C6   \u25C6\u25C6 \u25C6\u25C6  \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6    \u25C6\u25C6     \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6   \u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6      \u25C6    \u25C6 \u25C6\u25C6 \u25C6 \u25C6\u25C6 \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6              \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6\u25C6 \u25C6      \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\n     \u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n     \u25C6\u25C6 \u25C6\u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6   \u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6    \u25C6\u25C6 \u25C6\u25C6       \u25C6\n   \u25C6\u25C6       \u25C6  \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6     \u25C6\n  \u25C6\u25C6        \u25C6\u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6\u25C6  \u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n  \u25C6          \u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6\n              \u25C6\u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6    \u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6    \u25C6       \u25C6\u25C6    \u25C6\n                      \u25C6     \u25C6                \u25C6                      \u25C6\n                      \u25C6                      \u25C6                      \u25C6\n\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\n\n"
// #define TROPOSPHERE_ASCII "                      \u25C6                      \u25C6                      \u25C6\n              \u25C6\u25C6      \u25C6           \u25C6          \u25C6                      \u25C6\n               \u25C6\u25C6     \u25C6           \u25C6\u25C6         \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n               \u25C6\u25C6     \u25C6    \u25C6\u25C6     \u25C6\u25C6\u25C6        \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n         \u25C6     \u25C6\u25C6     \u25C6    \u25C6\u25C6\u25C6     \u25C6\u25C6   \u25C6    \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6\u25C6     \u25C6\n      \u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\u25C6     \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\u25C6 \u25C6   \u25C6      \u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6       \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6           \u25C6\u25C6\u25C6\u25C6\u25C6      \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6  \u25C6\u25C6   \u25C6\u25C6 \u25C6\u25C6  \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6    \u25C6\u25C6     \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6   \u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6      \u25C6    \u25C6 \u25C6\u25C6 \u25C6 \u25C6\u25C6 \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6              \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6\u25C6 \u25C6      \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\n     \u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n     \u25C6\u25C6 \u25C6\u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6   \u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6    \u25C6\u25C6 \u25C6\u25C6       \u25C6\n   \u25C6\u25C6       \u25C6  \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6     \u25C6\n  \u25C6\u25C6        \u25C6\u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6\u25C6  \u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n  \u25C6          \u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6\n              \u25C6\u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6    \u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6    \u25C6       \u25C6\u25C6    \u25C6\n                      \u25C6     \u25C6                \u25C6                      \u25C6\n                      \u25C6                      \u25C6                      \u25C6\n\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\n\n"
// #define TROPOSPHERE_ASCII  \
// "                           #            \n" \
// "            ##      #     ####       ############# \n" \
// " #######    ##      ## ##########    ##        ##  \n" \
// " #   ##     ## #    ##    ##         ##        ##  \n" \
// "  #  ## ########  #      ##  ##      ############  \n" \
// "  #  ##     ##     #    ##    ##     ##        #   \n" \
// "   # #  #   ##     ##  ##########    ##         #  \n" \
// "   ###  ##  ##     ## # ## # # #     ## #########  \n" \
// "    #    ## ##       #  ## # ##      ##          # \n" \
// "   ###   ## ##       #  ## # ##      ############# \n" \
// "   # ##  #  ##    # ##  ## # ##      ##   ## #     \n" \
// "  ##  ##    ##     ##   ## # ##      ##  ##   #    \n" \
// "  #   #     ##     ##   ## # ## #    #   ##   ##   \n" \
// " #          ##     ### ##  # ## #   ##  ##     ##  \n" \
// "          ####      ## #   # ####   #  ########### \n" \
// "            #       # #    #  ##   #    #       #   \n\n"

// // 定义一个宏表示图形的纯字体内容
// #define TROPOSPHERE_ASCII \
// "  ______             _ _                  \n" \
// " |  ____|           | (_)                 \n" \
// " | |__   _ __   __ _| |_ _   _ _ __ __  __\n" \
// " |  __| | '_ \\ / _` | | | | | | '_ \\ \\ / /\n" \
// " | |____| | | | (_| | | | |_| | | | |>  < \n" \
// " |______|_| |_|\__, |_|_|\__,_|_| |_/_/\\_\\\n" \
// "                __/ |                      \n" \
// "               |___/                       \n\n"

#define TROPOSPHERE_ASCII                                            \
    "  ______                   _   _                        \n"     \
    " |  ____|                 | | (_)                       \n"     \
    " | |__     _ __     __ _  | |  _   _ __    _   _  __  __\n"     \
    " |  __|   | '_ \\   / _` | | | | | | '_ \\  | | | | \\ \\//\n"  \
    " | |____  | | | | | (_| | | | | | | | | | | |_| |  >  < \n"     \
    " |______| |_| |_|  \\__, | |_| |_| |_| |_|  \\__,_| /_/\\_\\\n" \
    "                    __/ |                               \n"     \
    "                   |___/    \n"
#define COPYRIGHT_ASCII "TroposphereQuerySoftware Ver 1.0 Made by EthanYankang \
2025,03,25.\n    School of Physics,Xidian University.All rights reserved.\n\n"

// 打印函数声明
void acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep);
void copyright_print(const char *matched_machine, const char *author, int sleep_time, int interval_num_to_sleep);
void fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep);

// 徽标打印函数定义
void acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep)
{
    fast_Dynamic_input_green(define_str, sleep_time, interval_num_to_sleep);
}

// 版权打印函数定义
void print()
{
    // printf("\n\n\n");
    fast_Dynamic_input_green(TROPOSPHERE_ASCII, 1, 1);
    printf("\n\n");
    fast_Dynamic_input_green(COPYRIGHT_ASCII, 1, 1);
    printf("\n\n\n");
}

// 动态打印函数定义
void fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep)
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