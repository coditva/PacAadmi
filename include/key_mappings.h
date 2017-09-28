#ifndef KEY_MAPPINGS_H
#define KEY_MAPPINGS_H

#include "datatypes.h"

/* An array for all the key mappings */
int key_map[KEY_MAP_SIZE];

/* Initialize key mappings */
void key_mappings_init();

/* Destroy key mappings */
void key_mappings_destroy();

#endif /* end of include guard: KEY_MAPPINGS_H */
