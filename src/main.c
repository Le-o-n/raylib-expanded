//#include "my_game.h"
#include "data_structures/linked_list.h"
#include "data_structures/array.h"
#include "raylib_wrapper.h"
#include <stdio.h>

int main(void)
{
    Raylib_Vector2 vec2;
    vec2.x = 100.0f;
    vec2.y = 200.0f;

    Array_Dynamic array;

    Array_Dynamic_init(
        &array,
        (size_t)8,
        sizeof(Raylib_Vector2),
        2.0f,
        0.75f
    );

    for (size_t i=0; i<100; i++){
        printf("%d - %d\n", i, array.capacity);
        Array_Dynamic_append(
            &array,
            (const void*)&vec2
        );
    }

    Raylib_Vector2 outVec;

    Array_Dynamic_get(&array, 0, &outVec);

    printf("%f", outVec.x);

    
    outVec.x = 0.0f;
    outVec.y = 0.0f;

    printf("\n%d - %f", array.size, outVec.x);

    Array_Dynamic_pop(&array, &outVec);

    printf("\n%d - %f", array.size, outVec.x);



    Array_Dynamic_unload(&array);
    

    //MyGame_run();
    
    
    return 0;
}