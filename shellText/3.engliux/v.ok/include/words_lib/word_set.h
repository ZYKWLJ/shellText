#ifndef WORDS_SET_H
#define WORDS_SET_H
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
typedef struct
{
    const char *index;
    const char *word;
    const char *phonetic;
    const char *meaning;
} word_entry;

#endif