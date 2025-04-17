import os

# 目标目录
target_dir = "/home/eyk/1code/shellText/shellText/2.beta/v1.1/src/ShellText"

# 遍历目录树
for root, dirs, files in os.walk(target_dir):
    for file in files:
        file_path = os.path.join(root, file)
        try:
            # 读取文件内容
            with open(file_path, 'r', encoding='utf-8') as f:
                content = f.read()

            # 替换 #include "../../ 为 #include "../../../
            new_content = content.replace('#include "../../', '#include "../../../')

            # 将修改后的内容写回文件
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(new_content)

            print(f"已修改文件: {file_path}")
        except:
            print(f"处理文件 {file_path} 时出错，可能是编码问题或其他原因。")