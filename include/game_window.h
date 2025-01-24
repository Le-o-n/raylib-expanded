#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "config.h"
#include "raylib_wrapper.h"
#include "sounds/sound_manager.h"
#include "raylib.h"


typedef struct {
    int last_width;
    int last_height;

} GameWindow_Context;

void GameWindow_Context_init(
    GameWindow_Context* game_window, 
    int width,
    int height,
    const char* title
);

void GameWindow_Context_update(GameWindow_Context* game_window);
void GameWindow_Context_unload(GameWindow_Context* game_window);


#endif