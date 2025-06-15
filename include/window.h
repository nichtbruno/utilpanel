#pragma once

#include "defs.h"
#include <SDL2/SDL.h>

typedef struct {
    SDL_Window *window;
} Window;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

u8 window_init(Window *win);
void window_cleanup(Window *win);
