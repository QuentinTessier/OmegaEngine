/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** sprite
*/

#ifndef SPRITE_H_
	#define SPRITE_H_

typedef struct flipbook {
	sfVector2f pos;
	sfVector2f size;
	int nb_max;
	int nb;
	sfVector2f current_pos;
} _flipbook_t;

typedef struct spt {
	sfVector2f pos;
	sfSprite *s;
	sfTexture *t;
	_flipbook_t *f;
} _sprite_t;

void New_flipbook(_flipbook_t *flip, sfVector2f pos, sfVector2f size, int nb);
sfIntRect Get_rect(_flipbook_t *flip);

#endif /* !SPRITE_H_ */
