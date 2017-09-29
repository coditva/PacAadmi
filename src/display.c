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

    /* initialize game size */
    game_window_size.x = COLS - 1;
    game_window_size.y = LINES - 3;

    /* initialize game positions */
    display_pos.x = 0;
    display_pos.y = 0;

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
 * Move the cursor to the new position
 */
void display_move(pos_t pos)
{
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
    enum display_colors_pair color;
    char object;

    wmove(game_window, 0, 0);

    /* Read each character and print display equivalent */
    for (int i = 0; i < display_map.size.x * display_map.size.y; ++i) {
        switch (display_map.data[i]) {
            case D_BRICK:
                color = C_BLACK_ON_BLUE;
                object = ' ';
                break;
            case D_DOT:
                color = C_YELLOW_ON_BLACK;
                object = '.';
                break;
            case D_BLANK:
                color = C_BLACK_ON_BLACK;
                object = ' ';
                break;
            case D_PACMAN:
                color = C_BLACK_ON_YELLOW;
                object = ' ';
                break;
            case D_BLINKY:
                color = C_BLACK_ON_RED;
                object = ' ';
                break;
            case D_PINKY:
                color = C_BLACK_ON_PINK;
                object = ' ';
                break;
            case D_INKY:
                color = C_BLACK_ON_CYAN;
                object = ' ';
                break;
            case D_CLYDE:
                color = C_BLACK_ON_ORANGE;
                object = ' ';
                break;
            case D_NEWLINE:
                break;
        }

        /* print the object with color */
        wattron(game_window, COLOR_PAIR(color));
        wprintw(game_window, "%c", object);
        wattroff(game_window, COLOR_PAIR(color));
    }

    /* Display the pointer */
    mvwprintw(game_window, display_pos.y, display_pos.x, "%c", cursor.right);

    /* Render */
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
    display_map.size.x = (map.size.x - 1) * 2;
    display_map.size.y = map.size.y * 2;

    display_map.data = (char *) malloc(
            display_map.size.x
            * display_map.size.y
            * sizeof(char));

    /* Create a new window for holding the map */
    game_window = subwin(main_window,
            display_map.size.y,
            display_map.size.x,
            (LINES - display_map.size.y ) / 2,
            (COLS - display_map.size.x) / 2);

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
            case 'b':
                map_char = D_BLINKY;
                break;
            case 's':
                map_char = D_PINKY;
                break;
            case 'i':
                map_char = D_INKY;
                break;
            case 'c':
                map_char = D_CLYDE;
                break;
            case 10:
                /* don't add anything to map but go to next line */
                j += display_map.size.x - 2;
                continue;
        }

        display_map.data[j] = map_char;
        display_map.data[j + 1] = map_char;
        display_map.data[j + display_map.size.x] = map_char;
        display_map.data[j + display_map.size.x + 1] = map_char;
    }
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
