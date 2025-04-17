# ifndef PARSER_SECOND_TOKEN_H
# define PARSER_SECOND_TOKEN_H
#include "../display/eg_color.h"
#include "../display/eg_error.h"
#include "eg_is_all_digit.h"
// #include"is_all_"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int parser_second_token(char *token, char *origin_str, int *find_mod, char *word,char *subquerys[1024]);
# endif