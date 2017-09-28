#ifndef DISPLAY_H
#define DISPLAY_H

#include <datatypes.h>

struct game_window_size_t {
    int x;
    int y;
} game_window_size;

/* Initialize the display */
void display_init();

/* Destroy the display */
void display_destroy();

void display_draw();
void display_move(pos_t pos);

#endif /* end of include guard: DISPLAY_H */
