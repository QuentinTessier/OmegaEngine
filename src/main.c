/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** main
*/

#include <stdlib.h>
#include "engine.h"



void free_all(win_t *win_info, map_t *map, p_t *player)
{
	free(map->d_map);
	free(map->v_map);
	for (int i = 0; i < win_info->sq_i; i++)
		sfRectangleShape_destroy(map->c_map[i]);
	free(map->c_map);
	for (int i = 0; i < TEX_NB; i++)
		sfTexture_destroy(map->tex.t[i]);
	sfSprite_destroy(player->s);
	sfTexture_destroy(player->t);
}

win_t init_window(char *name)
{
	win_t win_info;
	sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};

	win_info.sq_x = WIN_WIDTH / S_V;
	win_info.sq_y = WIN_HEIGHT / S_V;
	win_info.sq_i = win_info.sq_y * win_info.sq_x;
	win_info.w = sfRenderWindow_create(mode, name, sfClose, NULL);
	return (win_info);
}

void quit_event(win_t *win_info)
{
	sfEvent event;
	while (sfRenderWindow_pollEvent(win_info->w, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(win_info->w);
	}
	return;
}

int main()
{
	win_t win_info = init_window("ENGINE");
	map_t map = init_map(&win_info);
	p_t player = init_player(&win_info);

	update_shape_texture(&win_info, &map);
	while (sfRenderWindow_isOpen(win_info.w)) {
		event_camera(&win_info, &map);
		sfRenderWindow_clear(win_info.w, sfBlack);
		display_convex(&map, &win_info);
		if (check_world_position(&win_info, &player, &map) == 1)
			render_player(get_map_position(&win_info, &player, &map), win_info.w, &player);
		sfRenderWindow_display(win_info.w);
	}
	sfRenderWindow_destroy(win_info.w);
	free_all(&win_info, &map, &player);
	return (0);
}