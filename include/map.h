#ifndef MAP_H
#define MAP_H

#include "datatypes.h"

/* Initialize the map */
void map_init();

/* Destroy the map */
void map_destroy();

/* Load a new map */
void map_load(char *path);

#endif /* end of include guard: MAP_H */
