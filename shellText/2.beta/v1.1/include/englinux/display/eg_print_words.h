#ifndef _PRINT_H_
#define _PRINT_H_
#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "eg_color.h"
#include"../words_lib/words.h"
#include"eg_display_width.h"
#include"../execute/eg_find.h"

void print_words(word_entry *words, int word_count,char*str,int match_mod,
                 int firstcol_show, int secondcol_show,
                 int thirdcol_show, int fourthcol_show);
#endif