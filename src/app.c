#include "app.h"

int Config_isRunning = 1;


GameWindow_Context game_window_context; // move to an App_Context struct
SoundManager_Context sound_manager_context; // move to an App_Context struct

void App_init(void) {

    SoundManager_Context_init(
        &sound_manager_context
    );

    GameWindow_Context_init(
        &game_window_context,
        &sound_manager_context,
        Config_SCREEN_WIDTH,
        Config_SCREEN_HEIGHT,
        Config_WINDOW_TITLE
    );
    UI_init();
    GameState_init();
    
}

void App_update(void){
    GameState_update();
    GameWindow_Context_update(&game_window_context);
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
    GameWindow_Context_unload(&game_window_context);
    SoundManager_Context_unload(&sound_manager_context);
    CloseWindow();  // Close the window and OpenGL context
}