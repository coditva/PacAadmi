#include <ncurses.h>

#include "input.h"
#include "key_mappings.h"

void input_init()
{
}

void input_destroy()
{
}

int input_get_key()
{
    int input;

    input = getch();
    for (int i = 1; i < KEY_MAP_SIZE; ++i) {
        if (input == key_map[i]) {
            return i;
        }
    }

    // return nop;
    return KEY_NOP;
}
