#include "graphics.h"

int main(void) {
    graphics_open_window("Shadow Over Barathra", 1780, 920);
    img_t *players0 = graphics_load_image("./assets/Player0.png", 16, 16);

    graphics_render_texture(players0, 0, 0, 10, 30, 38, 0, 0, 1);

    graphics_show_and_clear();

    while(1);

    return 0;
}
