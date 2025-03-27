#pragma once
#include "main.h"

//拼接字符串的不同颜色处理 
#define GREEN_TEXT "\033[92m"
//#define GREEN_TEXT_BRIGHT "\033[92m"
#define RESET_COLOR "\033[0m"
//红色 
#define RED_TEXT "\033[91m"

#define ANSI_COLOR_RED_BACKGROUND "\x1b[41m"
#define ANSI_COLOR_RED_BACKGROUND_BRIGHT "\x1b[101m"
#define ANSI_COLOR_WHITE_FONT     "\x1b[37m"
#define ANSI_COLOR_RESET          "\x1b[0m"
#define YELLOW_TEXT               "\033[38;5;208m"


void print_skyblue_instruction(const char* instruction);
void print_red_instruction(const char* instruction);
void print_green_instruction(const char* instruction);
//void print_skyblue_instruction(const char* instruction);
//颜色函数，可以直接替换成宏，虽然较之printf()转义字符方便性差一点，但是是万能的
void color(const unsigned short textColor);


