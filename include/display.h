#ifndef DISPLAY_H
#define DISPLAY_H

#include <datatypes.h>

/* Keep track of game window size */
game_window_size_t game_window_size;

/* Initialize the display */
void display_init();

/* Destroy the display */
void display_destroy();

/* Refresh all the windows */
void display_draw();

/* Refresh the game window */
void display_draw_game();

/* Move the position in the display */
void display_move(pos_t pos);

/* Set the starting positions */
void display_move(pos_t pos);

/* Load the map stored in map.data in the game window */
void display_load_map();
void display_reload_map();

#endif /* end of include guard: DISPLAY_H */
