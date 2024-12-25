#include "my_game.h"


void MyGame_run(){

    SoundManager_Context sound_manager_context;
    GameState_Context game_state_context;
    GameWindow_Context game_window_context;
    UI_context ui_context;

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

    App_run(
        &game_window_context,
        &game_state_context,
        &sound_manager_context,
        &ui_context
    );

    UI_Context_unload(&ui_context);
    GameWindow_Context_unload(&game_window_context);
    GameState_Context_unload(&game_state_context);
    SoundManager_Context_unload(&sound_manager_context);
}