#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "raylib_wrapper.h"
        
typedef struct{
    int padding;

} GameState_Context;

void GameState_Context_init(GameState_Context* game_state);
void GameState_Context_update(GameState_Context* game_state);         
void GameState_Context_draw(GameState_Context* game_state);                
void GameState_Context_unload(GameState_Context* game_state);

#endif