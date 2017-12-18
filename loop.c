#include <stdbool.h>
#include "graphics.h"

#define MS_PER_FRAME 16

static bool done;

void get_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0 && !done) {
        if (event.type == SDL_QUIT) {
            done = true;
        } else if (event.type == SDL_KEYDOWN) {
            SDL_Keycode key = event.key.keysym.sym;
            switch (key) {
                case SDLK_ESCAPE: {
                    done = true;
                    break;
                }
                case SDLK_UP: {
                    // Up
                    break;
                }
                case SDLK_DOWN: {
                    // Down
                    break;
                }
                case SDLK_LEFT: {
                    // Left
                    break;
                }
                case SDLK_RIGHT: {
                    // Right
                    break;
                }
            }
        } else if (event.type == SDL_KEYUP) {
            SDL_Keycode key = event.key.keysym.sym;
            switch (key) {
                case SDLK_UP: {
                    // Up
                    break;
                }
                case SDLK_DOWN: {
                    // Down
                    break;
                }
                case SDLK_LEFT: {
                    // Left
                    break;
                }
                case SDLK_RIGHT: {
                    // Right
                    break;
                }
            }
        }
    }
}
