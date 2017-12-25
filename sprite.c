#include "graphics.h"
#include "sprite.h"

spr_t * sprite_create(img_t *img_1, img_t *img_2, int type_x, int type_y, int rotation, flip_t flip, int r, int g, int b, int a) {
    spr_t *spr = malloc(sizeof(spr_t));
    spr->frame = 0;
    spr->img_1 = img_1;
    spr->img_2 = img_2;
    spr->type_x = type_x;
    spr->type_y = type_y;
    spr->rotation = rotation;
    spr->flip = flip;
    spr->r = r;
    spr->g = g;
    spr->b = b;
    spr->a = a;

    return spr;
}

void sprite_destroy(spr_t * spr) {
    free(spr);
}

void sprite_render(spr_t *spr, int x, int y, int z) {
    graphics_render_texture_modded(
            (spr->frame == 0 ? spr->img_1 : spr->img_2),
            spr->type_x,
            spr->type_y,
            x,
            y,
            y,
            z,
            spr->rotation,
            spr->flip,
            spr->r,
            spr->g,
            spr->b,
            spr->a
        );
}

void sprite_change_type(spr_t *spr, int type_x, int type_y) {
    spr->type_x = type_x;
    spr->type_y = type_y;
}

void sprite_change_color(spr_t *spr, int r, int g, int b, int a) {
    spr->r = r;
    spr->g = g;
    spr->b = b;
    spr->a = a;
}

void sprite_flip(spr_t *spr, flip_t flip) {
    spr->flip = flip;
}

void sprite_rotate(spr_t *spr, int rotation) {
    spr->rotation;
}
