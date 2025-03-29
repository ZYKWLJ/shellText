import xlrd
import os


# 定义结构体类型
include_definition = """#include "../word_set.h"
"""

# 定义结构体类型
struct_definition = """typedef struct {
    const char *index;
    const char *word;
    const char *phonetic;
    const char *meaning;

} word_entry;
"""


# 读取 Excel 文件
def read_excel(file_path):
    workbook = xlrd.open_workbook(file_path)
    sheet = workbook.sheet_by_index(0)
    data = []
    for row_index in range(1, sheet.nrows):  # 跳过表头
        # 将序号转换为整数类型
        index = int(sheet.cell_value(row_index, 0))
        row_data = {
            'index': str(index),
            'word': sheet.cell_value(row_index, 1),
            'phonetic': sheet.cell_value(row_index, 2),
           'meaning': sheet.cell_value(row_index, 3)
        }
        data.append(row_data)
    return data


# 按首字母分类数据
def categorize_data(data):
    categorized = {}
    for item in data:
        word = item['word']
        first_letter = word[0].lower()
        if first_letter not in categorized:
            categorized[first_letter] = []
        categorized[first_letter].append(item)
    return categorized


# 生成头文件内容
def generate_header_content(excel_filename, first_letter):
    header_name = f"{excel_filename}_{first_letter}".upper()
    content = f"""#ifndef {header_name}_H
#define {header_name}_H
#include<stdlib.h>
{include_definition}
#endif
"""
    return content


# 生成主文件内容
def generate_source_content(excel_filename, first_letter, data):
    array_name = f"{excel_filename}_{first_letter}"
    content = f'#include "../../../include/words_lib/{excel_filename}/{excel_filename}_{first_letter}.h"\n'
    content += f"word_entry {array_name}[1000] = {{\n"
    for item in data:
        content += f"    {{\n"
        content += f'        "{item["index"]}",\n'
        content += f'        "{item["word"]}",\n'
        content += f'        "{item["phonetic"]}",\n'
        content += f'        "{item["meaning"]}",\n'
        # content += '        NULL\n'
        content += '    },\n'
    # 在每个单词集最后添加结尾标记
    content += '    {NULL, NULL, NULL, NULL},\n'
    content += '};\n'
    return content


# 保存文件
def save_files(excel_filename, first_letter, header_content, source_content, header_dir, source_dir):
    header_filename = os.path.join(header_dir, f"{excel_filename}_{first_letter}.h")
    source_filename = os.path.join(source_dir, f"{excel_filename}_{first_letter}.c")
    with open(header_filename, 'w', encoding='utf-8') as header_file:
        header_file.write(header_content)
    with open(source_filename, 'w', encoding='utf-8') as source_file:
        source_file.write(source_content)


# 主函数
def main():
    excel_file_path = "cet6.xls"  # 请改成实际的 Excel 文件名
    excel_filename = os.path.splitext(os.path.basename(excel_file_path))[0]
    header_dir = "/home/eyk/1code/shellText/shellText/3.engliux/v.ok/include/words_lib/" + excel_filename
    source_dir = "/home/eyk/1code/shellText/shellText/3.engliux/v.ok/src/words_lib/" + excel_filename

    # 创建目录
    os.makedirs(header_dir, exist_ok=True)
    os.makedirs(source_dir, exist_ok=True)

    excel_data = read_excel(excel_file_path)
    categorized_data = categorize_data(excel_data)

    for first_letter, sub_data in categorized_data.items():
        header_content = generate_header_content(excel_filename, first_letter)
        source_content = generate_source_content(excel_filename, first_letter, sub_data)
        save_files(excel_filename, first_letter, header_content, source_content, header_dir, source_dir)


if __name__ == "__main__":
    main()
    