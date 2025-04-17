# ifndef THREE_TOKEN_H
# define THREE_TOKEN_H
// # include "../display/eg_color.h"
// # include "../display/eg_print_words.h"
// # include "../display/display.h"
// #include "../../include/display/error.h"
// #include <stdlib.h>
// #include "find.h"
// #include "help.h"
// # include "is_all_digit.h"
// #include"parser_second_token.h"
// #include"parser_third_token.h"
// #include"parser_first_token.h"
# include "../display/eg_color.h"
#include "eg_find.h"
#include "eg_help.h"
#include "../display/eg_endSay.h"
#include "../display/eg_error.h"
#include "../display/eg_display.h"
#include "eg_clear.h"
#include"../display/eg_author.h"
#include"../display/eg_find_help.h"
#include"eg_parser_fourth_token.h"
#include"eg_parser_first_token.h"
#include"eg_parser_second_token.h"
#include"eg_parser_third_token.h"
void execute_three_token(char*token[],int token_num, char *origin_str);
#endif