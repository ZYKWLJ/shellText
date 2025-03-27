// #ifndef _MAIN_H_
// #define _MAIN_H_
// #include <stdio.h>
// #include "my.h"
// #endif

#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
// 移除对 my.h 的包含，避免循环包含
#include "my.h"
#endif