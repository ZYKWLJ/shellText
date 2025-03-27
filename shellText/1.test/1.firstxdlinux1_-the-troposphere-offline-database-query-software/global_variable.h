#pragma once
#include "main.h"
#include <mysql.h>

//数据库连接全局变量
extern MYSQL* conn;
extern MYSQL_RES* res;
extern MYSQL_ROW row;

//存放所有表名
extern int table_count;
extern char table_name[MAX_TABLE_NAME_LENGTH];
extern char** table_names;

extern int ch; //清空缓存区的

//算字符长度用到
extern size_t len;

//每次打印的标头
extern char header[100];

//键入搜索关键字
extern char QueryKeywords[100];

