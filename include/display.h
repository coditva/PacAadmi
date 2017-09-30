#ifndef DISPLAY_H
#define DISPLAY_H

#include <datatypes.h>

/* Initialize the display */
void display_init();

/* Destroy the display */
void display_destroy();

/* Refresh all the windows */
void display_refresh();

/* Refresh the game window */
void display_draw_game();

/* Load the map stored in map.data in the game window */
void display_load_map();

#endif /* end of include guard: DISPLAY_H */
