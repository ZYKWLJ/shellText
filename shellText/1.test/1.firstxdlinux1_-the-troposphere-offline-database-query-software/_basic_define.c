#include "_basic_define.h"


void acsii_troposphere_print(const char* define_str, int sleep_time, int interval_num_to_sleep);

void copyright_print(const char* matched_machine, const char* author, int sleep_time, int interval_num_to_sleep);

//徽标打印
void acsii_troposphere_print(const char* define_str,int sleep_time,int interval_num_to_sleep) {

    fast_Dynamic_input_green(define_str,sleep_time,INTERVAL_NUM_TO_SLEEP);
}

//版权打印函数
void copyright_print(const char* matched_machine, const char* author,int sleep_time, int interval_num_to_sleep)
{
    printf("\n\n\n");
    //printBanner_green(COPYRIGHT1_1);
    //printBanner_green(COPYRIGHT2_1);
    fast_Dynamic_input_green(COPYRIGHT1_1, 10, 3);
    printf("\n\n\n");
    fast_Dynamic_input_green(COPYRIGHT2_1, 10, 3);
    printf("\n\n\n");
}


