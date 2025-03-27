#include "main.h"


//判断新老用户以优化体验，否则一直循环
int is_user_new_or_old() {

    char JudgeTheUser[100];

    printf("\n%s%s%s",
        GREEN_TEXT,
        HEAD_OF_ALL,
        RESET_COLOR
    );
    fflush(stdin);
    Dynamic_input("请问您是第一次使用吗？ y or n ?\n",
        SLEEP_TIME10,
        INTERVAL_NUM_TO_SLEEP3);

    printf("%s>>%s",
        GREEN_TEXT,
        RESET_COLOR
    );

    while (1) {
        
        //TODO这里有一个BUG,缓冲区问题：不能完全冲干净
 
        //显现光标
        printf("\033[?25h");
        fflush(stdin);
        fgets(JudgeTheUser, sizeof(JudgeTheUser), stdin);

        //隐藏光标
        printf("\033[?25l");

        JudgeTheUser[strcspn(JudgeTheUser, "\n")] = '\0'; // 去掉末尾的换行符
        if (strlen(JudgeTheUser) > 1) {
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

        if (strcmp(JudgeTheUser, "Y") == 0 || strcmp(JudgeTheUser, "y") == 0)
        {
            //新用户的系统使用教学在核心函数里面用，这里只是判断，解耦！！！！
            //new_user_guide();
            return 0;
            /*keywords_matching();*/
        }
        else if (strcmp(JudgeTheUser, "N") == 0 || strcmp(JudgeTheUser, "n") == 0)
        {
            //老用户直接跳转进入核心系统-------放在main里面吧，这里只判断，解耦！！！！
            /*keywords_matching();*/
            return 1;
        }

        else {

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


//新用户快速上手系统指南
void newUser_guide()
{

    //系统指令 
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING1,SLEEP_TIME10,1);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING2, SLEEP_TIME10,1);
  help_page(SLEEP_TIME1,SLEEP_TIME2,SLEEP_TIME3,INTERVAL_NUM_TO_SLEEP10);

  print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING4, SLEEP_TIME10,1);

    printBanner_yellow(DOTTED_LINE_SYSTEM_BEGIN_MIDDLE);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING20, SLEEP_TIME10,1);

    printBanner_yellow(DOTTED_LINE_SYSTEM_END_MIDDLE);



    //目录指令
    printBanner_yellow(DOTTED_LINE_DIR_BEGIN_MIDDLE);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING5, SLEEP_TIME10,1);
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);

    newUser_must_enter("1");

    // TODO: 指令1的内容 
    todo();
    printf(" 第一章的所有目录待导入\n");
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING6, SLEEP_TIME10,1);
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);
    printf("\033[?25h");
    newUser_must_enter("0");
    printf("\033[?25l");

    todo();
    printf(" 本书所有章节的全部目录待导入\n");
    // TODO: 指令0的内容 		
    todo();
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING7, SLEEP_TIME10,1);
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);

    newUser_must_enter("01");

    // TODO: 指令01的内容 
    todo();
    printf("本书所有章节的第一级目录待导入\n");
    //Dynamic_input(NEW_USER_GUIDE_SAYING7, SLEEP_TIME10,1);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING8, SLEEP_TIME10,1);
    //printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);
    printBanner_yellow(DOTTED_LINE_DIR_END_MIDDLE);



    //数据查询指令 

    //printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING9, SLEEP_TIME10, 1);

    printBanner_yellow(DOTTED_LINE_DB_BEGIN_MIDDLE);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING91, SLEEP_TIME10,1);

    printf("\033[?25h"); 

    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);
    newUser_must_enter("DB1");
    printf("\033[?25l");

    // TODO: 指令DB1的内容 
    todo(); printf("本书第一章的所有表单名称待导入\n");
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING10, SLEEP_TIME10,1);

    printf("\033[?25h");
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);
    newUser_must_enter("DB11");
    // TODO: 指令DB11的内容 
    todo(); printf("本书第一章的所有表单名称中第一个表的全部内容待导入\n");
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING11, SLEEP_TIME10,1);

    //printf("\033[?25h");
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);

    printBanner_yellow(DOTTED_LINE_DB_END_MIDDLE);


    //重点知识指令
    printBanner_yellow(DOTTED_LINE_CH_BEGIN_MIDDLE);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING12, SLEEP_TIME10,1);
    printf("\033[?25h");
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);

    newUser_must_enter("ch1");
    // TODO: 指令ch1的内容 	
    todo();
    printf("本书第一章的所有重点知识列表待导入\n");

    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING13, SLEEP_TIME10,1);

    printf("\033[?25h");
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);

    newUser_must_enter("ch10");
    // TODO: 指令ch10的内容 
    todo();
    printf("本书第一章的所有重点知识列表和详细内容待导入\n");

    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING131, SLEEP_TIME10,1);
    printf("\033[?25h");
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);
    newUser_must_enter("ch00");

    // TODO: 指令ch00的内容 	
    todo();
    printf("本书所有重点知识列表和详细内容待导入\n");
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING14, SLEEP_TIME10,1);
    //printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);
    printBanner_yellow(DOTTED_LINE_CH_END_MIDDLE);



    //帮助指令
    printBanner_yellow(DOTTED_LINE_HELP_BEGIN_MIDDLE);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING15, SLEEP_TIME10,1);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING16, SLEEP_TIME10,1);
    printf("\033[?25h");
    printf("%s%s%s", GREEN_TEXT, ARROW, RESET_COLOR);

    newUser_must_enter("h");
    // TODO: 指令h的内容 	
    printf("\033[?25l");
   
    help_page(SLEEP_TIME1,SLEEP_TIME2,SLEEP_TIME3,INTERVAL_NUM_TO_SLEEP10);
    //所有指令集合使用手册待导入 
    printBanner_yellow(DOTTED_LINE_HELP_END_MIDDLE);
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING17, SLEEP_TIME10,1);

    // TODO: 软件背后的故事
    print_green_instruction(header);
    Dynamic_input(NEW_USER_GUIDE_SAYING21, SLEEP_TIME10,1);

    int result_y_or_n_in_story = y_or_n_in_story();

    if (result_y_or_n_in_story == 1)
    {
        story_page(STORY_SLEEP_TIME1, STORY_SLEEP_TIME2, STORY_INTERVAL_NUM_TO_SLEEP);

    }

}

