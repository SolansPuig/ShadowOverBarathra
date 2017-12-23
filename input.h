#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

typedef enum {
    A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    N0, N1, N2, N3, N4, N5, N6, N7, N8, N9,
    F0, F1, F2, F3, F4, F5, F6, F7, F8, F9,
    ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT,
    SPACE, CTRL, SHIFT, INRO, ESC, QUIT,
    MAX_KEYS
} keys_t;

bool if_input(keys_t key);
// Check whether an input key is set,
//      key is the key to check.

void set_input(keys_t key);
// Sets an input key.
//      key is the input key to set.

void clear_input(keys_t key);
// Clear an input key.
//      key is the input key to clear.

void input_get();
// Check all the inputs and sets or clears them from the input list.

#endif
