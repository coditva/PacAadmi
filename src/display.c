#include <ncurses.h>
#include <stdlib.h>

#include "display.h"
#include "graphics.h"

/* Various windows in the game */
WINDOW *main_window = NULL;
WINDOW *top_bar = NULL;
WINDOW *bot_bar = NULL;
WINDOW *game_window = NULL;

/* Store position of the cursor in the game */
pos_t display_pos;

void top_bar_init();
void bot_bar_init();
void game_window_init();

/*
 * Initialize windows and variables required by the display
 */
void display_init()
{
    /* initialize screens */
    main_window = initscr();
    top_bar = subwin(main_window, 1, COLS, 0, 0);
    bot_bar = subwin(main_window, 1, COLS, LINES - 1, 0);
    game_window = subwin(main_window, LINES - 2, COLS, 1, 0);

    /* initialize game size */
    game_window_size.x = COLS - 1;
    game_window_size.y = LINES - 3;

    /* initialize game positions */
    display_pos.x = 0;
    display_pos.y = 0;

    /* initialize allt the windows */
    top_bar_init();
    bot_bar_init();
    game_window_init();

    /* remove cursor and don't echo keypresses */
    noecho();
    curs_set(0);
}

/*
 * Destroy the windows and cleanup
 */
void display_destroy()
{
    delwin(top_bar);
    delwin(bot_bar);
    delwin(game_window);
    delwin(main_window);
    endwin();
}

/*
 * Move the cursor to the new position
 */
void display_move(pos_t pos)
{
    wattrset(game_window, A_NORMAL);
    mvwprintw(game_window, display_pos.y, display_pos.x, "%c", ' ');
    wattrset(game_window, A_STANDOUT);
    mvwprintw(game_window, pos.y, pos.x, "%c", cursor.right);
    display_pos.x = pos.x;
    display_pos.y = pos.y;
}

/*
 * Draw all the windows again
 */
void display_draw()
{
    wrefresh(game_window);
    wrefresh(top_bar);
    wrefresh(bot_bar);
}

void game_window_init()
{
    wattrset(game_window, A_STANDOUT);
    mvwprintw(game_window, 0, 0, "%c", cursor.right);

    wrefresh(game_window);
}

/*
 * Initialize the top bar
 */
void top_bar_init()
{
    wattrset(top_bar, A_STANDOUT);
    for (int i = 0; i < COLS; ++i) {
        mvwprintw(top_bar, 0, i, " ");
    }
    wrefresh(top_bar);
}

/**
 * Initialize the bottom bar
 */
void bot_bar_init()
{
    wattrset(bot_bar, A_STANDOUT);
    for (int i = 0; i < COLS; ++i) {
        mvwprintw(bot_bar, 0, i, " ");
    }
    wrefresh(bot_bar);
}
