# import xlrd
# import os

# def read_excel(file_path):
#     wb = xlrd.open_workbook(file_path)
#     sheet = wb.sheet_by_index(0)
#     data = []
#     for row_index in range(1, sheet.nrows):  # 跳过表头
#         row = sheet.row_values(row_index)
#         data.append(row)
#     return data

# # 按首字母分类数据
# def categorize_data(data):
#     categorized_data = {chr(i + 97): [] for i in range(26)}
#     for row in data:
#         word = row[0]
#         if isinstance(word, str):
#             first_letter = word[0].lower()
#             if first_letter.isalpha():
#                 categorized_data[first_letter].append(row)
#     return categorized_data

# # 生成头文件内容
# def generate_header_file_content(array_name):
#     header_content = f"""
# #ifndef {array_name.upper()}_H
# #define {array_name.upper()}_H
# #include<stdlib.h>
# #endif
# """
#     return header_content

# # 生成主文件内容
# def generate_source_file_content(array_name, data):
#     source_content = f"""
# #include "../../../include/words_lib/lib4_3/{array_name}.h"
# const char *{array_name}[][3] = {{
# """
#     for row in data:
#         source_content += f'    {{"{row[0]}", "{row[1]}", "{row[2]}"}},\n'
#     source_content += '    NULL\n'
#     source_content += "};"
#     return source_content

# # 保存文件
# def save_files(array_name, header_content, source_content, header_path, source_path):
#     with open(os.path.join(header_path, f"{array_name}.h"), 'w') as header_file:
#         header_file.write(header_content)
#     with open(os.path.join(source_path, f"{array_name}.c"), 'w') as source_file:
#         source_file.write(source_content)

# if __name__ == "__main__":
#     excel_file_path = 'cet4.xls'  # 请替换为实际的Excel文件名
#     header_output_path = "/home/eyk/1code/shellText/shellText/3.engliux/v1.0/include/words_lib/lib4_3"
#     source_output_path = "/home/eyk/1code/shellText/shellText/3.engliux/v1.0/src/words_lib/lib4_3"

#     excel_data = read_excel(excel_file_path)
#     categorized_data = categorize_data(excel_data)

#     for letter, sub_data in categorized_data.items():
#         array_name = f"{letter}_4"
#         header_content = generate_header_file_content(array_name)
#         source_content = generate_source_file_content(array_name, sub_data)
#         save_files(array_name, header_content, source_content, header_output_path, source_output_path)



import xlrd
import os


# 读取 Excel 文件
def read_excel(file_path):
    try:
        wb = xlrd.open_workbook(file_path)
        sheet = wb.sheet_by_index(0)
        data = []
        for row_index in range(1, sheet.nrows):  # 跳过表头
            row = sheet.row_values(row_index)
            data.append(row)
        print(f"成功读取 {len(data)} 行数据")
        return data
    except Exception as e:
        print(f"读取 Excel 文件时出错: {e}")
        return []


# 按首字母分类数据
def categorize_data(data):
    categorized_data = {chr(i + 97): [] for i in range(26)}
    for row in data:
        if len(row) >= 3 and isinstance(row[1], str):  # 确保有单词、音标、释义，且单词为字符串
            word = row[1]
            first_letter = word[0].lower()
            if first_letter.isalpha():
                categorized_data[first_letter].append(row[1:])  # 取单词、音标、释义三列
    for letter, sub_data in categorized_data.items():
        print(f"{letter}_6 分类数据数量: {len(sub_data)}")
    return categorized_data


# 生成头文件内容
def generate_header_file_content(array_name):
    header_content = f"""
#ifndef {array_name.upper()}_H
#define {array_name.upper()}_H
#include<stdlib.h>
#endif
"""
    return header_content


# 生成主文件内容
def generate_source_file_content(array_name, data):
    source_content = f"""
#include "../../../include/words_lib/lib6_3/{array_name}.h"
const char *{array_name}[][3] = {{
"""
    for row in data:
        source_content += f'    {{"{row[0]}", "{row[1]}", "{row[2]}"}},\n'
    source_content += '    NULL\n'
    source_content += "};"
    return source_content


# 保存文件
def save_files(array_name, header_content, source_content, header_path, source_path):
    try:
        with open(os.path.join(header_path, f"{array_name}.h"), 'w') as header_file:
            header_file.write(header_content)
        with open(os.path.join(source_path, f"{array_name}.c"), 'w') as source_file:
            source_file.write(source_content)
        print(f"已成功生成 {array_name}.h 和 {array_name}.c 文件")
    except Exception as e:
        print(f"保存 {array_name} 文件时出错: {e}")


if __name__ == "__main__":
    excel_file_path = 'cet6.xls'
    header_output_path = "/home/eyk/1code/shellText/shellText/3.engliux/v1.0/include/words_lib/lib6_3"
    source_output_path = "/home/eyk/1code/shellText/shellText/3.engliux/v1.0/src/words_lib/lib6_3"

    # 检查输出目录是否存在，不存在则创建
    if not os.path.exists(header_output_path):
        os.makedirs(header_output_path)
    if not os.path.exists(source_output_path):
        os.makedirs(source_output_path)

    excel_data = read_excel(excel_file_path)
    if not excel_data:
        print("未读取到有效数据，请检查 Excel 文件。")
    else:
        categorized_data = categorize_data(excel_data)

        for letter, sub_data in categorized_data.items():
            array_name = f"{letter}_6"
            header_content = generate_header_file_content(array_name)
            source_content = generate_source_file_content(array_name, sub_data)
            save_files(array_name, header_content, source_content, header_output_path, source_output_path)