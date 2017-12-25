#include <stdbool.h>
#include "globals.h"
#include "graphics.h"
#include "input.h"
#include "sprite.h"

#define MS_PER_FRAME 16

static bool done;
static spr_t * player;

bool DEBUG;

void get_input() {
    input_get();

    if (if_input(F3))   DEBUG = true;
    else                DEBUG = false;
    if (if_input(ESC) || if_input(QUIT))    done = true;
}

void update() {}

void render() {
    sprite_render(player, 10, 10, 1);
    graphics_show_and_clear();
}

int main (void) {
    DEBUG = false;
    graphics_open_window("Shadow Over Barathra", 1780, 920);
    img_t * players0 = graphics_load_image("./assets/Player0.png", 16, 16);
    img_t * players1 = graphics_load_image("./assets/Player1.png", 16, 16);
    player = sprite_create(players0, players1, 0, 0, 0, 0, 0, 0, 0, 0);

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
