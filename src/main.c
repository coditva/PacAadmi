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
    game_loop();
    destroy();

    return 0;
}

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

void game_loop()
{
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
