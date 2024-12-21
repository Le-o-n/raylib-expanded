#include "app.h"
#include "game_state.h"
#include "game_window.h"
#include "ui.h"
#include "config.h"

int isRunning = 1;

void InitApplication(void) {
    InitGameWindow();
    InitUI();
    InitGameState();
    
}

void UpdateApplication(void){
    UpdateGameState();
    UpdateGameWindow();
    UpdateUI();
}

void DrawApplication(void){
    DrawGameState();
    DrawUI();
}

void RunApplication(void) {

    InitApplication();

    while (isRunning) {
        UpdateApplication();
        DrawApplication();
    }

    UnloadApplication();
}

void UnloadApplication(void) {
    UnloadGameState();
    UnloadUI();
    UnloadGameWindow();
    CloseWindow();  // Close the window and OpenGL context
}