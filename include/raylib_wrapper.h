#ifndef RAYLIB_WRAPPER_H
#define RAYLIB_WRAPPER_H

#include "raylib.h"


#define Raylib_Colour_RAYWHITE RAYWHITE
#define Raylib_Colour_BLUE BLUE
#define Raylib_Colour_GREEN GREEN


// Example namespace: Raylib_Window_initWindow
// Aliases for window management functions
#define Raylib_Window_init InitWindow
#define Raylib_Window_close CloseWindow
#define Raylib_Window_shouldClose WindowShouldClose
#define Raylib_Window_isReady IsWindowReady
#define Raylib_Window_isFullscreen IsWindowFullscreen
#define Raylib_Window_toggleFullscreen ToggleFullscreen
#define Raylib_Window_setTitle SetWindowTitle
#define Raylib_Window_setSize SetWindowSize
#define Raylib_Window_getScreenWidth GetScreenWidth
#define Raylib_Window_getScreenHeight GetScreenHeight

// Example namespace: Raylib_Renderer_beginDrawing
// Aliases for rendering functions
#define Raylib_Draw_beginDrawing BeginDrawing
#define Raylib_Draw_endDrawing EndDrawing
#define Raylib_Draw_clearBackground ClearBackground
#define Raylib_Draw_drawRectangle DrawRectangle

// Example namespace: Raylib_Keyboard_isKeyPressed
// Aliases for keyboard input functions
#define Raylib_Keyboard_isKeyPressed IsKeyPressed
#define Raylib_Keyboard_isKeyDown IsKeyDown
#define Raylib_Keyboard_isKeyReleased IsKeyReleased
#define Raylib_Keyboard_isKeyUp IsKeyUp
#define Raylib_Keyboard_getKeyPressed GetKeyPressed

// Example namespace: Raylib_Mouse_getMousePosition
// Aliases for mouse input functions
#define Raylib_Mouse_getMousePosition GetMousePosition
#define Raylib_Mouse_getMouseX GetMouseX
#define Raylib_Mouse_getMouseY GetMouseY
#define Raylib_Mouse_isMouseButtonDown IsMouseButtonDown
#define Raylib_Mouse_isMouseButtonUp IsMouseButtonUp

// Example namespace: Raylib_Sound_loadSound
// Aliases for audio functions
#define Raylib_Sound_load LoadSound
#define Raylib_Sound_unload UnloadSound
#define Raylib_Sound_play PlaySound
#define Raylib_Sound_stop StopSound
#define Raylib_Sound_setVolume SetSoundVolume

// Example namespace: Raylib_Texture_loadTexture
// Aliases for texture and model functions
#define Raylib_Texture_load LoadTexture
#define Raylib_Texture_unload UnloadTexture
#define Raylib_Texture_draw DrawTexture
#define Raylib_Texture_drawV DrawTextureV

// Add more functions as needed, following the same pattern

#endif // RAYLIB_WRAPPER_H
