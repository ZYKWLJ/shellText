#include "choose_language.h"
#include "main.h"


//进入系统第一件事就是选择语言，否则一直循环
int choose_language() {

    printf("%s%s%s",
        GREEN_TEXT,
        HEAD_OF_ALL,
        RESET_COLOR
    );
    Dynamic_input("请先选择语言, E(English) or C(中文) ? \t\t\t\t\t\nplease select the language first, E(English) or C(Chinese) ? \n", 
        SLEEP_TIME10,
        INTERVAL_NUM_TO_SLEEP3);

    printf("%s>>%s",
        GREEN_TEXT,
        RESET_COLOR
    );
 


    while (1) {

        //TODO关于清空缓冲区的地方都有大问题

        fflush(stdin);
        char language[100];

        //显现光标
        printf("\033[?25h");
        
        fgets(language, sizeof(language), stdin);

       //隐藏光标
        printf("\033[?25l");

        language[strcspn(language, "\n")] = '\0'; // 去掉末尾的换行符
        if (strlen(language) > 1)
        {
            printf("%s%s对不起,请先选择语言, E(English) or C(中文)?\t\t\t\t\t\nSorry, please select the language first,E(English) or C(Chinese)?%s\n%s%s%s",
                ANSI_COLOR_RED_BACKGROUND,
                ANSI_COLOR_WHITE_FONT,
                ANSI_COLOR_RESET,
                GREEN_TEXT,
                ARROW,
                RESET_COLOR
            );
            //fflush(stdin);
            continue;
        }

        if (strcmp(language, "E") == 0 || strcmp(language, "e") == 0)
        {

            return 0;
        }
        else if (strcmp(language, "C") == 0 || strcmp(language, "c") == 0)
        {
            //printf("这里将来会做中文的接口\n");
            return 1;
        }

        else {
            //printf("%s%s%s对不起,请输入 E(English) or C(中文)?\n>", HEAD_OF_NEW_USER, RESET_COLOR);

            printf("%s%s对不起,请先选择语言, E(English) or C(中文)?\t\t\t\t\t\nSorry, please select the language first,E(English) or C(Chinese)?%s\n%s%s%s",
                ANSI_COLOR_RED_BACKGROUND,
                ANSI_COLOR_WHITE_FONT,
                ANSI_COLOR_RESET,
                GREEN_TEXT,
                ARROW,
                RESET_COLOR
            );
            //fflush(stdin);
            continue;
        }
    }

}
