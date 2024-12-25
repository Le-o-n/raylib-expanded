#include "game_window.h"



void GameWindow_Context_init(
    GameWindow_Context* game_window, 
    int width,
    int height,
    const char* title
){
    if (game_window == 0){
        return;
    }

    game_window->last_width = width;
    game_window->last_height = height;

    Raylib_Window_init(
        width, 
        height, 
        title
    );
}

void GameWindow_Context_update(GameWindow_Context* game_window){
    if (game_window == 0){
        return;
    }
    
    if (Raylib_Window_shouldClose()) {
        Config_isRunning = 0; 
    }
}

void GameWindow_Context_unload(GameWindow_Context* game_window){
    if (game_window == 0){
        return;
    }

    // unload

    
}

