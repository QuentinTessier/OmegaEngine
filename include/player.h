/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** player
*/

#ifndef PLAYER_H_
	#define PLAYER_H_

#include <SFML/Graphics.h>

typedef struct player {
	int x;
	int y;
	sfSprite *s;
	sfTexture *t;
	sfIntRect r;
} p_t;

void render_player(sfVector2f position, sfRenderWindow *window, p_t *player);
p_t *init_player(void);

#endif /* !PLAYER_H_ */
