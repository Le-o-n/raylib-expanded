#include "my_game.h"


void MyGame_run(){

    SoundManager_Context sound_manager;
    GameState_Context game_state;
    GameWindow_Context game_window;
    UI_context ui;

    SoundManager_Context_init(
        &sound_manager
    );

    GameState_Context_init(
        &game_state
    );

    GameWindow_Context_init(
        &game_window,
        Config_SCREEN_WIDTH,
        Config_SCREEN_HEIGHT,
        Config_WINDOW_TITLE
    );

    UI_Context_init(
        &ui
    );

    App_run(
        &game_window,
        &game_state,
        &sound_manager,
        &ui
    );

    UI_Context_unload(&ui);
    GameWindow_Context_unload(&game_window);
    GameState_Context_unload(&game_state);
    SoundManager_Context_unload(&sound_manager);
}