#include "main.h"
#include "mysql.h"



void all_table_name_print(MYSQL* conn);

//全部表名打印
void all_table_name_print(MYSQL* conn) {
    MYSQL_RES* res = NULL;
    MYSQL_ROW row;

    // 执行SHOW TABLES查询
    if (mysql_query(conn, "SHOW TABLES")) {
        fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    res = mysql_use_result(conn);
    char** table_names = (char**)malloc(MAX_TABLES * sizeof(char*));

    // 读取结果集，将表名添加到集合中
    while ((row = mysql_fetch_row(res)) && table_count < MAX_TABLES) {
        strncpy(table_name, row[0], MAX_TABLE_NAME_LENGTH - 1);
        table_name[MAX_TABLE_NAME_LENGTH - 1] = '\0'; // 添加字符串结束符
        table_names[table_count++] = strdup(table_name); // 使用 strdup 动态分配内存并复制字符串
    }

    mysql_free_result(res);

    // 打印获取到的表名
    for (int i = 0; i < table_count; ++i) {

        printf("Table name: %s\n", table_names[i]);
        free(table_names[i]); // 释放动态分配的内存


    }
}
