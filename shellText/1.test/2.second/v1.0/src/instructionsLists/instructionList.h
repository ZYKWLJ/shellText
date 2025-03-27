#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 标准的写法其实就是.c只包含自己对应的.h文件，.h文件里面再次包含其他.h文件，这样可以避免重复包含，并且结构清晰！
#include "../guide/guide_must_enter.h"
#include "../commonTools/color/color.h"
#include "../commonTools/eliminateSpace/eliminateSpace.h"
#include "../guide/guide_one_by_one/choose_language.h"
#include "../guide/guide_one_by_one/enter_help.h"

void help();
void list();
void find(char *str);
void clear_screen();
void exit_program();
void story();
void author_info();
void subject_intro();
void list_chapter(int chapter);
void guide();
void set_language(char* language);

#endif