import pandas as pd

# 用于存储每个字母开头的单词列表
word_lists = {chr(i + 97): [] for i in range(26)}

# 读取Excel文件，这里假设文件名为words.xlsx，可按需修改
df = pd.read_excel('cet4.xls')
# 提取第二列（假设列索引从0开始）
word_column = df.iloc[:, 1]

for word in word_column:
    if isinstance(word, str):
        first_letter = word[0].lower()
        if first_letter.isalpha():
            word_lists[first_letter].append(word)

for letter, words in word_lists.items():
    array_name = f"{letter}_4"
    print(f"const char *{array_name}[] = {{")
    for word in words:
        print(f'    "{word}",')
    print('    NULL,')
    print('};')

'''
新需求：

背景：

我有一份excel文件，如图，现在我想把单词列提取出来，输出格式为：
const char *a_4[][][] = {
    {"abandon","/əˈbændən/","v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {"ability",	"/əˈbɪləti/"	,"n. 能力，能耐；才能"},
    NULL,
};
所有单词会输出26个数组，就像上面一样，数组名为开头单词字母_4,然后每一个元素是3维数组，第一维度是excel里面的"单词"列，第二维度是excel里面的"音标"列，第三维度是excel里面的"释义"列，请你输出这26个数组。
每一个数组会输出在两个文件里面，一个是头文件，一个是主文件，主文件名为开头单词字母_4.c，比如，a_4.c，b_4.c，c_4.c，头文件名字仅仅是变为.h后缀，例如：a_4.h，b_4.h，c_4.c
h，以此类推。

头文件输出的绝对路径为：/home/eyk/1code/shellText/shellText/3.engliux/v1.0/include/words_lib/lib4_3
主文件输出的绝对路径为：/home/eyk/1code/shellText/shellText/3.engliux/v1.0/src/words_lib/lib4_3

以下是例子：
比如这是a_4.h的内容：
头文件：
```c
# ifndef A_4_H
# define A_4_H
#include<stdlib.h>
# endif
```

这是a_4.c的内容：
主文件：
```c
# include "../../../include/words_lib/lib4/a_4.h"
const char *a_4[] = {
    {"abandon","/əˈbændən/","v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {"ability",	"/əˈbɪləti/"	,"n. 能力，能耐；才能"},
    // 这里省略了其他单词
    NULL,//注意每一个主文件最后都要加上NULL
};

```
请你完成这个任务
'''