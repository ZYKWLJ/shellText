#include "main.h"


//新用户再次进入教学系统函数1 

void again_newUser_guide() {

    Dynamic_input(NEW_USER_GUIDE_SAYING22,SLEEP_TIME10,1);

    if (y_or_n_in_new_user())
    {
        if (restart_newUser_must_enter("h0"))
        {
            newUser_guide();
        }
    }

    //结束指令 
    Dynamic_input(NEW_USER_GUIDE_SAYING23, SLEEP_TIME10,1);
    printBanner_yellow(DOTTED_LINE_NEWUSER_END_MIDDLE);

}

void again_newUser_guide1() {
    Dynamic_input("您确定要进入教学系统吗？\n", SLEEP_TIME10, 1);
    printf("\n%s>>%s",
        GREEN_TEXT,
        RESET_COLOR
    );
    if (y_or_n_in_new_user())
    {       
        printBanner_yellow(DOTTED_LINE_NEWUSER_BEGIN_MIDDLE);  
            newUser_guide(); 
            printBanner_yellow(DOTTED_LINE_NEWUSER_END_MIDDLE);
    }
    else {
//取消进入指令 
    printBanner_yellow(DOTTED_LINE_NEWUSER_CANCEL_MIDDLE);

    }
    
}

