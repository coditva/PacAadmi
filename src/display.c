#include <ncurses.h>
#include <stdlib.h>
#include "display.h"

WINDOW *main_window = NULL;
pos_t display_pos;
int cursor = '>';

void display_init()
{
    main_window = initscr();
    display_pos.x = 0;
    display_pos.y = 0;
    noecho();
    curs_set(0);
}

void display_destroy()
{
    endwin();
    main_window = NULL;
}

void display_refresh()
{
    wrefresh(main_window);
}

void display_move(pos_t pos)
{
    mvwprintw(main_window, display_pos.y, display_pos.x, "%c", ' ');
    mvwprintw(main_window, pos.y, pos.x, "%c", cursor);
    display_pos.x = pos.x;
    display_pos.y = pos.y;
}

void display_draw()
{
    wrefresh(main_window);
}
