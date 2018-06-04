/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** get_world_position
*/

#include "engine.h"

int check_world_position(p_t *player, dis_t *display)
{
	if (player->x < display->x || player->y < display->y)
		return (0);
	if (player->x > display->x + 31 || player->y > display->y + 16)
		return (0);
	else
		return (1);
}

int get_map_position(p_t *player, dis_t *display)
{
	int i = display->x;
	int j = display->y;
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
	return (30 * tmp_y + tmp_x);
}