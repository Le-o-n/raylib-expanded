

def string_sum01(string: str) -> int:
    
    prime: int = 31
    hash_val: int = 0
    for i, char in enumerate(string):
        hash_val = hash_val*prime + ord(char)
    
    return hash_val


def string_sum02(string: str) -> int:
    
    prime: int = 31
    hash_val: int = 0
    for i, char in enumerate(string):
        hash_val = hash_val*prime + i*ord(char)
    
    return hash_val

def string_sum03(string: str) -> int:
    
    prime: int = 31
    hash_val: int = 0
    for i, char in enumerate(string):
        hash_val = prime*(hash_val + i*ord(char))
    
    return hash_val

def string_sum04(string: str) -> int:
    
    prime: int = 31
    hash_val: int = 0
    for i, char in enumerate(string):
        hash_val = prime*(hash_val + ord(char))
    
    return hash_val

