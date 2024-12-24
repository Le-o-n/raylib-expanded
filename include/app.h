#ifndef APP_H
#define APP_H

#include "game_state.h"
#include "game_window.h"
#include "ui.h"
#include "config.h"
#include "raylib.h"
 
void App_init(void);
void App_update(void);
void App_run(void);
void App_unload(void);
void App_draw(void);

#endif 