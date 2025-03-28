#ifndef _SIMILARINSTRUCTIONS_H_
#define _SIMILARINSTRUCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include "all_instructions.h"
#include "execute.h"
#include "color.h"
// 声明 instructions_all 数组
extern char *instructions_all[50];
void find_similar_commands(char *input);
#endif