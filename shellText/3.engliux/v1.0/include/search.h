# ifndef _SEARCH_H_
# define _SEARCH_H_
# include "words.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
extern const char **words[27];
char** search_word(char* str, int library);
char** search_prefix(char* str, int library);
char** search_suffix(char* str, int library);
char** search_contains(char* str, int library);
# endif