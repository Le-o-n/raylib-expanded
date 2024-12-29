#ifndef RAYLIB_WRAPPER_H
#define RAYLIB_WRAPPER_H

#include "raylib.h"


#define Raylib_Colour_RAYWHITE RAYWHITE
#define Raylib_Colour_BLUE BLUE
#define Raylib_Colour_GREEN GREEN

#define Raylib_Vector2 Vector2
#define Raylib_Vector3 Vector3
#define Raylib_Vector4 Vector4

#define Raylib_Colour Color

#define Raylib_Draw_Pixel DrawPixel                                                  // Draw a pixel using geometry [Can be slow, use with care]
#define Raylib_Draw_PixelVec DrawPixelV                                                    // Draw a pixel using geometry (Vector version) [Can be slow, use with care]
#define Raylib_Draw_Line DrawLine
#define Raylib_Draw_LineVec DrawLineV                                     // Draw a line (using gl lines)
#define Raylib_Draw_LineExt DrawLineEx                       // Draw a line (using triangles/quads)
#define Raylib_Draw_LineStrip DrawLineStrip                            // Draw lines sequence (using gl lines)
#define Raylib_Draw_LineBezier DrawLineBezier                   // Draw line segment cubic-bezier in-out interpolation
#define Raylib_Draw_Circle DrawCircle                              // Draw a color-filled circle
#define Raylib_Draw_CircleSector DrawCircleSector      // Draw a piece of a circle
#define Raylib_Draw_CircleSectorLines DrawCircleSectorLines // Draw circle sector outline
#define Raylib_Draw_CircleGradient DrawCircleGradient         // Draw a gradient-filled circle
#define Raylib_Draw_CircleVec DrawCircleV                       // Draw a color-filled circle (Vector version)
#define Raylib_Draw_CircleLines DrawCircleLines                         // Draw circle outline
#define Raylib_Draw_CircleLinesVec DrawCircleLinesV                                  // Draw circle outline (Vector version)
#define Raylib_Draw_Ellipse DrawEllipse             // Draw ellipse
#define Raylib_Draw_EllipseLines DrawEllipseLines        // Draw ellipse outline
#define Raylib_Draw_Ring DrawRing // Draw ring
#define Raylib_Draw_RingLines DrawRingLines    // Draw ring outline
#define Raylib_Draw_Rectangle DrawRectangle                        // Draw a color-filled rectangle
#define Raylib_Draw_RectangleVec DrawRectangleV
#define Raylib_Draw_RectangleRec DrawRectangleRec
#define Raylib_Draw_RectanglePro DrawRectanglePro
#define Raylib_Draw_RectangleGradientVertical DrawRectangleGradientV
#define Raylib_Draw_RectangleGradientHorizontal DrawRectangleGradientH
#define Raylib_Draw_RectangleGradientExt DrawRectangleGradientEx
#define Raylib_Draw_RectangleLines DrawRectangleLines
#define Raylib_Draw_RectangleLinesExt DrawRectangleLinesEx
#define Raylib_Draw_RectangleRounded DrawRectangleRounded
#define Raylib_Draw_RectangleRoundedLines DrawRectangleRoundedLines
#define Raylib_Draw_RectangleRoundedLinesExt DrawRectangleRoundedLinesEx
#define Raylib_Draw_Triangle DrawTriangle
#define Raylib_Draw_TriangleLines DrawTriangleLines
#define Raylib_Draw_TriangleFan DrawTriangleFan
#define Raylib_Draw_TriangleStrip DrawTriangleStrip
#define Raylib_Draw_Poly DrawPoly
#define Raylib_Draw_PolyLines DrawPolyLines
#define Raylib_Draw_PolyLinesExt DrawPolyLinesEx
#define Raylib_Draw_SplineLinear DrawSplineLinear
#define Raylib_Draw_SplineBasis DrawSplineBasis
#define Raylib_Draw_SplineCatmullRom DrawSplineCatmullRom
#define Raylib_Draw_SplineBezierQuadratic DrawSplineBezierQuadratic
#define Raylib_Draw_SplineBezierCubic DrawSplineBezierCubic
#define Raylib_Draw_SplineSegmentLinear DrawSplineSegmentLinear
#define Raylib_Draw_SplineSegmentBasis DrawSplineSegmentBasis
#define Raylib_Draw_SplineSegmentCarmullRom DrawSplineSegmentCatmullRom
#define Raylib_Draw_SplineSegmentBezierQuadratic DrawSplineSegmentBezierQuadratic
#define Raylib_Draw_SplineSegmentBezierCubic DrawSplineSegmentBezierCubic


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

#define Raylib_Collision_Check CheckCollisionRecs
#define Raylib_Collision_CheckCircles CheckCollisionCircles
#define Raylib_Collision_CheckCircleRec CheckCollisionCircleRec
#define Raylib_Collision_CheckCircleLine CheckCollisionCircleLine
#define Raylib_Collision_CheckPointRec CheckCollisionPointRec
#define Raylib_Collision_CheckPointCircle CheckCollisionPointCircle
#define Raylib_Collision_CheckPointTriangle CheckCollisionPointTriangle
#define Raylib_Collision_CheckPointLine CheckCollisionPointLine
#define Raylib_Collision_CheckPointPoly CheckCollisionPointPoly
#define Raylib_Collision_CheckLines CheckCollisionLines
#define Raylib_Collision_GetRec GetCollisionRec

#endif // RAYLIB_WRAPPER_H
