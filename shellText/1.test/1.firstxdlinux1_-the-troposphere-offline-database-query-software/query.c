#include "main.h"


//指令匹配函数
void Query(char* QueryKeywords)
{
    //查询语句软编码
    char query[1024];
    snprintf(query, sizeof(query), "SELECT * FROM `%s`", QueryKeywords);

    // 执行SQL查询
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query error: %s\n", mysql_error(conn));
        //mysql_close(conn);
        return;
    }

    // 处理查询结果集
    res = mysql_store_result(conn);
    if (res == NULL) {

        //在这里做模糊匹配
        //SHOW TABLES LIKE '%pattern%'
        printf("匹配到下列数据表，请输入完整表名以获取:\n");
        snprintf(query, sizeof(query), "SHOW TABLES LIKE `%s`", QueryKeywords);
        res = mysql_store_result(conn);
        fprintf(stderr, "Could not store result set\n");
        //mysql_close(conn);
        return;
    }

    printf("Result rows:\n");
    while ((row = mysql_fetch_row(res))) {
        for (unsigned int i = 0; i < mysql_num_fields(res); ++i) {
            printf("%-20s", row[i] ? row[i] : "NULL");
        }
        puts("");

    }

    // 释放结果集
    mysql_free_result(res);
}
