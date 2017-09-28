#ifndef INPUT_H
#define INPUT_H

/* Initialize input */
void input_init();

/* Destroy input */
void input_destroy();

/* Return key pressed after waiting for a prompt */
int input_get_key();

#endif /* end of include guard: INPUT_H */
