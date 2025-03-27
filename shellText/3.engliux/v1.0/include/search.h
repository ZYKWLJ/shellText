# ifndef _SEARCH_H_
# define _SEARCH_H_
# include "words.h"
# include <stdio.h>
# include <stdlib.h>
extern const char **words[27];
char** search_word(char* str);
char** search_prefix(char* str);
char** search_suffix(char* str);
char** search_contains(char* str);
# endif