# ifndef ENDSAY_H
# define ENDSAY_H
#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
// 定义包含ASCII艺术字的宏
#define ENDSAY \
"                        _   _                \n" \
"                       | | | |               \n" \
"   __ _  ___   ___   __| | | |__  _   _  ___ \n" \
"  / _` |/ _ \\ / _ \\ / _` | | '_ \\| | | |/ _ \\ \n" \
" | (_| | (_) | (_) | (_| | | |_) | |_| |  __/ \n" \
"  \\__, |\\___/ \\___/ \\__,_| |_.__/ \\__, |\\___| \n" \
"   __/ |                           __/ |     \n" \
"  |___/                           |___/       "

void exit_signal_handler(int signum);
#endif