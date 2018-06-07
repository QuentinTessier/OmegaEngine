/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** main
*/

#include <time.h>
#include <stdlib.h>
#include "engine.h"



/*void free_all(dis_t *display, p_t *player, t_t *tex)
{
	free(display->generated);
	free(display->vector_map);
	for (int i = 0; i < (X_V * Y_V); i++) {
		sfRectangleShape_destroy(display->convex_map[i]);
	}
	for (int i = 0; i < 3; i++)
		sfTexture_destroy(tex[i].t);
	free(tex);
	sfSprite_destroy(player->s);
	sfTexture_destroy(player->t);
	free(display->convex_map);
}*/

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
	map_t map;
	p_t player = init_player(&win_info);
	map.v_map = generate_vector(&win_info);
	map.w_x = 0;
	map.w_y = 0;
	map.d_map = generator(win_info.sq_x, win_info.sq_y, 0, 0);
	map.c_map = generate_convex(&win_info, map.v_map);
	map.tex = create_texture();
	update_shape_texture(&win_info, &map, map.tex);
	while (sfRenderWindow_isOpen(win_info.w)) {
		camera_separeted_player(&win_info, &map, &player,map.tex);
		sfRenderWindow_clear(win_info.w, sfBlack);
		display_convex(&map, &win_info);
		if (check_world_position(&win_info, &player, &map) == 1)
			render_player(get_map_position(&win_info, &player, &map), win_info.w, &player);
		sfRenderWindow_display(win_info.w);
	}
	sfRenderWindow_destroy(win_info.w);
	return (0);
}