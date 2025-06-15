#include "renderer.h"
#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>

u8 renderer_init(Renderer *r, Window *win) {
    r->window = win;
    r->renderer = SDL_CreateRenderer(
        win->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (r->renderer == NULL) {
        printf("Renderer creation error: %s\n", SDL_GetError());
        return 0;
    }

    SDL_SetRenderDrawBlendMode(r->renderer, SDL_BLENDMODE_BLEND);
    return 1;
}

void renderer_cleanup(Renderer *r) {
    if (r->renderer) {
        SDL_DestroyRenderer(r->renderer);
        r->renderer = NULL;
    }
}

void renderer_clear(Renderer *r) {
    SDL_RenderClear(r->renderer);
}

void renderer_set_color(Renderer *ren, u8 r, u8 g, u8 b, u8 a) {
    SDL_SetRenderDrawColor(ren->renderer, r, g, b, a);
}

void renderer_present(Renderer *r) {
    SDL_RenderPresent(r->renderer);
}
