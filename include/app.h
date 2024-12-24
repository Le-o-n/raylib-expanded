#ifndef APP_H
#define APP_H

#include "game_state.h"
#include "game_window.h"
#include "ui.h"
#include "config.h"
#include "raylib.h"

typedef struct{
    GameWindow_Context* game_window_context;
    GameState_Context* game_state_context;
    SoundManager_Context* sound_manager_context;
    UI_context* ui_context;
} App_Context;

void App_run();
void App_Context_init(App_Context* context);
void App_Context_update(App_Context* context);
void App_Context_unload(App_Context* context);
void App_Context_draw(App_Context* context);

#endif 