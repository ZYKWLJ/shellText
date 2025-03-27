#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 标准的写法其实就是.c只包含自己对应的.h文件，.h文件里面再次包含其他.h文件，这样可以避免重复包含，并且结构清晰！
// #include "guide_must_enter.h"
#include "color.h"
#include "eliminateSpace.h"
// #include "choose_language.h"
// #include "enter_help.h"
#include "subject.h"
#include "story.h"
#include "endSay.h"
#include "author.h"
#include "chapter_show.h"
#include "help.h"
#include "find.h"
#include "all_pages.h"
// #include "chapter_show.h"
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
void set_language(char *language);
// extern char *all_pages[500];
#endif