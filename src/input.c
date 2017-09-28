#include <ncurses.h>

#include "input.h"
#include "key_mappings.h"

/*
 * Initialize input
 */
void input_init()
{ }

/*
 * Destroy input
 */
void input_destroy()
{ }

/*
 * Return a keypress after waiting for a prompt
 */
int input_get_key()
{
    int input = getch();

    /* Search the key pressed in mapped keys */
    for (int i = 1; i < KEY_MAP_SIZE; ++i) {
        if (input == key_map[i]) return i;
    }

    /* return nop if an unmapped key pressed */
    return KEY_NOP;
}
