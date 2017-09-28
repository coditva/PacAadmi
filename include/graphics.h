#ifndef GRAPHICS_H
#define GRAPHICS_H

/* The graphic to use for the cursor */
struct cursor_t {
    int up;
    int down;
    int left;
    int right;
} cursor = { 'u', '^', '>', '<' };

#endif /* end of include guard: GRAPHICS_H */
