#include "../../../include/englinux/execute/eg_clear.h"
void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

}