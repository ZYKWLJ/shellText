# import os

# # 目标目录
# target_dir = "/home/eyk/1code/shellText/shellText/2.beta/v1.1/include/shellText"

# # 遍历目录下的所有文件和目录
# for root, dirs, files in os.walk(target_dir):
#     for file in files:
#         old_file_path = os.path.join(root, file)
#         new_file_name = f"text_{file}"
#         new_file_path = os.path.join(root, new_file_name)
#         os.rename(old_file_path, new_file_path)
#         print(f"已将 {old_file_path} 重命名为 {new_file_path}")

