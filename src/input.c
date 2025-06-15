#include "input.h"
#include <SDL2/SDL_events.h>
#include <string.h>

void input_init(Input *input) {
    memset(input->keys, 0, sizeof(input->keys));
    memset(input->mouse_buttons, 0, sizeof(input->mouse_buttons));
    input->mouse_x = 0;
    input->mouse_y = 0;
    input->quit = 0;
}

void input_update(Input *input) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                input->quit = 1;
                break;
            case SDL_KEYDOWN:
                input->keys[event.key.keysym.scancode] = 1;
                break;
            case SDL_KEYUP:
                input->keys[event.key.keysym.scancode] = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button < 5) {
                    input->mouse_buttons[event.button.button] = 1;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button < 5) {
                    input->mouse_buttons[event.button.button] = 0;
                }
                break;
            case SDL_MOUSEMOTION:
                input->mouse_x = event.motion.x;
                input->mouse_y = event.motion.y;
                break;
        }
    }
}

u8 input_key_pressed(Input *input, SDL_Scancode key) {
    return input->keys[key];
}

u8 input_mouse_pressed(Input *input, int button) {
    return input->mouse_buttons[button];
}
