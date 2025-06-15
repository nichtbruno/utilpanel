#pragma once

#include "defs.h"
#include <SDL2/SDL_scancode.h>

typedef struct {
    u16 keys[SDL_NUM_SCANCODES];
    u8 mouse_buttons[5];
    int mouse_x, mouse_y;
    u8 quit;
} Input;

void input_init(Input *input);
void input_update(Input *input);
u8 input_key_pressed(Input *input, SDL_Scancode key);
u8 input_mouse_pressed(Input *input, int button);
