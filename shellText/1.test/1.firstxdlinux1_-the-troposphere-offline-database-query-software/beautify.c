#include "beautify.h"
#include "main.h"


//===边框函数 ，中间打印黄色，代表某一个指令模块结束
void printBanner_yellow(const char* middleText) {
    int totalLength = 124;
    int middleLength = strlen(middleText);
    int sideLength = (totalLength - middleLength) / 2;

    // 打印左边的等号
    for (int i = 0; i < sideLength; i++) {
        printf("=");
    }

    // 打印中间的文本
    //printf("%s", middleText);

    //中间红色字体打印醒目
    printf("%s%s%s", YELLOW_TEXT, middleText, RESET_COLOR);

    // 打印右边的等号
    for (int i = 0; i < sideLength; i++) {
        printf("=");
    }

    printf("\n\n");
}

//===边框函数 ，中间打印红色，代表出错
void printBanner_red(const char* middleText) {
    int totalLength = 124;
    int middleLength = strlen(middleText);
    int sideLength = (totalLength - middleLength) / 2;

    // 打印左边的等号
    for (int i = 0; i < sideLength; i++) {
        printf("=");
    }

    // 打印中间的文本
    //printf("%s", middleText);

    //中间红色字体打印醒目
    printf("%s%s%s", RED_TEXT, middleText, RESET_COLOR);

    // 打印右边的等号
    for (int i = 0; i < sideLength; i++) {
        printf("=");
    }

    printf("\n\n");
}


//===边框函数 ，中间打印绿色，代表某一个模块结束

void printBanner_green(const char* middleText) {
    int totalLength = 124;
    int middleLength = strlen(middleText);
    int sideLength = (totalLength - middleLength) / 2;

    // 打印左边的等号
    for (int i = 0; i < sideLength; i++) {
        printf("=");
    }

    // 打印中间的文本
    //printf("%s", middleText);

    //中间红色字体打印醒目
    printf("%s%s%s", GREEN_TEXT, middleText, RESET_COLOR);

    // 打印右边的等号
    for (int i = 0; i < sideLength; i++) {
        printf("=");
    }
    printf("\n\n");
}
