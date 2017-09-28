#ifndef DISPLAY_H
#define DISPLAY_H

#include <datatypes.h>

/* Initialize the display */
void display_init();

/* Destroy the display */
void display_destroy();

void display_refresh();
void display_draw();
void display_move(pos_t pos);

#endif /* end of include guard: DISPLAY_H */
