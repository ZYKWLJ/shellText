import os

# 指定目录
directory = '/home/eyk/1code/shellText/shellText/2.beta/v1.1/include/shellText'

# 要匹配的文件名列表
target_files = [
    'enter_help.h', 'show_page.h', 'endSay.h', 'myTime.h', 'copyRight.h',
    'all_pages.h', 'help.h', 'find.h', 'eliminateSpace.h', 'color.h',
    'subject.h', 'choose_language.h', 'rain.h', 'chapter_show.h',
    'page_preprocess.h', 'similarInstructions.h', 'instructionList.h',
    'author.h', 'execute.h', 'story.h'
]

# 用于存储文件名映射的字典
replace_dict = {}

# 使用 os.walk 遍历目录及其子目录
for root, dirs, files in os.walk(directory):
    for file in files:
        if file.startswith('text_'):
            # 去除前缀
            clean_name = file[len('text_'):]
            if clean_name in target_files:
                # 存储到字典
                replace_dict[clean_name] = file

# 打印结果
for key, value in replace_dict.items():
    print(f"'{key}': '{value}',")
    