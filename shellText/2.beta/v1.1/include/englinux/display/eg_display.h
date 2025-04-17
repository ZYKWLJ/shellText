#ifndef DISPLAY_H
#define DISPLAY_H
#include "../words_lib/words.h"
#include"eg_color.h"
#include"eg_print_words.h"
#include"../execute/eg_find.h"
void eg_display(int lib_index,int match_mod,char*str,word_entry *word_list, int list_size, int first_show, int second_show, int third_show,int fourthcol_show);
#endif