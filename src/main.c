#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "display.h"
#include "input.h"
#include "key_mappings.h"

void init();
void destroy();
void game_loop();

pos_t pos;

int main(int argc, char *argv[])
{
    init();
    display_refresh();
    game_loop();
    destroy();

    return 0;
}

void take_action(int key)
{
    if (key == MOVE_DOWN) {
        pos.y++;
    } else if (key == MOVE_UP) {
        pos.y--;
    } else if (key == MOVE_LEFT) {
        pos.x--;
    } else if (key == MOVE_RIGHT) {
        pos.x++;
    }
}

void game_loop()
{
    display_draw();
    int key;
    while (key != QUIT) {
        display_draw();
        key = input_get_key();
        take_action(key);
        display_move(pos);
    }
}

void init()
{
    display_init();
    key_mappings_init();
    pos.x = 0;
    pos.y = 0;
}

void destroy()
{
    display_destroy();
}
