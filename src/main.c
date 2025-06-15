
#include "input.h"
#include "renderer.h"
#include "window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL Init Error: %s\n", SDL_GetError());
        return 1;
    }

    Window window;
    Renderer renderer;
    Input input;

    if (!window_init(&window)) {
        SDL_Quit();
        return 1;
    }

    if (!renderer_init(&renderer, &window)) {
        window_cleanup(&window);
        SDL_Quit();
        return 1;
    }

    input_init(&input);

    u32 last_time = SDL_GetTicks();
    while (!input.quit) {
        u32 current_time = SDL_GetTicks();
        float delta_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        // INPUT
        input_update(&input);

        // LOGIC (pass delta time ig)

        // RENDER
        renderer_set_color(&renderer, 12, 12, 12, 255);
        renderer_clear(&renderer);

        // UI

        renderer_present(&renderer);
        SDL_Delay(16);
    }

    renderer_cleanup(&renderer);
    window_cleanup(&window);
    SDL_Quit();

    return 0;
}
