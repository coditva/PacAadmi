#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "datatypes.h"
#include "display.h"
#include "input.h"
#include "key_mappings.h"
#include "map.h"

void init();
void destroy();
void game_loop();

/* Stores the position of the cursor in the game */
pos_t pos;

int main(int argc, char *argv[])
{
    init();
    game_loop();
    destroy();

    return 0;
}

/**
 * Takes 'key' and updates 'pos'
 */
void take_action(int key)
{
    if (key == MOVE_DOWN) {
        pos.y++;
        if (pos.y > game_window_size.y) pos.y = 0;

    } else if (key == MOVE_UP) {
        pos.y--;
        if (pos.y < 0) pos.y = game_window_size.y;

    } else if (key == MOVE_LEFT) {
        pos.x--;
        if (pos.x < 0) pos.x = game_window_size.x;

    } else if (key == MOVE_RIGHT) {
        pos.x++;
        if (pos.x > game_window_size.y) pos.x = 0;
    }
}

/**
 * Loops till the game is running
 */
void game_loop()
{
    int key = 0;
    while (key != QUIT) {
        /* refresh display */
        display_draw();

        /* get input and update position */
        key = input_get_key();
        take_action(key);

        /* send updated pos to display */
        display_move(pos);
    }
}

/**
 * Initialize all the modules and game data
 */
void init()
{
    display_init();
    key_mappings_init();

    /* initialize position of the cursor */
    pos.x = 0;
    pos.y = 0;
}

/**
 * Destroy all the modules and game data
 */
void destroy()
{
    display_destroy();
}
