#pragma once
#include "main.h"

//判断是新是老用户
int is_user_new_or_old();

//进入新用户指南
void newUser_guide();

//指南是否选项
int y_or_n_in_new_user();

//新用户教学过程中必须输入的指引单词以继续向下学习
int newUser_must_enter(const char* expected_input);

//更改字体颜色
void color(const unsigned short textColor);


//是否了解故事的选项
int y_or_n_in_story();

//是否再次进入新用户教学
void again_newUser_guide();

//用户必须输入h0已达到重进入教学系统
int restart_newUser_must_enter(const char* expected_input);




