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

# 遍历目录下的文件
for filename in os.listdir(directory):
    if filename in target_files:
        old_file_path = os.path.join(directory, filename)
        new_filename = f"text_{filename}"
        new_file_path = os.path.join(directory, new_filename)
        # 重命名文件
        os.rename(old_file_path, new_file_path)
        print(f"已将 {old_file_path} 重命名为 {new_file_path}")