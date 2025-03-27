#include "todo.h"

//这里以后是导入的数据
void todo()
{
    const char* str = "这是以后需要导入的数据\n";
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("%s%s%s", RED_TEXT, str, RESET_COLOR);
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("%s%s%s", GREEN_TEXT, TODO, RESET_COLOR);
    printf("\n\n");
}
