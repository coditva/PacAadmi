#ifndef DISPLAY_H
#define DISPLAY_H

#include <datatypes.h>

/* Struct for window size */
struct game_window_size_t {
    int x;
    int y;
} game_window_size;

/* Initialize the display */
void display_init();

/* Destroy the display */
void display_destroy();

/* Refresh all the windows */
void display_draw();

/* Move the position in the display */
void display_move(pos_t pos);

#endif /* end of include guard: DISPLAY_H */
