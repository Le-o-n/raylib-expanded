import os
from typing import Generator

filedir: str = os.path.abspath(
    os.path.dirname(__file__)
)

words_txt_path: str = os.path.join(
    filedir,
    "words.txt"
)

def yield_word(
) -> Generator[str, None, None]:
    with open(words_txt_path, 'r') as file:
        for line in file:
            # Strip any leading/trailing whitespace and yield the word
            word = line.strip()
            if word:  # Only yield non-empty words
                yield word
    
