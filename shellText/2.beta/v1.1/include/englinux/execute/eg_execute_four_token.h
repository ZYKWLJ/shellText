# ifndef FOUR_TOKEN_H
# define FOUR_TOKEN_H
// # include "../display/color.h"
// #include "find.h"
// #include "help.h"
// # include "is_all_digit.h"
// #include "../../include/display/error.h"
// #include "../../include/display/display.h"
// #include "parser_first_token.h"
// #include "parser_second_token.h"
// #include "parser_third_token.h"
// #include "parser_fourth_token.h"
// void execute_four_token(char*token,char *origin_str,int*firstcol_show,int*secondcol_show,int*thirdcol_show,int*fourthcol_show);
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
void execute_four_token(char*token[],int token_num, char *origin_str);
#endif