# ifndef FIND_H
# define FIND_H
# include "text_color.h"
# include "string.h"
# include "stdio.h"
// # include"pages.h"
#include "text_all_pages.h"
// void find_page(int page_num);
// extern char *all_pages[500];
int find_and_highlight(char **s, int s_size, char *t);
# endif