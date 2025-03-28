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

我有一份excel文件，如图，现在我想把单词列提取出来，输出格式为：
const char *a_4[][][] = {
    {"abandon","/əˈbændən/","v. 遗弃；离开；放弃；终止；陷入n. 放任，狂热"},
    {"ability",	"/əˈbɪləti/"	,"n. 能力，能耐；才能"},
    NULL,
};
所有单词会输出26个数组，就像上面一样，数组名为开头单词字母_4,然后每一个元素是3维数组，请你输出这26个数组个数组，每个数组里面存放着该首字母开头的单词。
'''