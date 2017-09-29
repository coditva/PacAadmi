#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "map.h"

void map_init()
{
    int map_file;

    map_file = open("data/maps/mast.map", O_RDONLY);
    if (map_file == -1) {
        printf("shit\n");
    }

    /* size.x is size + 1, because of newline */
    map.size.x = 61;
    map.size.y = 15;

    map.data = (char *) malloc(sizeof(char) * map.size.x * map.size.y);
    read(map_file, map.data, map.size.x * map.size.y);
}

void map_destroy()
{
}

void map_load(char *path)
{
}
