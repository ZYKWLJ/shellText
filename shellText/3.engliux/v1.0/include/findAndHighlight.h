// # include "findAndHighlight.h"
#ifndef FINDANDHIGHLIGHT_H
#define FINDANDHIGHLIGHT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "color.h"
#include "display.h"
#include <ctype.h>
int find_if_exist(const char **word_set, int set_size, const char *target, int mode);
void find_and_highlight(const char **word_set, int set_size, const char *target, 
                       int mode, int col1, int col2, int col3) ;
// int find_and_highlight(const char ***s, int s_size, char *t, int search_mod, int first_show, int second_show, int third_show);
// int find_if_exist(char ***s, int s_size, char *t, int search_mod);
// int find_if_exist(const char ***word_list, int list_size, const char *target, int search_mode) ;

#endif