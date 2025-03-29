// # include "findAndHighlight.h"
#ifndef FINDANDHIGHLIGHT_H
#define FINDANDHIGHLIGHT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "words.h"
#include "color.h"
#include "display.h"
int find_and_highlight(word_entry *s, int s_size, char *t, int search_mod, int first_show, int second_show, int third_show);
// int find_if_exist(char ***s, int s_size, char *t, int search_mod);
int find_if_exist(word_entry *word_list, int list_size, const char *target, int search_mode) ;

#endif