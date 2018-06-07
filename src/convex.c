/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** convex
*/

#include <stdlib.h>
#include <stdio.h>
#include "engine.h"

sfTexture *get_texture(double value, t_t *tex)
{
	if (value < 0)
		value *= -1.0;
	if (value < 1.0)
		return (tex[0].t);
	if (value < 1.5)
		return (tex[1].t);
	if (value < 2.5)
		return (tex[2].t);
	if (value < 3.0)
		return (tex[3].t);
	return (tex[4].t);
}

t_t *create_texture(void)
{
	t_t *tex = malloc(sizeof(t_t) * TEX_NB);
	sfIntRect r = {0, 0, S_V, S_V};

	tex[0].t = sfTexture_createFromFile("./assets/rock_tiles.png", &r);
	tex[1].t = sfTexture_createFromFile("./assets/tile.png", &r);	
	tex[2].t = sfTexture_createFromFile("./assets/dirt_tile.png", &r);
	tex[3].t = sfTexture_createFromFile("./assets/tile.png", &r);
	tex[4].t = sfTexture_createFromFile("./assets/grass_tile.png", &r);
	return (tex);
}

void update_shape_texture(win_t *win_info, map_t *map, t_t *tex)
{
	for (int i = 0; i < win_info->sq_i; i++) {
		sfRectangleShape_setTexture(map->c_map[i], get_texture(map->d_map[i], tex), sfFalse);
	}
	return;
}

sfRectangleShape **generate_convex(win_t *win_info, sfVector2f *v_map)
{
	sfRectangleShape **convex_map = malloc(sizeof(sfRectangleShape *) * win_info->sq_i);
	int count = 0;

	for (int i = 0; i < win_info->sq_i; i++)
		convex_map[i] = sfRectangleShape_create();
	for (int j = 0; j < win_info->sq_i; j++) {
		sfRectangleShape_setSize(convex_map[j], (sfVector2f){S_V, S_V});
		sfRectangleShape_setPosition(convex_map[j], v_map[j]);
		count++;
	}
	return (convex_map);
}

void display_convex(map_t *map, win_t *win_info)
{
	for (int i = 0; i < win_info->sq_i; i++) {
		sfRenderWindow_drawRectangleShape(win_info->w, map->c_map[i], NULL);
	}
}