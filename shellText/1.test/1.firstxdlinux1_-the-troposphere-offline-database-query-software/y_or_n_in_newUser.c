#include "main.h"


//在新用户系统里面的选择判断调用
int y_or_n_in_new_user() {

    while (1) {

        char JudgeTheUser[10];
        fflush(stdin);
        //显现光标
        printf("\033[?25h");
        fgets(JudgeTheUser, sizeof(JudgeTheUser), stdin); 
        //隐藏光标
        printf("\033[?25l");

        JudgeTheUser[strcspn(JudgeTheUser, "\n")] = '\0'; // 去掉末尾的换行符

        if (strcmp(JudgeTheUser, "y") == 0 || strcmp(JudgeTheUser, "Y") == 0)
        {
            return 1;
        }
        else if (strcmp(JudgeTheUser, "n") == 0 || strcmp(JudgeTheUser, "N") == 0)
        {
            return 0;
        }
        else {
            //          printf("%s", );
            //          printf("%s%s%s为优化您的体验请先输入 y or n ?",GREEN_TEXT, HEAD_OF_NEW_USER, RESET_COLOR);			
          /*  printf("%s%s%s对不起,请输入 y or n?\n>", GREEN_TEXT, HEAD_OF_NEW_USER, RESET_COLOR);*/
            printf("%s%s对不起,为优化您的体验请先输入 y or n ?%s\n%s%s%s",
                ANSI_COLOR_RED_BACKGROUND,
                ANSI_COLOR_WHITE_FONT,
                ANSI_COLOR_RESET,
                GREEN_TEXT,
                ARROW,
                RESET_COLOR
            );
            continue;
        }
    }

}
