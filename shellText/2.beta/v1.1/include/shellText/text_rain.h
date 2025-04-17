# ifndef _RAIN_H_
# define _RAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
# include "text_color.h"

// 增大宽度和高度，增加雨滴数量
#define WIDTH 120
#define HEIGHT 30
#define RAINDROP_COUNT 50


// 雨滴结构体
typedef struct {
    int x;
    int y;
    int speed;
    char value;
} Raindrop;

void rainStart();
#endif