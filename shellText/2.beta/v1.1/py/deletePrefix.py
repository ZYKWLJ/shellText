import os

# 指定目录
directory = '/home/eyk/1code/shellText/shellText/2.beta/v1.1/include/shellText/temp'

# 使用 os.walk 遍历目录及其子目录
for root, dirs, files in os.walk(directory):
    for file in files:
        if file.startswith('text_'):
            # 去除 text_ 前缀
            new_file = file[len('text_'):]
            old_path = os.path.join(root, file)
            new_path = os.path.join(root, new_file)
            try:
                # 重命名文件
                os.rename(old_path, new_path)
                print(f"已将 {old_path} 重命名为 {new_path}")
            except Exception as e:
                print(f"重命名 {old_path} 时出错: {e}")