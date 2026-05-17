#ifndef ENGINE_H
#define ENGINE_H

int engine_InitWindow();
int engine_WindowShouldClose();
void engine_RenderPass();
void engine_RefreshWindow();
void engine_ProcessInput();
void engine_TerminateWindow();

#endif