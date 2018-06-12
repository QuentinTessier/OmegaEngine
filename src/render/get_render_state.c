/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** get_render_state
*/

#include "engine.h"

sfBool check_inside_window(sfRectangleShape *window, sfFloatRect object)
{
	sfFloatRect window_r = sfRectangleShape_getGlobalBounds(window);
	return (sfFloatRect_intersects(&window_r, &object, NULL));
}