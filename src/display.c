#include <ncurses.h>
#include <stdlib.h>

#include "display.h"
#include "graphics.h"
#include "map.h"

/* Various windows in the game */
WINDOW *main_window = NULL;
WINDOW *top_bar = NULL;
WINDOW *bot_bar = NULL;
WINDOW *game_window = NULL;

/* Store position of the cursor in the game */
pos_t display_pos;
/* Store map locally parsed for display */
map_t display_map;

/* Local functions */
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

    /* remove cursor and don't echo keypresses */
    noecho();
    curs_set(0);

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

/*
 * Draw game window again
 */
void display_draw_game()
{
    wattrset(game_window, A_NORMAL);
    wmove(game_window, 0, 0);
    for (int i = 0; i < display_map.size.x * display_map.size.y; ++i) {
        if (display_map.data[i] == D_NEWLINE) {
            wprintw(game_window, "\n");
        } else {
            wprintw(game_window, "%d", display_map.data[i]);
        }
    }

    wattrset(game_window, A_STANDOUT);
    mvwprintw(game_window, display_pos.y, display_pos.x, "%c", cursor.right);

    wrefresh(game_window);
}

/*
 * Load map in the display_map for drawing display later
 * Every char in map is transformed to 4 chars in display map except newline
 */
void display_load_map()
{
    int map_size, map_char;

    /* Initialize display_map which will store the display */
    display_map.size.x = (map.size.x - 1) * 2 + 1;
    display_map.size.y = map.size.y * 2;
    display_map.data = (char *) malloc( display_map.size.x
            * display_map.size.y
            * sizeof(char));

    /* Scale map to 2x */
    map_size = map.size.x * map.size.y;
    for (int i, j = 0; i < map_size; ++i, j += 2) {
        switch (map.data[i]) {
            case '-':
                map_char = D_BRICK;
                break;
            case ' ':
                map_char = D_DOT;
                break;
            case 'p':
                map_char = D_PACMAN;
                break;
            case 'g':
                map_char = D_GHOST;
                break;
            case 10:
                display_map.data[j] = D_NEWLINE;
                display_map.data[j + display_map.size.x] = D_NEWLINE;
                j += display_map.size.x - 1;
                continue;
        }
        display_map.data[j] = map_char;
        display_map.data[j + 1] = map_char;
        display_map.data[j + display_map.size.x] = map_char;
        display_map.data[j + display_map.size.x + 1] = map_char;
    }
}

/*
 * Initialize game window
 */
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

/*
 * Initialize the bottom bar
 */
void bot_bar_init()
{
    wattrset(bot_bar, A_STANDOUT);
    for (int i = 0; i < COLS; ++i) {
        mvwprintw(bot_bar, 0, i, " ");
    }
    mvwprintw(bot_bar, 0, 0, "%d", game_window_size.x);
    wrefresh(bot_bar);
}
