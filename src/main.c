//#include "my_game.h"
#include "data_structures/linked_list.h"
#include "data_structures/array.h"
#include "data_structures/hashmap.h"
#include "hashing/string.h"
#include "compare/string.h"
#include "raylib_wrapper.h"
#include <stdio.h>


int main(void)
{
    Raylib_Vector2 vec2;
    vec2.x = 100.0f;
    vec2.y = 200.0f;

    HashMap_Map hashmap;

    HashMap_Map_init(
        &hashmap, 
        &Hashing_stringSum,
        &Compare_string,
        &HashMap_dataNoFree,
        &HashMap_dataNoFree,
        1
    );

    HashMap_Map_insert(
        &hashmap,
        (void*)"SomeKey1\0",
        (void*)"SomeValue1\0"
    );

    HashMap_Map_insert(
        &hashmap,
        (void*)"SomeKey2\0",
        (void*)"SomeValue2\0"
    );

    HashMap_Map_insert(
        &hashmap,
        (void*)"SomeKey3\0",
        (void*)"SomeValue3\0"
    );

    //LinkedList_List* linked_list = hashmap._array + 1;
    void* data1 = HashMap_Map_get(
        &hashmap,
        (void*)"SomeKey1\0"
    );

    void* data2 = HashMap_Map_get(
        &hashmap,
        (void*)"SomeKey2\0"
    );

    void* data3 = HashMap_Map_get(
        &hashmap,
        (void*)"SomeKey3\0"
    );

    HashMap_Map_deleteFrom( // Error Here
        &hashmap,
        (void*)"SomeKey2\0"
    );

    void* data2_removed = HashMap_Map_get(
        &hashmap,
        (void*)"SomeKey2\0"
    ); // should be 0

    return 0;
}