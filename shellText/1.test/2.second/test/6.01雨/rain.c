#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 80
#define RAINDROP_COUNT 40

// 雨滴结构体
typedef struct {
    int x;
    int y;
    int speed;
    char value;
} Raindrop;

// 初始化雨滴
void init_raindrop(Raindrop *raindrop) {
    raindrop->x = rand() % WIDTH;
    raindrop->y = 0;
    raindrop->speed = rand() % 3 + 1;
    raindrop->value = (rand() % 2) ? '0' : '1';
}

// 雨滴下落
void fall(Raindrop *raindrop) {
    raindrop->y += raindrop->speed;
    if (raindrop->y > HEIGHT) {
        init_raindrop(raindrop);
    }
}

// 清屏函数
void clear_screen() {
    printf("\033[2J");
    printf("\033[H");
}

int main() {
    srand(time(NULL));

    // 创建雨滴数组
    Raindrop raindrops[RAINDROP_COUNT];
    for (int i = 0; i < RAINDROP_COUNT; i++) {
        init_raindrop(&raindrops[i]);
    }

    // 主循环
    while (1) {
        clear_screen();

        // 初始化屏幕字符数组
        char screen[HEIGHT][WIDTH];
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                screen[y][x] = ' ';
            }
        }

        // 更新雨滴位置并绘制到屏幕数组
        for (int i = 0; i < RAINDROP_COUNT; i++) {
            fall(&raindrops[i]);
            if (raindrops[i].y < HEIGHT) {
                screen[raindrops[i].y][raindrops[i].x] = raindrops[i].value;
            }
        }

        // 输出屏幕数组
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                printf("%c", screen[y][x]);
            }
            printf("\n");
        }

        // 控制帧率
        usleep(10000);
    }

    return 0;
}    