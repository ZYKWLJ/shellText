#pragma once
#include "main.h"



//系统指令介绍 
#define INSTRUCTIONOF_BASIC_SYSTEM "系统所有指令不区分大小写,括号外必选,括号内可选,0代表所有,在末尾可省略\n\n\n"

//系统基本指令 
#define INSTRUCTIONOF_ENTER_SYSTEM1 "系统指令:\n\n"
#define INSTRUCTIONOF_ENTER_SYSTEM2 "  ~|i"
#define INSTRUCTIONOF_ENTER_SYSTEM3 "\n\t\t[……………………][进入系统]\n\n\n"

//通用的点状物连接省略指令美化使用 
#define INSTRUCTIONOF_DOT_GREED "\n\t··\t··········\t"


#define INSTRUCTIONOF_OFF_SYSTEM1 "  ~|q"
#define INSTRUCTIONOF_OFF_SYSTEM2 "\n\t\t[……………………][退出系统]\n\n\n"

 //第一条指令 DIR 
#define INSTRUCTIONOF_DIR_LEVEL1_HEAD "章节指令:\n\n"
#define INSTRUCTIONOF_DIR_LEVEL1_COLOR_RED "  0~9[0~4]"
#define INSTRUCTIONOF_DIR_LEVEL1_TAIL "\n\t\t[……………………][章节目录][展开层级]"

#define INSTRUCTIONOF_DIR_LEVEL2_1th_GREED "\n\n  \t0|00"
#define INSTRUCTIONOF_DIR_LEVEL2_1th_TAIL "\t[……………………][进入所有章节全级目录]"

#define INSTRUCTIONOF_DIR_LEVEL2_2th_GREED "\n\n  \t01"
#define INSTRUCTIONOF_DIR_LEVEL2_2th_TAIL "\t[……………………][进入所有章节1级目录]"

#define INSTRUCTIONOF_DIR_LEVEL2_3th_GREED "\n\n  \t1|10"
#define INSTRUCTIONOF_DIR_LEVEL2_3th_TAIL "\t[……………………][进入第1章节全级目录]"

#define INSTRUCTIONOF_DIR_LEVEL2_4th_GREED "\n\n  \t11"
#define INSTRUCTIONOF_DIR_LEVEL2_4th_TAIL "\t[……………………][进入第1章节1级目录]"

#define INSTRUCTIONOF_DIR_LEVEL2_5th_GREED "\n\n  \t12"
#define INSTRUCTIONOF_DIR_LEVEL2_5th_TAIL "\t[……………………][进入第1章节2级目录]"

#define INSTRUCTIONOF_DIR_LEVEL2_6th_GREED "\n  \t84"
#define INSTRUCTIONOF_DIR_LEVEL2_6th_TAIL "\t[……………………][进入第8章节4级目录]\n\n\n"


 //第二条指令 DB 
#define INSTRUCTIONOF_DATABASE_LEVEL1_HEAD "数据]指令:\n\n"
#define INSTRUCTIONOF_DATABASE_LEVEL1_COLOR_RED "  DB[0~9][0~n]"
#define INSTRUCTIONOF_DATABASE_LEVEL1_TAIL "\n\t\t[……………………]DB[展示章节所有数据表名][展示第几个数据表]"

#define INSTRUCTIONOF_DATABASE_LEVEL2_1th_GREED "\n\n  \tDB"
#define INSTRUCTIONOF_DATABASE_LEVEL2_1th_TAIL "\t[……………………][展示所有章节所有表名不展示数据]"

#define INSTRUCTIONOF_DATABASE_LEVEL2_11th_GREED "\n\n  \tDB0"
#define INSTRUCTIONOF_DATABASE_LEVEL2_11th_TAIL "\t[……………………][展示所有章节所有表名及全部数据]"


#define INSTRUCTIONOF_DATABASE_LEVEL2_3th_GREED "\n\n  \tDB10"
#define INSTRUCTIONOF_DATABASE_LEVEL2_3th_TAIL "\t[……………………][展示第1章节所有表名及全部数据]"

#define INSTRUCTIONOF_DATABASE_LEVEL2_4th_GREED "\n\n  \tDB11"
#define INSTRUCTIONOF_DATABASE_LEVEL2_4th_TAIL "\t[……………………][展示第1章节的第1个表名的对应的全部数据]"

#define INSTRUCTIONOF_DATABASE_LEVEL2_5th_GREED "\n\n  \tDB12"
#define INSTRUCTIONOF_DATABASE_LEVEL2_5th_TAIL "\t[……………………][展示第1章节的第2个表名的对应的全部数据]"

#define INSTRUCTIONOF_DATABASE_LEVEL2_6th_GREED "\n  \tDB62"
#define INSTRUCTIONOF_DATABASE_LEVEL2_6th_TAIL "\t[……………………][展示第6章节的第2个表名的对应的全部数据]\n\n\n"



//第3条指令 ch 
#define INSTRUCTIONOF_CHAPTER_LEVEL1_HEAD "重点知识指令:\n\n"
#define INSTRUCTIONOF_CHAPTER_LEVEL1_COLOR_RED "  ch[0~9][0]"
#define INSTRUCTIONOF_CHAPTER_LEVEL1_TAIL "\t[……………………]ch[所属章节名重点知识列表][是否全部展示]"

#define INSTRUCTIONOF_CHAPTER_LEVEL2_1th_GREED "\n\n  \tch0"
#define INSTRUCTIONOF_CHAPTER_LEVEL2_1th_TAIL "\t[……………………][展示本书所有重点知识所在章节及全部内容]"

#define INSTRUCTIONOF_CHAPTER_LEVEL2_2th_GREED "\n\n  \tch1"
#define INSTRUCTIONOF_CHAPTER_LEVEL2_2th_TAIL "\t[……………………][仅展示第1章重点知识列表]"

#define INSTRUCTIONOF_CHAPTER_LEVEL2_3th_GREED "\n\n  \tch10"
#define INSTRUCTIONOF_CHAPTER_LEVEL2_3th_TAIL "\t[……………………][展示第1章重点知识列表及全部内容]"

#define INSTRUCTIONOF_CHAPTER_LEVEL2_4th_GREED "\n  \tch90"
#define INSTRUCTIONOF_CHAPTER_LEVEL2_4th_TAIL "\t[……………………][展示第9章重点知识列表及全部内容]\n\n\n"



//第4条指令 help 

#define INSTRUCTIONOF_HELP_LEVEL1_HEAD "帮助指令:\n\n"
#define INSTRUCTIONOF_HELP_LEVEL1_COLOR_RED "  h|help[0]"
#define INSTRUCTIONOF_HELP_LEVEL1_TAIL "\t[……………………]h|help[0][查看指令集][进入指令教学系统]"

#define INSTRUCTIONOF_HELP_LEVEL2_1th_GREED "\n\n  \th[elp]"
#define INSTRUCTIONOF_HELP_LEVEL2_1th_TAIL "\t[……………………][查看所有指令集]"

#define INSTRUCTIONOF_HELP_LEVEL2_2th_GREED "\n\n  \th[elp]0"
#define INSTRUCTIONOF_HELP_LEVEL2_2th_TAIL "\t[……………………][进入指令教学系统]\n\n\n"

//第5条指令 girl 
#define INSTRUCTIONOF_GIRL1 "其他指令:\n\n"
#define INSTRUCTIONOF_GIRL2 "  lj|girl"
#define INSTRUCTIONOF_GIRL3 "\n \t\t[……………………][一个女孩]\n\n\n"


//第6条指令 story 
#define INSTRUCTIONOF_STORY1 "  st|story"
#define INSTRUCTIONOF_STORY2 "\n \t\t[……………………][了解软件背后的故事]\n\n\n"

//help主页面
//页面里面有三种不同速率的输出，而且还加有极高速率输出
//直接将其他几类速率函数封装进此函数中

void help_page(int sleep_time1, int sleep_time2, int sleep_time3, int interval_num_to_sleep);
