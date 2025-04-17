#include "../../../include/englinux/display/eg_endSay.h"

// 信号处理函数
void eg_exit_signal_handler(int signum)
{
    if (signum == SIGINT)
    {
        printf("\n%s%s退出程序！%s\n", RED, BOLD, RESET);
        printf(ENDSAY);
        exit(0);
    }
}
// 测试函数！
// int main() {
//     // 注册信号处理函数
//     signal(SIGINT, signal_handler);

//     printf("程序正在运行，按 Ctrl + C 退出...\n");
//     while (1) {
//         // 程序持续运行
//         puts("i am running...");
//         sleep(1);
//     }

//     return 0;
// }
