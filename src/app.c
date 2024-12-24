#include "app.h"

int Config_isRunning = 1;

GameWindow_Context game_window_context;
SoundManager_Context sound_manager_context; 

void App_Context_init(App_Context* context) {

    SoundManager_Context_init(
        &sound_manager_context
    );

    GameWindow_Context_init(
        &game_window_context,
        Config_SCREEN_WIDTH,
        Config_SCREEN_HEIGHT,
        Config_WINDOW_TITLE
    );
    UI_init();
    GameState_init();

    context->game_window_context = &game_window_context;
    context->sound_manager_context = &sound_manager_context;
    
}

void App_Context_update(App_Context* context){
    GameState_update();
    GameWindow_Context_update(&game_window_context);
    UI_update();
}

void App_Context_draw(App_Context* context){
    GameState_draw();
    UI_draw();
}

void App_run() {

    App_Context app_context;

    App_Context_init(&app_context);

    while (Config_isRunning) {
        App_Context_update(&app_context);
        App_Context_draw(&app_context);
    }

    App_Context_unload(&app_context);
}

void App_Context_unload(App_Context* context) {
    GameState_unload();
    UI_unload();
    GameWindow_Context_unload(context->game_window_context);
    SoundManager_Context_unload(context->sound_manager_context);
    CloseWindow();  // Close the window and OpenGL context
}