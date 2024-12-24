#include "app.h"

int Config_isRunning = 1;

GameWindow_Context game_window_context; // not a fan of this global scope, move to main?
GameState_Context game_state_context;
SoundManager_Context sound_manager_context; 
UI_context ui_context;

void App_run() {

    App_Context app_context;

    App_Context_init(&app_context);

    while (Config_isRunning) {
        App_Context_update(&app_context);
        App_Context_draw(&app_context);
    }

    App_Context_unload(&app_context);
}

void App_Context_init(App_Context* context) {

    if (context == 0){
        return;
    }

    SoundManager_Context_init(
        &sound_manager_context
    );

    GameState_Context_init(
        &game_state_context
    );

    GameWindow_Context_init(
        &game_window_context,
        Config_SCREEN_WIDTH,
        Config_SCREEN_HEIGHT,
        Config_WINDOW_TITLE
    );
    UI_Context_init(
        &ui_context
    );

    context->game_window_context = &game_window_context;
    context->game_state_context = &game_state_context;
    context->sound_manager_context = &sound_manager_context;
    context->ui_context = &ui_context;

}

void App_Context_update(App_Context* context){
    if (context == 0){
        return;
    }
    
    GameState_Context_update(context->game_state_context);
    GameWindow_Context_update(context->game_window_context);
    UI_Context_update(context->ui_context);
}

void App_Context_draw(App_Context* context){
    if (context == 0){
        return;
    }
    
    GameState_Context_draw(context->game_state_context);
    UI_Context_draw(context->ui_context);
}



void App_Context_unload(App_Context* context) {
    if (context == 0){
        return;
    }
    
    GameState_Context_unload(context->game_state_context);
    UI_Context_unload(context->ui_context);
    GameWindow_Context_unload(context->game_window_context);
    SoundManager_Context_unload(context->sound_manager_context);
    
    Raylib_Window_close();  // Close the window and OpenGL context
}