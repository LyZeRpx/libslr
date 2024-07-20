import os
import re

def load_keywords(config_file):
    with open(config_file, 'r') as file:
        keywords = [line.strip() for line in file.readlines()]
    return keywords

def count_keyword_in_file(filepath, keyword):
    with open(filepath, 'r', encoding='utf-8') as file:
        content = file.read()
        pattern = f'(^|[ ,.:;\'"\\-\\!\\?]){re.escape(keyword)}([ ,.:;\'"\\-\\!\\?]|$)'
        matches = re.findall(pattern, content, re.MULTILINE)
        return len(matches)

def process_directory(directory_path, keywords):
    output_file = 'matches.txt'
    with open(output_file, 'w') as output:
        for filename in os.listdir(directory_path):
            filepath = os.path.join(directory_path, filename)
            if os.path.isfile(filepath):
                print(f"Processing file: {filepath}")
                output.write(f"File: {filepath}:\n")

                for keyword in keywords:
                    count = count_keyword_in_file(filepath, keyword)
                    print(f"\tKeyword '{keyword}': {count} matches")
                    output.write(f"\tKeyword '{keyword}': {count} matches\n")

                print()
                output.write("\n")

if __name__ == "__main__":
    directory_path = './files'
    config_file = 'config/keywords.conf'

    keywords = load_keywords(config_file)
    process_directory(directory_path, keywords)
