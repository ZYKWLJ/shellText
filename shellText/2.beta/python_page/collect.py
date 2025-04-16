import os

# 目标目录
target_dir = "/home/eyk/1code/shellText/shellText/2.beta/python_page/pages2"

# 遍历目录下的所有文件
for filename in os.listdir(target_dir):
    if filename.endswith(".h"):
        file_path = os.path.join(target_dir, filename)
        # 读取文件内容
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.read()

        # 提取原来的 PAGE_XXX_H 部分
        start_index = content.find("#ifndef PAGE_") + len("#ifndef PAGE_")
        end_index = content.find("_H", start_index)
        old_page_num = int(content[start_index:end_index])

        # 计算新的 PAGE_XXX_H 部分
        new_page_num = old_page_num + 30

        # 构建新的文件内容
        new_content = content.replace(
            f"PAGE_{old_page_num}_H", f"PAGE_{new_page_num}_H")
        new_content = new_content.replace(
            f"PAGE_{old_page_num}", f"PAGE_{new_page_num}")

        # 写回修改后的内容
        with open(file_path, 'w', encoding='utf-8') as file:
            file.write(new_content)

        print(f"已修改文件 {filename}")