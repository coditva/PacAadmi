#ifndef MAP_H
#define MAP_H

#include "datatypes.h"

/* Store the map data */
map_t map;

/* Initialize the map */
void map_init();

/* Destroy the map */
void map_destroy();

/* Load a new map */
void map_load(char *path);

/* Load position in pos */
void map_get_position(character_t character, pos_t *pos);

/* Move the character to the new positions */
void map_move(character_t character, pos_t pos);

pos_t map_window_size;

#endif /* end of include guard: MAP_H */
