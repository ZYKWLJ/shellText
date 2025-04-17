import os

def replace_in_files(directory, old_text, new_text):
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()

                new_content = content.replace(old_text, new_text)

                if new_content != content:
                    with open(file_path, 'w', encoding='utf-8') as f:
                        f.write(new_content)
                    print(f"已更新文件: {file_path}")
            except Exception as e:
                print(f"处理文件 {file_path} 时出错: {e}")

if __name__ == "__main__":
    directory = "/home/eyk/1code/shellText/shellText/2.beta/v1.1/src/shellText/chapters"
    old_text = '#include "#include "../../../include/shellText/chapters/text_chapter'
    new_text = '#include "../../../include/shellText/chapters/text_chapter'
    replace_in_files(directory, old_text, new_text)    