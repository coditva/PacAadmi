#include "key_mappings.h"

/*
 * Initialize key mappings
 */
void key_mappings_init()
{
    key_map[MOVE_UP] = 'k';
    key_map[MOVE_DOWN] = 'j';
    key_map[MOVE_LEFT] = 'h';
    key_map[MOVE_RIGHT] = 'l';
    key_map[PAUSE] = ' ';
    key_map[QUIT] = 'q';
}

/*
 * Destroy all key mappings
 */
void key_mappings_destroy()
{
}
