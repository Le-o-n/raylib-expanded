#ifndef HASH_STRING_H
#define HASH_STRING_H

#include <stddef.h>

size_t Hashing_stringSum(void* string_ptr) {
    char* char_string = (char*)string_ptr;
    char* cur_char = char_string;
    size_t hash = 0;
    size_t prime = 31; // A small prime number
    size_t length = 0;

    while (*cur_char != '\0') {
        hash = hash * prime + (size_t)(*cur_char);
        cur_char++;
        length++;
    }

    return hash;
}


#endif 