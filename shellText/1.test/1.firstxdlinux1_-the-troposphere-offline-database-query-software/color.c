#include "color.h"



//天蓝色打印字体
void print_skyblue_instruction(const char* instruction)
{
    color(9);
    printf(instruction);
    color(16);    //因为这里大于15，恢复默认的颜色 

}

//绿色打印字体
void print_green_instruction(const char* instruction)
{
    color(10);
    printf(instruction);
    color(16);    //因为这里大于15，恢复默认的颜色 

}

//红色打印字体
void print_red_instruction(const char* instruction)
{
    color(12);
    printf(instruction);
    color(16);    //因为这里大于15，恢复默认的颜色 

}

//字体函数调用
void color(const unsigned short textColor)      //自定义函根据参数改变颜色 
{
    if (textColor >= 0 && textColor <= 15)     //参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);  //用一个参数，改变字体颜色
    else   //默认的字体颜色是白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


