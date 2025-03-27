#include "main.h"

//数据库连接全局变量
MYSQL* conn = NULL;
MYSQL_RES* res = NULL;
MYSQL_ROW row = {0};

//存放所有表名
table_count = 0;
char table_name[MAX_TABLE_NAME_LENGTH] = { 0 };
char ** table_names = NULL;
 ch=0; //清空缓存区的

//算字符长度用到
  size_t len;