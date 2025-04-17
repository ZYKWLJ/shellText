#include "../../../include/shellText/text_show_page.h"

void show_page(int page_num)
{
    printf("第%s%d%s页\n", BOLD, page_num, RESET);
    // printf("这里接下来会引入每一页的内容----------------------------------------\n");
    printf("%s",all_pages[page_num - 1]);
}
