#include "main.h"

//新用户教学过程中必须输入的指引单词以继续向下学习

int newUser_must_enter(const char* expected_input) {
    char user_input[BUFSIZ];  // 假设足够存储用户的输入

    while (1) {  // 无限循环，直到用户输入正确
        //        printf("Please enter '%s' to proceed:", expected_input);  // 提示用户输入
        //		printf("请输入 '%s' 继续下面的学习:", expected_input); 

        fflush(stdin);
        //显现光标
        printf("\033[?25h");
        if (fgets(user_input, BUFSIZ, stdin) == NULL) {        
         //隐藏光标
        printf("\033[?25l");

            // 处理输入错误或EOF情况（如Ctrl+D或Ctrl+Z）
            fprintf(stderr, "Input error occurred. Please try again.\n");
            continue;
        }

        // 去除换行符（fgets可能读取到）
        user_input[strcspn(user_input, "\n")] = '\0';

        if (strcmp(user_input, expected_input) == 0) {
            // 输入正确，返回0表示成功
            return 0;
        }
        else {

            printf("%s%s%s%s对不起，请输入 '%s' 以继续下面的学习:%s\n>>s%", 
                GREEN_TEXT, 
                HEAD_OF_NEW_USER, 
                RESET_COLOR, 
                ANSI_COLOR_RED_BACKGROUND,
                ANSI_COLOR_WHITE_FONT,
                expected_input, 
                ANSI_COLOR_RESET,
                GREEN_TEXT, 
                RESET_COLOR);
            //			HEAD_OF_NEW_USER 

        }
    }
}
