#ifndef CHARACTER_H
#define CHARACTER_H

void character_init_all();
void character_get_position(character_t character, pos_t *pos);

void character_move(character_t character, pos_t pos);
void character_die(character_t character);

#endif /* end of include guard: CHARACTER_H */
