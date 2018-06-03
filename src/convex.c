/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** convex
*/

#include <stdlib.h>
#include "engine.h"

int color_value(double ramp)
{
	if (ramp < 0.35)
		ramp += 0.25;
	else if (ramp > 0.75)
		ramp -= 0.25;
	return (255 * ramp);
}

sfColor get_color(double value)
{
	int nb = (int)value;
	double ramp = value - (double)nb;
	int col = color_value(ramp);

	if (nb < 1)
		return ((sfColor){0, col, 0, 255});
	else if (nb < 2)
		return ((sfColor){0, col, 0, 255});
	else if (nb < 3)
		return ((sfColor){col, col, col, 255});
	else {
		return ((sfColor){0, col, 0, 255});
	}
	return (sfBlack);
}

void update_shape(dis_t *display)
{
	sfColor color;
	for (int i = 0; i < 31 * 17; i++) {
		color = get_color(display->generated[i]);
		sfRectangleShape_setFillColor(display->convex_map[i], color);
	}
	return;
}

sfRectangleShape **generate_convex(dis_t *display)
{
	sfRectangleShape **convex_map = malloc(sizeof(sfRectangleShape *) * 31 * 17);
	int count = 0;

	for (int i = 0; i < 31 * 17; i++)
		convex_map[i] = sfRectangleShape_create();
	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < 31 * 17; j++) {
			sfRectangleShape_setSize(convex_map[j], (sfVector2f){64, 64});
			sfRectangleShape_setPosition(convex_map[j], display->vector_map[j]);
			count++;
		}
	}
	
	return (convex_map);
}

void display_convex(dis_t *display, sfRenderWindow *window)
{
	for (int i = 0; i < 31 * 17; i++) {
		sfRenderWindow_drawRectangleShape(window, display->convex_map[i], NULL);
	}
}