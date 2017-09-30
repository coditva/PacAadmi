#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "datatypes.h"
#include "map.h"

/* Array to keep track of positions of all characters */
int position[CH_SIZE];

void map_init()
{
    int map_file;
    int map_size;

    map_file = open("data/maps/mast.map", O_RDONLY);
    if (map_file == -1) {
        printf("shit\n");
    }

    /* size.x is size + 1, because of newline */
    map.size.x = 61;
    map.size.y = 15;

    map_window_size.x = map.size.x - 1;
    map_window_size.y = map.size.y;

    map_size = map.size.x * map.size.y;

    map.data = (char *) malloc(sizeof(char) * map_size);
    read(map_file, map.data, map_size);
}
