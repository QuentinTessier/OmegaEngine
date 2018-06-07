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
		return (tex->t[0]);
	if (value < 1.5)
		return (tex->t[1]);
	if (value < 2.5)
		return (tex->t[2]);
	if (value < 3.0)
		return (tex->t[3]);
	return (tex->t[4]);
}

t_t init_texture(void)
{
	t_t tex;
	sfIntRect r = {0, 0, S_V, S_V};

	tex.t = malloc(sizeof(sfTexture *) * TEX_NB);

	tex.t[0] = sfTexture_createFromFile("./assets/tile_rock.png", &r);
	tex.t[1] = sfTexture_createFromFile("./assets/tile_blank.png", &r);
	tex.t[2] = sfTexture_createFromFile("./assets/tile_dirt.png", &r);
	tex.t[3] = sfTexture_createFromFile("./assets/tile_blank.png", &r);
	tex.t[4] = sfTexture_createFromFile("./assets/tile_grass.png", &r);
	return (tex);
}

void update_shape_texture(win_t *win_info, map_t *map)
{
	for (int i = 0; i < win_info->sq_i; i++) {
		sfRectangleShape_setTexture(map->c_map[i], get_texture(map->d_map[i], &map->tex), sfFalse);
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