import os

# 目标目录
target_dir = "/home/eyk/1code/shellText/shellText/2.beta/v1.1/include/shellText"

# 遍历目录下的所有文件和目录
for root, dirs, files in os.walk(target_dir):
    for file in files:
        old_file_path = os.path.join(root, file)
        if file.startswith("eg_"):
            new_file_name = file[len("eg_"):]
            new_file_path = os.path.join(root, new_file_name)
            os.rename(old_file_path, new_file_path)
            old_file_path = new_file_path

        try:
            # 读取文件内容
            with open(old_file_path, 'r', encoding='utf-8') as f:
                content = f.read()

            # 查找所有 #include 语句，并修改包含的文件名
            new_content = content
            start_index = 0
            while True:
                include_index = new_content.find('#include', start_index)
                if include_index == -1:
                    break
                quote_start_index = new_content.find('"', include_index)
                quote_end_index = new_content.find('"', quote_start_index + 1)
                if quote_start_index != -1 and quote_end_index != -1:
                    file_include = new_content[quote_start_index + 1:quote_end_index]
                    if file_include.startswith("text_"):
                        new_file_include = file_include[len("text_"):]
                        new_content = new_content[:quote_start_index + 1] + new_file_include + new_content[quote_end_index:]
                start_index = include_index + 1

            # 将修改后的内容写回文件
            with open(old_file_path, 'w', encoding='utf-8') as f:
                f.write(new_content)

            print(f"已处理文件: {old_file_path}")
        except:
            print(f"处理文件 {old_file_path} 时出错，可能是编码问题或其他原因。")