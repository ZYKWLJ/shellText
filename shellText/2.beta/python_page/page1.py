import os
import pytesseract
from pdf2image import convert_from_path
from PIL import Image

# 指定 Tesseract 可执行文件的路径
pytesseract.pytesseract.tesseract_cmd = r'/usr/bin/tesseract'

def pdf_to_h_files(pdf_path, output_dir, max_pages):
    # 创建输出目录
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # 将 PDF 转换为图像列表
    images = convert_from_path(pdf_path)
    total_pages = min(len(images), max_pages)

    for page_num, image in enumerate(images, start=1):
        # 只处理指定的页数
        if page_num > max_pages:
            break

        # 使用 pytesseract 进行 OCR 识别
        text = pytesseract.image_to_string(image, lang='chi_sim+eng')  # 识别中文和英文
        # 替换 \ 为 |，替换 " 为 ”
        text = text.replace('\\', '|').replace('"', '”')
        text_lines = text.split('\n')
        processed_text = []
        for line in text_lines:
            processed_text.append(line.strip() + '\\n" \\\n"')
        content = ''.join(processed_text)
        content = content.rstrip('\\n" \\\n"')
        header_content = f'#ifndef PAGE_{page_num+330}_H\n#define PAGE_{page_num+330}_H\n#define PAGE_{page_num+330} \\\n"{content}"\n#endif'

        # 生成输出文件路径
        output_path = os.path.join(output_dir, f'page{page_num+330}.h')
        with open(output_path, 'w', encoding='utf - 8') as h_file:
            h_file.write(header_content)

        # 计算并显示进度
        progress = (page_num / total_pages) * 100
        print(f"已完成第 {page_num} 页，当前进度: {progress:.2f}%")


if __name__ == "__main__":
    pdf_path = '/home/eyk/文档/xwechat_files/wxid_4qgi1qtrnr6w22_553c/msg/file/2025-04/331-430.pdf'
    output_dir = '/home/eyk/1code/shellText/shellText/2.beta/python_page/pages2'
    max_pages = 100  # 可根据需要修改为其他页数
    pdf_to_h_files(pdf_path, output_dir, max_pages)
    