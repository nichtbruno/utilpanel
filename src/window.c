#include "window.h"
#include "defs.h"
#include <SDL2/SDL_video.h>

u8 window_init(Window *win) {
    win->window = SDL_CreateWindow(
        "Utilpanel",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if (win->window == NULL) {
        printf("Window creation error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void window_cleanup(Window *win) {
    if (win->window) {
        SDL_DestroyWindow(win->window);
        win->window = NULL;
    }
}
