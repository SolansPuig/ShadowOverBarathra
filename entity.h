#ifndef ENTITY_H
#define ENTITY_H

typedef enum {
    COMPONENT_NONE = 0,
    COMPONENT_POSITION = 1 << 0,
    COMPONENT_SPEED = 1 << 1,
    COMPONENT_VIEW = 1 << 2
} component_t;

typedef struct {
    float x;
    float y;
    float z;
} component_position_t;

typedef struct {
    float x;
    float y;
} component_speed_t;

typedef struct {
    spr_t *spr;
} component_view_t;

#endif
