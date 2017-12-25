#ifndef SPRITE_H
#define SPRITE_H

#include <stdbool.h>
#include "graphics.h"

typedef struct {
    int frame;
    img_t *img_1;
    img_t *img_2;
    int type_x;
    int type_y;
    int rotation;
    flip_t flip;
    int r;
    int g;
    int b;
    int a;
} spr_t;

spr_t * sprite_create(img_t *img_1, img_t *img_2, int type_x, int type_y, int rotation, flip_t flip, int r, int g, int b, int a);
// Creates an sprite, unique for each entity.
//      img_1 is the file containing the first animation of this sprite.
//      img_2 is the file containing the second animation of this sprite.
//      type_x and type_y are the coords, in tile-sizes, of the sprite in the image file.
//      rotation is a number, in degrees, to rotate the image.
//      flip is one of { NO_FLIP, FLIP_HORIZONTAL, FLIP_VERTICAL, FLIP_DIAGONAL }.
//      r is the red value used to mod the original image.
//      g is the green value used to mod the original image.
//      b the blue value used to mod the original image.
//      a the alpha value used to mod the original image.

void sprite_destroy(spr_t * spr); // Free the memory of the sprite.

void sprite_render(spr_t *spr, int x, int y, int z);
// Renders an sprite. Must be done every frame and for every entity.
//     spr is the previously loaded sprite.
//     x, y and z are the coords in pixels where to draw the top left corner.

void sprite_change_type(spr_t *spr, int type_x, int type_y);
// Changes the type of sprite..
//     spr is the previously loaded sprite.
//      type_x and type_y are the coords, in tile-sizes, of the sprite in the image file.

void sprite_change_color(spr_t *spr, int r, int g, int b, int a);
// Change the color of the sprite.
//      r, g, and b are the red, green and blue values.
//      a is the alpha.

void sprite_flip(spr_t *spr, flip_t flip);
// Flips the sprite.
//      flip is one of { NO_FLIP, FLIP_HORIZONTAL, FLIP_VERTICAL, FLIP_DIAGONAL }.

void sprite_rotate(spr_t *spr, int rotation);
// Rotates a sprite.
//      rotation is a number, in degrees, to rotate the image.

#endif
