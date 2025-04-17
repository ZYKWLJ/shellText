/**
 * filename:execute.h
 * description:
 * author:EthanYankang
 * create time:2025/03/31 14:43:55
 */
#ifndef _EXECUTE_H_
#define _EXECUTE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// #include "eg_search.h"
#include "eg_clear.h"
#include "../display/eg_error.h"
#include "eg_execute_one_token.h"
#include "eg_execute_two_token.h"
#include "eg_execute_three_token.h"
#include "eg_execute_four_token.h"
#include "../lexer/eg_lexer.h"
#include "eg_is_all_digit.h"
#include "eg_find.h"
void eg_execute(char *str);
// int is_all_digit(const char *str);
#endif