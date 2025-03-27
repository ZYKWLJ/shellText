#pragma once
#include "main.h"




//动态输出单个单个的词，SLEEP_TIME用来调节休眠时间已达到修改输出速率
void Dynamic_input(const char* input, int sleep_time,  int interval_num_to_sleep);

//红色地动态输出单个单个的词，SLEEP_TIME用来调节休眠时间已达到修改输出速率
void Dynamic_input_red(const char* input, int sleep_time, int interval_num_to_sleep);

//红色地动态输出单个单个的词，SLEEP_TIME用来调节休眠时间已达到修改输出速率
void Dynamic_input_green(const char* input, int sleep_time, int interval_num_to_sleep);

//能以更高的速率动态输出单个单个的词，SLEEP_TIME用来调节休眠时间已达到修改输出速率
//因为可以设置INTERVAL_NUM_TO_SLEEP的值让程序在刚好能被INTERVAL_NUM_TO_SLEEP除尽之时才休眠，这样未除尽之间就是及原有速率极高的输出

void fast_Dynamic_input(const char* input, int sleep_time, int interval_num_to_sleep);

//在上面的基础上加上了颜色处理
void fast_Dynamic_input_green(const char* input, int sleep_time, int interval_num_to_sleep);

//大一统函数—————包括背景色、速率、字体颜色等