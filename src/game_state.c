#include "game_state.h"




void GameState_Context_init(GameState_Context* context){
    if (context == 0){
        return;
    }

}

void GameState_Context_update(GameState_Context* context) {
    if (context == 0){
        return;
    }



}

void GameState_Context_draw(GameState_Context* context) {
    if (context == 0){
        return;
    }

    Raylib_Draw_beginDrawing();
    Raylib_Draw_clearBackground(Raylib_Colour_RAYWHITE);
    Raylib_Draw_drawRectangle(
        100, 
        100, 
        200, 
        100, 
        Raylib_Colour_BLUE
    );

    Raylib_Draw_drawRectangle(
        350, 
        250, 
        100, 
        100, 
        Raylib_Colour_GREEN
    );

    Raylib_Draw_endDrawing();


}

void GameState_Context_unload(GameState_Context* context){
    if (context == 0){
        return;
    }
}
