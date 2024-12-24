#ifndef GAME_STATE_H
#define GAME_STATE

#include "raylib_wrapper.h"
        
typedef struct{
    int padding;

} GameState_Context;

void GameState_Context_init(GameState_Context* context);
void GameState_Context_update(GameState_Context* context);         
void GameState_Context_draw(GameState_Context* context);                
void GameState_Context_unload(GameState_Context* context);

#endif