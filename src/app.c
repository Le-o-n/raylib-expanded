#include "app.h"
#include "game_state.h"
#include "game_window.h"
#include "ui.h"
#include "config.h"

int Config_isRunning = 1;

void App_init(void) {
    GameWindow_init();
    UI_init();
    GameState_init();
    
}

void App_update(void){
    GameState_update();
    GameWindow_update();
    UI_update();
}

void App_draw(void){
    GameState_draw();
    UI_draw();
}

void App_run(void) {

    App_init();

    while (Config_isRunning) {
        App_update();
        App_draw();
    }

    App_unload();
}

void App_unload(void) {
    GameState_unload();
    UI_unload();
    GameWindow_unload();
    CloseWindow();  // Close the window and OpenGL context
}