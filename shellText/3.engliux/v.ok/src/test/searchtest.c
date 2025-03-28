// #include "../../include/search.h"
// // int main()
// // {
// // }
// void search_in_single_library(char **result, int *result_count, const char ***single_library, char *str, int search_type)
// {
//     if (single_library == NULL)
//         return;
//     for (int i = 0; single_library[i] != NULL /*单个库的列表里面就是二维数组，直接用高亮函数*/; i++)
//     {
//         // 即时调用 find_and_highlight 函数
//         find_and_highlight(single_library[i], sizeof(single_library[i])/sizeof(single_library[i][0]), str);
//     }
// }