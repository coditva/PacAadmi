#ifndef DATATYPES_H
#define DATATYPES_H

/* Struct to keep track of position */
typedef struct pos_struct {
    int x;
    int y;
} pos_t;

/* Struct for window size */
typedef struct game_window_size_struct {
    int x;
    int y;
} game_window_size_t;

/* Enum of all the key mappings */
enum key_mappings {
    KEY_NOP,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    PAUSE,
    QUIT,
    KEY_MAP_SIZE
};

/* Struct to describe map */
typedef struct map_struct {
    pos_t size;
    char *data;
} map_t;

/* Enum of display elements */
enum display_elements {
    D_BRICK,
    D_DOT,
    D_BLANK,
    D_PACMAN,
    D_BLINKY,
    D_PINKY,
    D_INKY,
    D_CLYDE,
    D_NEWLINE,
    D_ELEMENTS_SIZE
};

/* Enum of all colors */
enum display_colors {
    C_BLACK,
    C_WHITE,
    C_RED,
    C_BLUE,
    C_PINK,
    C_CYAN,
    C_ORANGE,
    C_YELLOW
};

enum display_colors_pair {
    C_BLACK_ON_BLACK,
    C_BLACK_ON_WHITE,
    C_BLACK_ON_RED,
    C_BLACK_ON_BLUE,
    C_BLACK_ON_PINK,
    C_BLACK_ON_CYAN,
    C_BLACK_ON_ORANGE,
    C_BLACK_ON_YELLOW,
    C_YELLOW_ON_BLACK
};

#endif /* end of include guard: DATATYPES_H */
