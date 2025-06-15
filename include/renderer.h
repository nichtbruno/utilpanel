#pragma once

#include <SDL2/SDL.h>
#include "defs.h"
#include "window.h"

typedef struct {
    SDL_Renderer *renderer;
    Window *window;
} Renderer;

u8 renderer_init(Renderer *r, Window *win);
void renderer_cleanup(Renderer *r);
void renderer_set_color(Renderer *ren, u8 r, u8 g, u8 b, u8 a);
void renderer_present(Renderer *r);
void renderer_clear(Renderer *r);
