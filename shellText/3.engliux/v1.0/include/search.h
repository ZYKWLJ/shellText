# ifndef _SEARCH_H_
# define _SEARCH_H_
# include "words.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "findAndHighlight.h"
# include "words.h"
// extern const char **words[27];
extern const char ***library[];
int search_word(char* str, int library);

# endif