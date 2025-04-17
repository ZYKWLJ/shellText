import os

# 指定目录
directory = '/home/eyk/1code/shellText/shellText/2.beta/v1.1/include/shellText'

# 定义需要替换的内容和替换后的内容，使用字典存储
replace_dict = {
   'enter_help.h': 'text_enter_help.h',
    'show_page.h': 'text_show_page.h',
    'endSay.h': 'text_endSay.h',
    'myTime.h': 'text_myTime.h',
    'copyRight.h': 'text_copyRight.h',
    'all_pages.h': 'text_all_pages.h',
    'help.h': 'text_help.h',
    'find.h': 'text_find.h',
    'eliminateSpace.h': 'text_eliminateSpace.h',
    'color.h': 'text_color.h',
    'subject.h': 'text_subject.h',
    'choose_language.h': 'text_choose_language.h',
    'rain.h': 'text_rain.h',
    'chapter_show.h': 'text_chapter_show.h',
    'page_preprocess.h': 'text_page_preprocess.h',
    'similarInstructions.h': 'text_similarInstructions.h',
    'instructionList.h': 'text_instructionList.h',
    'author.h': 'text_author.h',
    'execute.h': 'text_execute.h',
    'story.h': 'text_story.h',
    # 你可以在这里添加更多的替换规则，格式为 '原内容': '替换后的内容'
}

# 遍历目录及其子目录
for root, dirs, files in os.walk(directory):
    for file in files:
        file_path = os.path.join(root, file)
        try:
            # 读取文件内容
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()

            # 进行替换操作
            new_content = content
            for old_text, new_text in replace_dict.items():
                new_content = new_content.replace(old_text, new_text)

            # 如果内容有变化，则写回文件
            if new_content != content:
                with open(file_path, 'w', encoding='utf-8') as f:
                    f.write(new_content)
                print(f"已更新文件: {file_path}")
        except Exception as e:
            print(f"处理文件 {file_path} 时出错: {e}")