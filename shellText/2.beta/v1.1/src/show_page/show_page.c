#include "../../include/show_page.h"

void show_page(int page_num)
{
    printf("第%s%d%s页\n", BOLD, page_num, RESET);
    // printf("这里接下来会引入每一页的内容----------------------------------------\n");
    switch (page_num)
    {
    case 1:
        printf(PAGE_1);
        break;
    case 2:
        printf(PAGE_2);
        break;
    default:
        printf("这个页码内容有待上传！！\n");
        break;
    }
}
