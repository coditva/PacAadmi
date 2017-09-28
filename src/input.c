#include <ncurses.h>
#include "input.h"

void input_init()
{
}

void input_destroy()
{
}

int input_get_key()
{
    int key = getch();
    if (key == KEY_DOWN) {
        return 'j';
    } else if (key == KEY_UP) {
        return 'k';
    } else if (key == KEY_LEFT) {
        return 'h';
    } else if (key == KEY_RIGHT) {
        return 'l';
    } else {
        return key;
    }
}
