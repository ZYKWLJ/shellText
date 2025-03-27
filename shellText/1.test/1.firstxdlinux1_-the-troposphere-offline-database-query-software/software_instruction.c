#include "main.h"
void software_instruction(const char* main_text, const char* dotted_line_word, int  sleep_time, int interval_num_to_sleep) {
	printBanner_yellow(dotted_line_word);
	printf("\n");
	Dynamic_input(main_text, sleep_time, interval_num_to_sleep);
	printf("\n\n\n");

    cursor_move_Ncolumn_print(101);
    Dynamic_input_green(NAME, SLEEP_TIME1, 1);
    printf("\n");
    cursor_move_Ncolumn_print(101);
    cursor_move_Ncolumn_print(101);
    Dynamic_input_green(DATE1, SLEEP_TIME1, 1);
    printf("\n");
    cursor_move_Ncolumn_print(101);
    Dynamic_input_green(ADDRESS, SLEEP_TIME1, 1);
    printf("\n");
	printBanner_yellow(dotted_line_word);

    
}


