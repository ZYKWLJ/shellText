#ifndef FIND_H
#define FIND_H
#include "color.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
void find_parser(char *token, char *full_command, int *library, int *search_mod, int *first_show, int *second_show, int *third_show);
#endif