# ifndef PARSER_FIRST_TOKEN_H
# define PARSER_FIRST_TOKEN_H
#include "../display/eg_color.h"
#include "../display/eg_error.h"
#include "eg_is_all_digit.h"
// #include"is_all_"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int parser_first_token(char *token, char *full_command);
# endif