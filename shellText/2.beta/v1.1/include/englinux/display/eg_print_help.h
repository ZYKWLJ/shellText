#ifndef _PRINT_H_
#define _PRINT_H_
#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include"eg_display_width.h"
void eg_print_help(const char **str[],int columns_num);
void eg_print(const char **str[],int columns_num);
#endif