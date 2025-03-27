#pragma once
#include "main.h"

//为了视觉效果做的填充 
#define TODO "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"

//每条指令对应的边框封装语句，美化与提示作用
#define DOTTED_LINE_FORNT "====================================="
#define DOTTED_LINE_BACK "=====================================\n\n"

#define DOTTED_LINE_HELP_MIDDLE "您可以在任何时候输入help/h获取此指令集手册"
#define DOTTED_LINE_NEWUSER_BEGIN_MIDDLE "欢迎进入教学系统"
#define DOTTED_LINE_NEWUSER_END_MIDDLE "系统使用教学已结束，输入h0再次进入"
#define DOTTED_LINE_NEWUSER_CANCEL_MIDDLE "已取消进入教学系统"
#define DOTTED_LINE_SYSTEM_BEGIN_MIDDLE "系统基本指令"
#define DOTTED_LINE_SYSTEM_END_MIDDLE "系统基本指令已结束"
#define DOTTED_LINE_DIR_BEGIN_MIDDLE "章节指令"
#define DOTTED_LINE_DIR_END_MIDDLE "章节指令已结束"
#define DOTTED_LINE_DB_BEGIN_MIDDLE "数据指令"
#define DOTTED_LINE_DB_END_MIDDLE "数据指令已结束"
#define DOTTED_LINE_CH_BEGIN_MIDDLE "重点知识指令"
#define DOTTED_LINE_CH_END_MIDDLE "重点知识指令已结束"
#define DOTTED_LINE_HELP_BEGIN_MIDDLE "帮助指令"
#define DOTTED_LINE_HELP_END_MIDDLE "帮助指令已结束"
#define DOTTED_LINE_STORY_END_MIDDLE "软件背后的故事"
#define DOTTED_LINE_BASIC_SOFTWARE_END_MIDDLE "软件基本介绍"

void printBanner_green(const char* middleText);
void printBanner_red(const char* middleText);
void printBanner_yellow(const char* middleText);