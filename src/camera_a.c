/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** camera_a
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
	if (code == sfKeySpace)
		return (4);
	return (-1);
}

static int index_movement_player(sfKeyCode code)
{
	if (code == sfKeyUp)
		return (0);
	if (code == sfKeyDown)
		return (1);
	if (code == sfKeyLeft)
		return (2);
	if (code == sfKeyRight)
		return (3);
	return (-1);
}

static int modular_event_map(sfKeyCode code, map_t *map, p_t *player, win_t *win_info)
{
	int index = index_movement(code);
	int mov[5][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0},
			{player->x - win_info->sq_x / 2, player->y - win_info->sq_y / 2}};

	if (index < 0)
		return (-1);
	map->w_x += mov[index][0];
	map->w_y += mov[index][1];
	if (index == 4) {
		map->w_x = mov[index][0];
		map->w_y = mov[index][1];
	}
	return (0);
}

static void modular_event_player(sfKeyCode code, p_t *player)
{
	int index = index_movement_player(code);
	int mov[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};	

	if (index < 0 || index == 5)
		return;
	player->x += mov[index][0];
	player->y += mov[index][1];
	return;
}

void camera_separeted_player(win_t *win_info, map_t *map, p_t *player, t_t *tex)
{
	sfEvent event;
	int index = 0;

	while (sfRenderWindow_pollEvent(win_info->w, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(win_info->w);
		if (event.type == sfEvtKeyPressed) {
			index = modular_event_map(event.key.code, map, player, win_info);
			modular_event_player(event.key.code, player);
		}
	}
	if (index == 0) {
		map->d_map = generator(win_info->sq_x, win_info->sq_y, map->w_x, map->w_y);
		update_shape_texture(win_info, map, tex);
	}
	return;
}