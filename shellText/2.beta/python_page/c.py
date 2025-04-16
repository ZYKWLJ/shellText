code = 'char *all_pages[500] = {\n'
for i in range(1, 301):
    code += f'    PAGE_{i},\n'
code += '    "NULL"\n};\n'

print(code)