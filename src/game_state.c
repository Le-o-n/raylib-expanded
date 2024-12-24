#include "game_state.h"

void GameState_init(void){
    
}

void GameState_update(void) {
    
}

void GameState_draw(void) {
    
    Raylib_Draw_beginDrawing();
    Raylib_Draw_clearBackground(Raylib_Colour_RAYWHITE);
    Raylib_Draw_drawRectangle(
        100, 
        100, 
        200, 
        100, 
        Raylib_Colour_BLUE
    );

    Raylib_Draw_endDrawing();
}

void GameState_unload(void){

}
