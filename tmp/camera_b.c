/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** camera
*/

#include "engine.h"

static int index_movement(sfKeyCode code)
{
	if (code == sfKeyZ)
		return (0);
	if (code == sfKeyS)
		return (1);
	if (code == sfKeyQ)
		return (2);
	if (code == sfKeyD)
		return (3);
	return (-1);
}

static int modular_event(sfKeyCode code, map_t *map, p_t *player)
{
	int index = index_movement(code);
	int mov[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

	if (index < 0)
		return (-1);
	map->w_x += mov[index][0];
	map->w_y += mov[index][1];
	player->x += mov[index][0];
	player->y += mov[index][1];
	return (0);
}

void camera_bind_to_player(win_t *win_info, map_t *map, p_t *player, t_t *tex)
{
	sfEvent event;
	int index = 0;

	while (sfRenderWindow_pollEvent(win_info->w, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(win_info->w);
		if (event.type == sfEvtKeyPressed)
			index = modular_event(event.key.code, map, player);
	}
	if (index == 0) {
		map->d_map = generator(win_info->sq_x, win_info->sq_y, map->w_x, map->w_y);
		update_shape_texture(win_info, map, tex);
	}
	return;
}