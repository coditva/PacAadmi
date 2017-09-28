#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "display.h"
#include "input.h"

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
    if (key == 'j') {
        pos.y++;
    } else if (key == 'k') {
        pos.y--;
    } else if (key == 'h') {
        pos.x--;
    } else if (key == 'l') {
        pos.x++;
    }
}

void game_loop()
{
    display_draw();
    int key;
    while (key != 'q') {
        display_draw();
        key = input_get_key();
        take_action(key);
        display_move(pos);
    }
}

void init()
{
    display_init();
    pos.x = 0;
    pos.y = 0;
}

void destroy()
{
    display_destroy();
}
