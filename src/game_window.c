#include "game_window.h"
#include "config.h"

void InitGameWindow(){
    InitWindow(
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        WINDOW_TITLE
    );
}

void UpdateGameWindow(void) {
    
    if (WindowShouldClose()) {
        isRunning = false; 
    }

}


void UnloadGameWindow(void){
    
}