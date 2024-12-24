#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "config.h"
#include "raylib_wrapper.h"
#include "sound_manager.h"
#include "raylib.h"


typedef struct {
    SoundManager_Context* sound_manager_context;
    int last_width;
    int last_height;

} GameWindow_Context;

void GameWindow_Context_init(
    GameWindow_Context* context, 
    SoundManager_Context* sound_manager_context,
    int width,
    int height,
    const char* title
);

void GameWindow_Context_update(GameWindow_Context* context);
void GameWindow_Context_unload(GameWindow_Context* context);


#endif