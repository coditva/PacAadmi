#ifndef KEY_MAPPINGS_H
#define KEY_MAPPINGS_H

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

int key_map[KEY_MAP_SIZE];

void key_mappings_init();
void key_mappings_destroy();

#endif /* end of include guard: KEY_MAPPINGS_H */
