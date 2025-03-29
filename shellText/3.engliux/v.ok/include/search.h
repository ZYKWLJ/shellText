# ifndef _SEARCH_H_
# define _SEARCH_H_
# include "words.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "findAndHighlight.h"
# include "words.h"
// extern const char **words[27];
extern const char **library[];
// int search_word(char* str, int library,int mod);
void search_word(char *str, int library_index, int search_mod, int first_show, int second_show, int third_show);
// int search_word(const char *target, int lib_index, int search_mode,
            //    int first_show, int second_show, int third_show) ;
# endif
