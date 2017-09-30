#include "character.h"
#include "map.h"

int position[CH_SIZE];

void character_move(character_t character, pos_t pos)
{
    map.data[position[character]] = ' ';
    position[character] = pos.y * map.size.x + pos.x;
    map.data[position[character]] = 'p';
}

void character_init_all()
{
    character_t ch;
    int map_size = map.size.x * map.size.y;

    /* load positions */
    map_size = map.size.x * map.size.y;
    for (int i = 0; i < map_size; ++i) {
        if (map.data[i] == 'p') {
            ch = CH_PACMAN;

        } else if (map.data[i] == 'b') {
            ch = CH_BLINKY;

        } else if (map.data[i] == 's') {
            ch = CH_PINKY;

        } else if (map.data[i] == 'i') {
            ch = CH_INKY;

        } else if (map.data[i] == 'c') {
            ch = CH_CLYDE;

        } else {
            continue;
        }

        position[ch] = i;
        map.data[i] = ' ';
    }
}

void character_get_position(character_t character, pos_t *pos)
{
    pos->x = position[character] % map.size.x;
    pos->y = position[character] / map.size.x;
}
