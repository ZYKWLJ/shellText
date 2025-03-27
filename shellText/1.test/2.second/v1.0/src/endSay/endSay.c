#include "endSay.h"

// 信号处理函数
void exit_signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\n这里将来会做告别语了~~~\n");
        printf(ENDSAY);
        exit(0);
    }
}

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
    