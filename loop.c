#include <stdbool.h>
#include "globals.h"
#include "graphics.h"
#include "input.h"

#define MS_PER_FRAME 16

static bool done;
static img_t * players0;

bool DEBUG;

void get_input() {
    input_get();

    if (if_input(F3))   DEBUG = true;
    else                DEBUG = false;
    if (if_input(ESC) || if_input(QUIT))    done = true;
}

void update() {}

void render() {
    graphics_render_texture(players0, 0, 0, 10, 30, 38, 0, 0, 1);
    graphics_show_and_clear();
}

int main (void) {
    DEBUG = false;
    graphics_open_window("Shadow Over Barathra", 1780, 920);
    players0 = graphics_load_image("./assets/Player0.png", 16, 16);

    double lag = 0.0;
    done = false;
    double previous = SDL_GetTicks();
    while (!done) {
        double current = SDL_GetTicks();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        get_input();

        while (lag >= MS_PER_UPDATE) {
            update();
            lag -= MS_PER_UPDATE;
        }

        render();
    }

    graphics_close_texture(players0);
    graphics_close_window(screen);
    return 0;
}
