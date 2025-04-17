#include "../../../include/shellText/text_copyRight.h"
// 对流层ASCII
// #define TROPOSPHERE_ASCII "                      \u25C6                      \u25C6                      \u25C6\n              \u25C6\u25C6      \u25C6           \u25C6          \u25C6                      \u25C6\n               \u25C6\u25C6     \u25C6           \u25C6\u25C6         \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n               \u25C6\u25C6     \u25C6    \u25C6\u25C6     \u25C6\u25C6\u25C6        \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n         \u25C6     \u25C6\u25C6     \u25C6    \u25C6\u25C6\u25C6     \u25C6\u25C6   \u25C6    \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6\u25C6     \u25C6\n      \u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\u25C6     \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\u25C6 \u25C6   \u25C6      \u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6       \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6           \u25C6\u25C6\u25C6\u25C6\u25C6      \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6  \u25C6\u25C6   \u25C6\u25C6 \u25C6\u25C6  \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6    \u25C6\u25C6     \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6   \u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6      \u25C6    \u25C6 \u25C6\u25C6 \u25C6 \u25C6\u25C6 \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6              \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6\u25C6 \u25C6      \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\n     \u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n     \u25C6\u25C6 \u25C6\u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6   \u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6    \u25C6\u25C6 \u25C6\u25C6       \u25C6\n   \u25C6\u25C6       \u25C6  \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6     \u25C6\n  \u25C6\u25C6        \u25C6\u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6\u25C6  \u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n  \u25C6          \u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6\n              \u25C6\u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6    \u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6    \u25C6       \u25C6\u25C6    \u25C6\n                      \u25C6     \u25C6                \u25C6                      \u25C6\n                      \u25C6                      \u25C6                      \u25C6\n\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\n\n"
// #define TROPOSPHERE_ASCII "                      \u25C6                      \u25C6                      \u25C6\n              \u25C6\u25C6      \u25C6           \u25C6          \u25C6                      \u25C6\n               \u25C6\u25C6     \u25C6           \u25C6\u25C6         \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n               \u25C6\u25C6     \u25C6    \u25C6\u25C6     \u25C6\u25C6\u25C6        \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n         \u25C6     \u25C6\u25C6     \u25C6    \u25C6\u25C6\u25C6     \u25C6\u25C6   \u25C6    \u25C6       \u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6\u25C6     \u25C6\n      \u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\u25C6     \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6   \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\u25C6 \u25C6   \u25C6      \u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6       \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6           \u25C6\u25C6\u25C6\u25C6\u25C6      \u25C6      \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6  \u25C6\u25C6   \u25C6\u25C6 \u25C6\u25C6  \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6       \u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6    \u25C6\u25C6     \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6     \u25C6\n     \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6   \u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6      \u25C6\u25C6 \u25C6\u25C6\u25C6\u25C6\u25C6        \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6      \u25C6    \u25C6 \u25C6\u25C6 \u25C6 \u25C6\u25C6 \u25C6\u25C6\u25C6     \u25C6      \u25C6\u25C6              \u25C6\n      \u25C6\u25C6\u25C6  \u25C6\u25C6\u25C6 \u25C6      \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6 \u25C6\u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\n     \u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n     \u25C6\u25C6 \u25C6\u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6\u25C6 \u25C6  \u25C6      \u25C6     \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6        \u25C6\n    \u25C6\u25C6   \u25C6\u25C6    \u25C6      \u25C6     \u25C6\u25C6  \u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6    \u25C6\u25C6 \u25C6\u25C6       \u25C6\n   \u25C6\u25C6       \u25C6  \u25C6      \u25C6  \u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6  \u25C6  \u25C6   \u25C6    \u25C6\u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6     \u25C6\n  \u25C6\u25C6        \u25C6\u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6 \u25C6\u25C6\u25C6 \u25C6\u25C6  \u25C6  \u25C6\u25C6  \u25C6   \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6    \u25C6\n  \u25C6          \u25C6\u25C6\u25C6      \u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6   \u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6\u25C6    \u25C6\n              \u25C6\u25C6      \u25C6    \u25C6\u25C6\u25C6\u25C6    \u25C6  \u25C6\u25C6\u25C6\u25C6\u25C6  \u25C6  \u25C6\u25C6    \u25C6       \u25C6\u25C6    \u25C6\n                      \u25C6     \u25C6                \u25C6                      \u25C6\n                      \u25C6                      \u25C6                      \u25C6\n\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\u25C6\n\n"
#define TROPOSPHERE_ASCII  \
"                           #            \n" \
"            ##      #     ####       ############# \n" \
" #######    ##      ## ##########    ##        ##  \n" \
" #   ##     ## #    ##    ##         ##        ##  \n" \
"  #  ## ########  #      ##  ##      ############  \n" \
"  #  ##     ##     #    ##    ##     ##        #   \n" \
"   # #  #   ##     ##  ##########    ##         #  \n" \
"   ###  ##  ##     ## # ## # # #     ## #########  \n" \
"    #    ## ##       #  ## # ##      ##          # \n" \
"   ###   ## ##       #  ## # ##      ############# \n" \
"   # ##  #  ##    # ##  ## # ##      ##   ## #     \n" \
"  ##  ##    ##     ##   ## # ##      ##  ##   #    \n" \
"  #   #     ##     ##   ## # ## #    #   ##   ##   \n" \
" #          ##     ### ##  # ## #   ##  ##     ##  \n" \
"          ####      ## #   # ####   #  ########### \n" \
"            #       # #    #  ##   #    #       #   \n\n"

#define COPYRIGHT_ASCII "TroposphereQuerySoftware Ver 1.0 Made by EthanYankang \
2025,03,25.\n    School of Physics,Xidian University.All rights reserved.\n\n"

// 打印函数声明
void text_acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep);
// void copyright_print(const char *matched_machine, const char *author, int sleep_time, int interval_num_to_sleep);
void text_fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep);

// 徽标打印函数定义
void text_acsii_troposphere_print(const char *define_str, int sleep_time, int interval_num_to_sleep)
{
    text_fast_Dynamic_input_green(define_str, sleep_time, interval_num_to_sleep);
}

// 版权打印函数定义
void text_print_copyright()
{
    // printf("\n\n\n");
    text_fast_Dynamic_input_green(TROPOSPHERE_ASCII, 1, 1);
    printf("\n\n\n");
    text_fast_Dynamic_input_green(COPYRIGHT_ASCII, 1, 1);
    printf("\n\n\n");
}

// 动态打印函数定义
void text_fast_Dynamic_input_green(const char *input, int sleep_time, int interval_num_to_sleep)
{
    int len = strlen(input);

    for (size_t i = 0; i < len; ++i)
    {
        printf("%s%c%s", GREEN, input[i], RESET);
        fflush(stdout); // Ensure character is immediately printed
        if (i % interval_num_to_sleep == 0)
        {
            usleep(sleep_time * 100); // usleep 的单位是微秒，将毫秒转换为微秒
        }
    }
}

// int main(int argc, char const *argv[])
// {
//     print();
//     return 0;
// }