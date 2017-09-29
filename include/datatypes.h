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
    D_GHOST,
    D_NEWLINE,
    D_ELEMENTS_SIZE
};

#endif /* end of include guard: DATATYPES_H */
