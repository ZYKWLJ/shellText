/**
 * filename:lexer.c
 * description:get the token from the input string
 * author:EthanYankang
 * create time:2025/03/31 13:24:14
 */
#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../display/eg_color.h"
void lexer(char *str, char *token[100], int *token_num);

#endif