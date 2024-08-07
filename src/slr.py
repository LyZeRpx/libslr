import os
import re

def load_keywords(config_file):
    with open(config_file, 'r') as file:
        keywords = {}
        for line in file:
            variations = line.strip().split('/')
            if variations:
                main_keyword = variations[0]
                keywords[main_keyword] = variations
    return keywords

def count_words_in_file(filepath):
    with open(filepath, 'r', encoding='utf-8') as file:
        content = file.read()
        words = re.findall(r'\b\w+\b', content)
        return len(words)

def count_keyword_variations_in_file(filepath, variations):
    with open(filepath, 'r', encoding='utf-8') as file:
        content = file.read()
        total_matches = 0
        for keyword in variations:
            pattern = f'(^|[ ,.:;\'"\\-\\!\\?]){re.escape(keyword)}([ ,.:;\'"\\-\\!\\?]|$)'
            matches = re.findall(pattern, content, re.MULTILINE | re.IGNORECASE)
            total_matches += len(matches)
        return total_matches

def process_directory(directory_path, keywords):
    output_file = 'trace.txt'
    with open(output_file, 'w') as output:
        for filename in os.listdir(directory_path):
            filepath = os.path.join(directory_path, filename)
            if os.path.isfile(filepath):
                print(f"Results for:\n {filename}")
                output.write(f"File: {filename}\n")

                total_words = count_words_in_file(filepath)
                total_keyword_matches = 0

                for main_keyword, variations in keywords.items():
                    count = count_keyword_variations_in_file(filepath, variations)
                    total_keyword_matches += count
                    print(f"\tKeyword variations '{'/'.join(variations)}': {count} matches")
                    output.write(f"\tKeyword variations '{'/'.join(variations)}': {count} matches\n")

                interest_score = (total_keyword_matches / total_words) * 100 if total_words > 0 else 0
                print(f"\tTotal words: {total_words}")
                print(f"\tTotal matches: {total_keyword_matches}")
                print(f"\tInterest score: {interest_score:.2f}%")
                output.write(f"\tTotal words: {total_words}\n")
                output.write(f"\tTotal matches: {total_keyword_matches}")
                output.write(f"\tInterest score: {interest_score:.2f}%\n\n")

                print()
                output.write("\n")

if __name__ == "__main__":
    directory_path = './files'
    config_file = 'config/keywords.txt'

    keywords = load_keywords(config_file)
    process_directory(directory_path, keywords)
