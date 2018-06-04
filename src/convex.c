/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** convex
*/

#include <stdlib.h>
#include <stdio.h>
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

	if (nb < 3)
		return ((sfColor){0, col, 0, 255});
	else
		return ((sfColor){col, col, col, 255});
	return (sfBlack);
}

void update_shape(dis_t *display)
{
	sfColor color;
	for (int i = 0; i < (X_V * Y_V); i++) {
		color = get_color(display->generated[i]);
		sfRectangleShape_setFillColor(display->convex_map[i], color);
	}
	return;
}

sfTexture *get_texture(double value, t_t *tex)
{
	int int_value = (int)value;

	//printf("a");
	if (int_value < 0)
		int_value *= -1;
	if (int_value > 2)
		int_value = 2;
	return (tex[int_value].t);
}

t_t *create_texture(void)
{
	t_t *tex = malloc(sizeof(t_t) * 6);
	sfIntRect r = {0, 0, 64, 64};

	tex[0].t = sfTexture_createFromFile("./assets/rock_tiles.png", &r);
	tex[1].t = sfTexture_createFromFile("./assets/dirt_tile.png", &r);
	tex[2].t = sfTexture_createFromFile("./assets/grass_tile.png", &r);
	return (tex);
}

void update_shape_texture(dis_t *display, t_t *tex)
{
	for (int i = 0; i < (X_V * Y_V); i++) {
		//printf("%d : %0.1f\n", i, display->generated[i]);
		sfRectangleShape_setTexture(display->convex_map[i], get_texture(display->generated[i], tex), sfFalse);
	}
	return;
}

sfRectangleShape **generate_convex(dis_t *display)
{
	sfRectangleShape **convex_map = malloc(sizeof(sfRectangleShape *) * X_V * Y_V);
	int count = 0;

	for (int i = 0; i < (X_V * Y_V); i++)
		convex_map[i] = sfRectangleShape_create();
	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < (X_V * Y_V); j++) {
			sfRectangleShape_setSize(convex_map[j], (sfVector2f){64, 64});
			sfRectangleShape_setPosition(convex_map[j], display->vector_map[j]);
			count++;
		}
	}
	
	return (convex_map);
}

void display_convex(dis_t *display, sfRenderWindow *window)
{
	for (int i = 0; i < (X_V * Y_V); i++) {
		sfRenderWindow_drawRectangleShape(window, display->convex_map[i], NULL);
	}
}