#include "dynamic_print_rate.h"

void  Dynamic_input(const char* input, int sleep_time,int interval_num_to_sleep) {

    len = strlen(input);
    // Hide cursor using ANSI escape sequence
    printf("\033[?25l");

    for (size_t i = 0; i < len; ++i) {
        putchar(input[i]);
        fflush(stdout);  // Ensure character is immediately printed
        if (i % interval_num_to_sleep == 0) {
        Sleep(sleep_time);      // Sleep for 50 milliseconds

       }
    }
}



void Dynamic_input_red(const char* input, int sleep_time,int interval_num_to_sleep) {

    len = strlen(input);

    // Hide cursor using ANSI escape sequence
    //printf("\033[?25l");光标只有在需要输入之时，在开启，输入完毕后立马关闭就行，这样永远不会错

    for (size_t i = 0; i < len; ++i) {
        color(12);
        putchar(input[i]);
        color(16);
        fflush(stdout);  // Ensure character is immediately printed
        if (i % interval_num_to_sleep == 0) {
            Sleep(sleep_time);      // Sleep for 50 milliseconds

        }
    }
}


void Dynamic_input_green(const char* input, int sleep_time,int interval_num_to_sleep) {

    len = strlen(input);

    for (size_t i = 0; i < len; ++i) {

        color(10);
        putchar(input[i]);
        color(16);
        fflush(stdout);  // Ensure character is immediately printed
        if (i % interval_num_to_sleep == 0) {
            Sleep(sleep_time);      // Sleep for 50 milliseconds

        }
    }
}


void fast_Dynamic_input_green(const char* input, int sleep_time, int interval_num_to_sleep) {

    len = strlen(input);

    for (size_t i = 0; i < len; ++i) {       
        color(10);
        putchar(input[i]);
        color(16);
        fflush(stdout);  // Ensure character is immediately printed
        if (i % interval_num_to_sleep==0)
        {
            Sleep(sleep_time);      // Sleep for 50 milliseconds
        }
    }
}


void fast_Dynamic_input(const char* input, int sleep_time, int interval_num_to_sleep) {

    len = strlen(input);
    // Hide cursor using ANSI escape sequence


    for (size_t i = 0; i < len; ++i) {
        putchar(input[i]);
        fflush(stdout);  // Ensure character is immediately printed
        if (i % interval_num_to_sleep == 0) {
            Sleep(sleep_time);      // Sleep for 50 milliseconds
        }

    }
}

