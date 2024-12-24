#include "game_window.h"
#include "config.h"
#include "raylib_wrapper.h"

void GameWindow_init(){
    InitWindow(
        Config_SCREEN_WIDTH, 
        Config_SCREEN_HEIGHT, 
        Config_WINDOW_TITLE
    );
}

void GameWindow_update(void) {

    if (Raylib_Window_shouldClose()) {
        Config_isRunning = 0; 
    }

}


void GameWindow_unload(void){
    
}