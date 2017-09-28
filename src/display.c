#include <ncurses.h>
#include <stdlib.h>

#include "display.h"
#include "graphics.h"

WINDOW *main_window = NULL;
WINDOW *top_bar = NULL;
WINDOW *bot_bar = NULL;
WINDOW *game_window = NULL;

pos_t display_pos;

void top_bar_init();
void bot_bar_init();

void display_init()
{
    main_window = initscr();
    top_bar = subwin(main_window, 1, COLS, 0, 0);
    bot_bar = subwin(main_window, 1, COLS, LINES - 1, 0);
    game_window = subwin(main_window, LINES - 2, COLS, 1, 0);

    game_window_size.x = COLS - 1;
    game_window_size.y = LINES - 3;

    display_pos.x = 0;
    display_pos.y = 0;

    top_bar_init();
    bot_bar_init();

    noecho();
    curs_set(0);
}

void display_destroy()
{
    endwin();
    main_window = NULL;
}

void display_move(pos_t pos)
{
    wattrset(game_window, A_NORMAL);
    mvwprintw(game_window, display_pos.y, display_pos.x, "%c", ' ');
    wattrset(game_window, A_STANDOUT);
    mvwprintw(game_window, pos.y, pos.x, "%c", cursor.right);
    display_pos.x = pos.x;
    display_pos.y = pos.y;

    wmove(top_bar, 0, 0);
    wprintw(top_bar, "%s", "1234adfasdfadfadsf");
}

void display_draw()
{
    wrefresh(game_window);
    wrefresh(top_bar);
    wrefresh(bot_bar);
}

void top_bar_init()
{
    wattrset(top_bar, A_STANDOUT);
    for (int i = 0; i < COLS; ++i) {
        mvwprintw(top_bar, 0, i, " ");
    }
    wrefresh(top_bar);
}

void bot_bar_init()
{
    wattrset(bot_bar, A_STANDOUT);
    for (int i = 0; i < COLS; ++i) {
        mvwprintw(bot_bar, 0, i, " ");
    }
    wrefresh(bot_bar);
}
