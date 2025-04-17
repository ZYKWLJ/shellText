#ifndef MATCH_H
#define MATCH_H
#include <stdlib.h>
#include <string.h>
#include"../words_lib/words.h"
extern word_entry **library[LIB_NUM];
int find_exact(const char *str, int library_index, word_entry *result);
//  前缀匹配函数
int prefix_match(const char *str, const char *prefix);
// 前缀查找单词
int find_prefix(const char *str, int library_index, word_entry *result);

// 后缀匹配
int suffix_match(const char *str, const char *suffix);

// 后缀查找单词
int find_suffix(const char *str, int library_index, word_entry *result);
// 包含匹配函数
int contains_match(const char *str,const char *sub_str);

int find_contain(const char *str, int library_index, word_entry *result);
int find_contain_chinese(const char *str, int library_index, word_entry *result);
#endif