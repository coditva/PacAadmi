#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "datatypes.h"
#include "display.h"
#include "input.h"
#include "key_mappings.h"
#include "map.h"
#include "character.h"

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
        if (pos.y >= map_window_size.y) pos.y = 0;

    } else if (key == MOVE_UP) {
        pos.y--;
        if (pos.y < 0) pos.y = map_window_size.y - 1;

    } else if (key == MOVE_LEFT) {
        pos.x--;
        if (pos.x < 0) pos.x = map_window_size.x - 1;

    } else if (key == MOVE_RIGHT) {
        pos.x++;
        if (pos.x >= map_window_size.x) pos.x = 0;
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
        display_draw_game();

        /* get input and update position */
        key = input_get_key();
        take_action(key);

        /* send updated pos to map */
        character_move(CH_PACMAN, pos);
    }
}

/**
 * Initialize all the modules and game data
 */
void init()
{
    display_init();
    key_mappings_init();
    map_init();
    display_load_map();
    character_init_all();

    /* initialize position of the cursor */
    character_get_position(CH_PACMAN, &pos);
}

/**
 * Destroy all the modules and game data
 */
void destroy()
{
    display_destroy();
}
