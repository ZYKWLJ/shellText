# ifndef TWO_TOKEN_H
# define TWO_TOKEN_H
#include "../display/eg_error.h"
# include "../display/eg_color.h"
# include "../display/eg_display.h"
#include "eg_is_all_digit.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "eg_find.h"
#include "eg_help.h"
#include"eg_parser_fourth_token.h"
#include"eg_parser_first_token.h"
#include"eg_parser_second_token.h"
#include"eg_parser_third_token.h"
void execute_two_token(char*token[],int token_num, char *origin_str);
#endif