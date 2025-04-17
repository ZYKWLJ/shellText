import os

# 指定目录
directory = '/home/eyk/1code/shellText/shellText/2.beta/v1.1/include/shellText'

# 用于存储处理后的文件名
file_names = []

# 使用 os.walk 遍历目录及其子目录
for root, dirs, files in os.walk(directory):
    for file in files:
        # 去除文件名的 text_ 前缀
        if file.startswith('text_'):
            file = file[len('text_'):]
        file_names.append(file)

print(file_names)