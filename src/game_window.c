#include "game_window.h"



void GameWindow_Context_init(
    GameWindow_Context* context, 
    int width,
    int height,
    const char* title
){
    if (context == 0){
        return;
    }

    context->last_width = width;
    context->last_height = height;

    Raylib_Window_init(
        width, 
        height, 
        title
    );
}

void GameWindow_Context_update(GameWindow_Context* context){
    if (context == 0){
        return;
    }
    
    if (Raylib_Window_shouldClose()) {
        Config_isRunning = 0; 
    }
}

void GameWindow_Context_unload(GameWindow_Context* context){
    if (context == 0){
        return;
    }

    // unload

    
}

