#include "app.h"

int Config_isRunning = 1;

GameWindow_Context game_window; // not a fan of this global scope, move to main?
GameState_Context game_state;
SoundManager_Context sound_manager; 
UI_context ui;

void App_run(
    GameWindow_Context* game_window,
    GameState_Context* game_state,
    SoundManager_Context* sound_manager,
    UI_context* ui
){

    App_Context app;
    App_Context_init(
        &app,
        game_window,
        game_state,
        sound_manager,
        ui
    );

    while (Config_isRunning) {
        App_Context_update(&app);
        App_Context_draw(&app);
    }

    App_Context_unload(&app);
}

void App_Context_init(
    App_Context* app,
    GameWindow_Context* game_window,
    GameState_Context* game_state,
    SoundManager_Context* sound_manager,
    UI_context* ui
) {

    if (app == 0){
        return;
    }

    app->game_window = game_window;
    app->game_state = game_state;
    app->sound_manager = sound_manager;
    app->ui = ui;

}

void App_Context_update(App_Context* app){
    if (app == 0){
        return;
    }
    
    GameState_Context_update(app->game_state);
    GameWindow_Context_update(app->game_window);
    UI_Context_update(app->ui);
}

void App_Context_draw(App_Context* app){
    if (app == 0){
        return;
    }
    
    GameState_Context_draw(app->game_state);
    UI_Context_draw(app->ui);
}



void App_Context_unload(App_Context* app) {
    if (app == 0){
        return;
    }
    
    Raylib_Window_close();  // Close the window and OpenGL app
}