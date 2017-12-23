#include <SDL2/SDL.h>
#include "input.h"

static keys_t key_list [MAX_KEYS];

bool if_input(keys_t key) {
    return key_list[key];
}

void set_input(keys_t key) {
    key_list[key] = true;
}

void clear_input(keys_t key) {
    key_list[key] = false;
}

void input_get() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            key_list[QUIT] = true;
            break;
        } else if (event.type == SDL_KEYDOWN) {
            SDL_Keycode key = event.key.keysym.sym;
            switch (key) {
                case SDLK_ESCAPE: {
                    key_list[ESC] = true;
                    break;
                }
                case SDLK_UP: {
                    key_list[ARROW_UP] = true;
                    break;
                }
                case SDLK_DOWN: {
                    key_list[ARROW_DOWN] = true;
                    break;
                }
                case SDLK_LEFT: {
                    key_list[ARROW_LEFT] = true;
                    break;
                }
                case SDLK_RIGHT: {
                    key_list[ARROW_RIGHT] = true;
                    break;
                }
            }
        } else if (event.type == SDL_KEYUP) {
            SDL_Keycode key = event.key.keysym.sym;
            switch (key) {
                case SDLK_UP: {
                    key_list[ARROW_UP] = false;
                    break;
                }
                case SDLK_DOWN: {
                    key_list[ARROW_DOWN] = false;
                    break;
                }
                case SDLK_LEFT: {
                    key_list[ARROW_LEFT] = false;
                    break;
                }
                case SDLK_RIGHT: {
                    key_list[ARROW_RIGHT] = false;
                    break;
                }
            }
        }
    }
}
