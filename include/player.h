/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** player
*/

#ifndef PLAYER_H_
	#define PLAYER_H_

#include <SFML/Graphics.h>

typedef struct player_stats {
	char *name;
	float health;
	float attack;
	float defence;
} ps_t;

typedef struct player {
	int x;
	int y;
	ps_t *stat;
	sfSprite *s;
	sfTexture *t;
	sfIntRect r;
} p_t;

void render_player(sfVector2f position, sfRenderWindow *window, p_t *player);

#endif /* !PLAYER_H_ */
