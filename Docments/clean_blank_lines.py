import os
import re

def clean_file(filepath):
    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    cleaned_lines = [re.sub(r'^[ \t]+$', '', line) for line in lines]

    with open(filepath, 'w', encoding='utf-8') as f:
        f.writelines(cleaned_lines)

# 親ディレクトリから実行
# 直下のディレクトリ（1階層目）のみ対象
parent_dir = '.'
for entry in os.scandir(parent_dir):
    if entry.is_dir():
        for root, _, files in os.walk(entry.path):
            for file in files:
                if file.endswith('.cpp') or file.endswith('.hpp'):
                    full_path = os.path.join(root, file)
                    clean_file(full_path)
                    
# cd /Users/toruinoue/CPP/0817cpp04/my_cpp04
# find ex00 ex01 ex02 -type f \( -name "*.cpp" -o -name "*.hpp" \) -exec sed -i '' 's/^    /\t/g' {} +