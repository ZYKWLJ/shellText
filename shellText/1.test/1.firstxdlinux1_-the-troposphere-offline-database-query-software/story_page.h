#pragma once
#include "main.h"
//这是涉及到story_page的展现控制 
#define STORY_SLEEP_TIME1 20    
#define STORY_SLEEP_TIME2 1
//每个10次才休眠一次，会更快！！ 
#define STORY_INTERVAL_NUM_TO_SLEEP 10

//软件背后的故事
void story_page(int sleep_time1, int sleep_time2, int interval_num_to_sleep);
