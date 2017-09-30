#include <ncurses.h>
#include <stdlib.h>

#include "datatypes.h"
#include "display.h"
#include "map.h"

/* Various windows in the game */
WINDOW *main_window = NULL;
WINDOW *top_bar = NULL;
WINDOW *bot_bar = NULL;
WINDOW *game_window = NULL;

/* Local functions */
void top_bar_init();
void bot_bar_init();
void colors_init();

/*
 * Initialize windows and variables required by the display
 */
void display_init()
{
    /* initialize screens */
    main_window = initscr();
    top_bar = subwin(main_window, 1, COLS, 0, 0);
    bot_bar = subwin(main_window, 1, COLS, LINES - 1, 0);

    /* remove cursor and don't echo keypresses */
    noecho();
    curs_set(0);

    /* initialize allt the windows */
    top_bar_init();
    bot_bar_init();
    colors_init();
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
 * Draw all the windows again
 */
void display_draw()
{
    wrefresh(top_bar);
    wrefresh(bot_bar);
    wrefresh(game_window);
}

/*
 * Draw game window again
 */
void display_draw_game()
{
    enum display_colors_pair color;
    char object;
    int map_size;
    int y = 0, x = 0;

    map_size = map.size.x * map.size.y;
    for (int i = 0; i < map_size; ++i) {
        switch (map.data[i]) {
            case '-':
                color = C_BLACK_ON_BLUE;
                object = ' ';
                break;
            case ' ':
                color = C_YELLOW_ON_BLACK;
                object = '.';
                break;
            case ',':
                color = C_BLACK_ON_BLACK;
                object = ' ';
                break;
            case 'p':
                color = C_BLACK_ON_YELLOW;
                object = ' ';
                break;
            case 'b':
                color = C_BLACK_ON_RED;
                object = ' ';
                break;
            case 's':
                color = C_BLACK_ON_PINK;
                object = ' ';
                break;
            case 'i':
                color = C_BLACK_ON_CYAN;
                object = ' ';
                break;
            case 'c':
                color = C_BLACK_ON_ORANGE;
                object = ' ';
                break;
            case 10:
                /* don't add anything to map but go to next line */
                y += 2;
                continue;
        }

        x = (i % map.size.x) * 2;

        wattron(game_window, COLOR_PAIR(color));
        mvwprintw(game_window, y,   x, "%c%c", object, object);
        mvwprintw(game_window, y+1, x, "%c%c", object, object);
        wattroff(game_window, COLOR_PAIR(color));
    }

    /* Render */
    wrefresh(game_window);
}

/*
 * Load map in the display_map for drawing display later
 * Every char in map is transformed to 4 chars in display map except newline
 */
void display_load_map()
{
    pos_t display_map;

    /* Initialize display_map which will store the display */
    display_map.x = (map.size.x - 1) * 2;
    display_map.y = map.size.y * 2;

    /* Create a new window for holding the map */
    game_window = subwin(main_window, display_map.y, display_map.x,
            (LINES - display_map.y ) / 2, (COLS - display_map.x) / 2);
}

/*
 * Initialize colors
 */
void colors_init()
{
    start_color();

    /* define colors */
    init_color(C_BLACK, 0, 0, 0);
    init_color(C_WHITE, 1000, 1000, 1000);
    init_color(C_RED, 1000, 0, 0);
    init_color(C_BLUE, 0, 0, 1000);
    init_color(C_PINK, 1000, 750, 800);
    init_color(C_CYAN, 0, 1000, 1000);
    init_color(C_ORANGE, 1000, 500, 0);
    init_color(C_YELLOW, 1000, 1000, 0);

    /* define color pairs */
    init_pair(C_BLACK_ON_BLACK, C_BLACK, C_BLACK);
    init_pair(C_BLACK_ON_WHITE, C_BLACK, C_WHITE);
    init_pair(C_BLACK_ON_RED, C_BLACK, C_RED);
    init_pair(C_BLACK_ON_BLUE, C_BLACK, C_BLUE);
    init_pair(C_BLACK_ON_PINK, C_BLACK, C_PINK);
    init_pair(C_BLACK_ON_CYAN, C_BLACK, C_CYAN);
    init_pair(C_BLACK_ON_ORANGE, C_BLACK, C_ORANGE);
    init_pair(C_BLACK_ON_YELLOW, C_BLACK, C_YELLOW);
    init_pair(C_YELLOW_ON_BLACK, C_YELLOW, C_BLACK);
}

/*
 * Initialize the top bar
 */
void top_bar_init()
{
    wattron(top_bar, COLOR_PAIR(C_BLACK_ON_WHITE));
    for (int i = 0; i < COLS; ++i) {
        mvwprintw(top_bar, 0, i, " ");
    }
    wattroff(top_bar, COLOR_PAIR(C_BLACK_ON_WHITE));
    wrefresh(top_bar);
}

/*
 * Initialize the bottom bar
 */
void bot_bar_init()
{
    wattron(bot_bar, COLOR_PAIR(C_BLACK_ON_WHITE));
    for (int i = 0; i < COLS; ++i) {
        mvwprintw(bot_bar, 0, i, " ");
    }
    wattroff(bot_bar, COLOR_PAIR(C_BLACK_ON_WHITE));
    wrefresh(bot_bar);
}
