/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** check_render
*/

#include "engine.h"

int check_window_sprite(sfRectangleShape *win_r, sfSprite *s)
{
	sfFloatRect win_fr = sfRectangleShape_getGlobalBounds(win_r);
	sfFloatRect s_fr = sfSprite_getGlobalBounds(s);

	if (sfFloatRect_intersects(&win_fr, &s_fr, NULL) == sfTrue) {
		return (1);
	} else {
		return (0);
	}
	return (84);
}