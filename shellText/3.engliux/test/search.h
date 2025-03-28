# ifndef _SEARCH_H_
# define _SEARCH_H_
#include "lib.h"
#include "findAndHighlight.h"
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
// extern const char **words[27];
extern const char ****library;
char** search_word(char* str, int library);
#endif