#ifndef APP_H
#define APP_H

#include "game_state.h"
#include "game_window.h"
#include "ui.h"
#include "config.h"
#include "raylib.h"

typedef struct{
    GameWindow_Context* game_window;
    GameState_Context* game_state;
    SoundManager_Context* sound_manager;
    UI_context* ui;
} App_Context;

void App_run(
    GameWindow_Context* game_window,
    GameState_Context* game_state,
    SoundManager_Context* sound_manager,
    UI_context* ui
);
void App_Context_init(
    App_Context* app,
    GameWindow_Context* game_window,
    GameState_Context* game_state,
    SoundManager_Context* sound_manager,
    UI_context* ui
);
void App_Context_update(App_Context* app);
void App_Context_unload(App_Context* app);
void App_Context_draw(App_Context* app);

#endif 