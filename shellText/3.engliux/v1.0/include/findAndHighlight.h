// # include "findAndHighlight.h"
#ifndef FINDANDHIGHLIGHT_H
#define FINDANDHIGHLIGHT_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"color.h"
int find_and_highlight(const char **s, int s_size, char *t,int mod);
int find_if_exist(const char **s, int s_size, char *t,int mod);
#endif