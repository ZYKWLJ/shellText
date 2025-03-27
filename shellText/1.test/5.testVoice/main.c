#include <stdio.h>
#include <stdlib.h>

// 发出声音的函数
void playSoundOnLinux() {
    // 使用 system 函数调用系统的 beep 命令，设置频率为 800Hz，持续时间 300 毫秒
    int status = system("beep -f 800 -l 300");
    if (status == -1) {
        perror("调用 beep 命令失败");
    }
}

int main() {
    playSoundOnLinux();
    return 0;
}

