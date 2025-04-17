#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 标准的写法其实就是.c只包含自己对应的.h文件，.h文件里面再次包含其他.h文件，这样可以避免重复包含，并且结构清晰！
// #include "guide_must_enter.h"
#include "text_color.h"
#include "text_eliminateSpace.h"
// #include "text_choose_language.h"
// #include "text_enter_text_help.h"
#include "text_subject.h"
#include "text_story.h"
#include "text_endSay.h"
#include "text_author.h"
#include "text_chapter_show.h"
#include "text_help.h"
#include "text_find.h"
#include "text_all_pages.h"
// #include "text_chapter_show.h"
void text_help();
void list();
void text_find(char *str);
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