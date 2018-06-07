/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** get_world_position
*/

#include "engine.h"

int check_world_position(win_t *win_info, p_t *player, map_t *map)
{
	if (player->x < map->w_x || player->y < map->w_y)
		return (0);
	if ((player->x > (map->w_x + win_info->sq_x - 1)) || (player->y > (map->w_y + win_info->sq_y - 1)))
		return (0);
	else
		return (1);
}

sfVector2f get_map_position(win_t *win_info, p_t *player, map_t *map)
{
	int i = map->w_x;
	int j = map->w_y;
	int tmp_x = 0;
	int tmp_y = 0;

	while (i < player->x) {
		i++;
		tmp_x++;
	}
	while (j < player->y) {
		j++;
		tmp_y++;
	}
	return (map->v_map[win_info->sq_x * tmp_y + tmp_x]);
}