# include "../../../include/englinux/display/eg_find_help.h"
void find_help(){
    const char*find[]={TOKEN1,TOKEN2,TOKEN3,TOKEN4,NULL};
    const char* find_description[]={TOKEN1_DESC,TOKEN2_DESC,TOKEN3_DESC,TOKEN4_DESC,NULL};
    const char **columns[] = {find, find_description};
    eg_print(columns, sizeof(columns) / sizeof(columns[0]));
}