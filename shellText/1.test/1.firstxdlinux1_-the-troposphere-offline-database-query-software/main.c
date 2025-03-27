#include "main.h"

//主函数
int main() {

    //隐藏光标
    printf("\033[?25l");
    // 初始化MySQL连接结构体
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init failed: %s\n", mysql_error(conn));
        exit(1);
    }

    mysql_options(conn, MYSQL_SET_CHARSET_NAME, "gbk");

    // 建立到MySQL服务器的连接
    if (mysql_real_connect(conn, SERVER_HOST, SERVER_USER, SERVER_PASS, DATABASE_NAME, DATABASE_port, NULL, 1) == NULL) {
        fprintf(stderr, "Error connecting to database: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }


    //打印ASCII码
    acsii_troposphere_print(TROPOSPHERE_ASCII,0,INTERVAL_NUM_TO_SLEEP1);
    printf("\n\n\n");

    //打印版权
    copyright_print(COPYRIGHT1_1,COPYRIGHT2_1,SLEEP_TIME40,INTERVAL_NUM_TO_SLEEP20);
    printf("\n\n\n\n");

    //软件基本介绍
    software_instruction(BASIC_INTRODUCTION_OF_1SOFTWARE, DOTTED_LINE_STORY_END_MIDDLE,SLEEP_TIME1,INTERVAL_NUM_TO_SLEEP4);

    //首先做语言判断
    int resultOf_choose_language = choose_language();

    if (resultOf_choose_language == 0)
    {
        printf("这里将来会做英语的接口\n");
        printf("暂时先继续\n");
    }
    else if (resultOf_choose_language == 1)
    {
        printf("这里将来会做中文的接口\n");
        printf("暂时先继续\n");
    }

    
    printf("\n%s%s%s", GREEN_TEXT, HEAD_OF_NEW_USER, RESET_COLOR);

    //这是最合适的提示用户输入的速率
    Dynamic_input_green("\n\nCurrent all table names are as follows:\n\n",
        SLEEP_TIME10, 
        INTERVAL_NUM_TO_SLEEP2);
//打印总存的的表名
    all_table_name_print(conn);
    printf("\n\n");
   
    

    //TODO这一节有出错，主要是缓存里面的值

    int judge_is_user_new_or_old = is_user_new_or_old();

    if (judge_is_user_new_or_old == 0)
    {
        newUser_guide();
        core_keywords_matching();
    }
    else if (judge_is_user_new_or_old == 1)
    {
        core_keywords_matching();

    }
}
