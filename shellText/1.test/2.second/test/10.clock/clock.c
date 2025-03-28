#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define CLOCK_SIZE 10
#define CENTER_X (CLOCK_SIZE + 1)
#define CENTER_Y (CLOCK_SIZE + 1)

// 清屏函数
void clear_screen() {
    printf("\033[2J\033[H");
}

// 绘制钟表函数
void draw_clock(int hours, int minutes, int seconds) {
    char clock[2*CLOCK_SIZE+3][2*CLOCK_SIZE+3];
    
    // 初始化钟表数组
    for (int y = 0; y < 2*CLOCK_SIZE+3; y++) {
        for (int x = 0; x < 2*CLOCK_SIZE+3; x++) {
            clock[y][x] = ' ';
        }
    }
    
    // 绘制钟表外框
    for (int i = 0; i <= 360; i += 30) {
        double angle = i * PI / 180;
        int x = CENTER_X + (int)(CLOCK_SIZE * cos(angle));
        int y = CENTER_Y + (int)(CLOCK_SIZE * sin(angle));
        clock[y][x] = '.';
    }
    
    // 计算指针位置
    double hour_angle = (hours % 12 + minutes / 60.0) * 30 * PI / 180;
    double min_angle = minutes * 6 * PI / 180;
    double sec_angle = seconds * 6 * PI / 180;
    
    // 绘制时针
    for (int r = 0; r < CLOCK_SIZE * 0.6; r++) {
        int x = CENTER_X + (int)(r * cos(hour_angle - PI/2));
        int y = CENTER_Y + (int)(r * sin(hour_angle - PI/2));
        if (x >= 0 && x < 2*CLOCK_SIZE+3 && y >= 0 && y < 2*CLOCK_SIZE+3) {
            clock[y][x] = 'H';
        }
    }
    
    // 绘制分针
    for (int r = 0; r < CLOCK_SIZE * 0.8; r++) {
        int x = CENTER_X + (int)(r * cos(min_angle - PI/2));
        int y = CENTER_Y + (int)(r * sin(min_angle - PI/2));
        if (x >= 0 && x < 2*CLOCK_SIZE+3 && y >= 0 && y < 2*CLOCK_SIZE+3) {
            clock[y][x] = 'M';
        }
    }
    
    // 绘制秒针
    for (int r = 0; r < CLOCK_SIZE * 0.9; r++) {
        int x = CENTER_X + (int)(r * cos(sec_angle - PI/2));
        int y = CENTER_Y + (int)(r * sin(sec_angle - PI/2));
        if (x >= 0 && x < 2*CLOCK_SIZE+3 && y >= 0 && y < 2*CLOCK_SIZE+3) {
            clock[y][x] = 'S';
        }
    }
    
    // 绘制中心点
    clock[CENTER_Y][CENTER_X] = 'O';
    
    // 打印钟表
    for (int y = 0; y < 2*CLOCK_SIZE+3; y++) {
        for (int x = 0; x < 2*CLOCK_SIZE+3; x++) {
            putchar(clock[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    while (1) {
        // 获取当前时间
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        
        int hours = timeinfo->tm_hour;
        int minutes = timeinfo->tm_min;
        int seconds = timeinfo->tm_sec;
        
        // 清屏并绘制钟表
        clear_screen();
        printf("当前时间: %02d:%02d:%02d\n", hours, minutes, seconds);
        draw_clock(hours, minutes, seconds);
        
        // 每秒刷新一次
        sleep(1);
    }
    
    return 0;
}