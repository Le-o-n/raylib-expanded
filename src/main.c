//#include "my_game.h"
#include "data_structures/linked_list.h"
#include "data_structures/array.h"
#include "data_structures/hashmap.h"
#include "raylib_wrapper.h"
#include <stdio.h>

size_t Main_stringHash(void* string_ptr) {
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

int main(void)
{
    Raylib_Vector2 vec2;
    vec2.x = 100.0f;
    vec2.y = 200.0f;

    char* my_string = "Hi there\0";

    Main_stringHash((void*)my_string);

    //HashMap_Map hash_map;
    //hash_map = HashMap_Map_init(
    //    &hash_map,)
    
    
    return 0;
}