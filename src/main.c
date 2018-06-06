/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** main
*/

#include <time.h>
#include <stdlib.h>
#include "engine.h"



void free_all(dis_t *display, p_t *player, t_t *tex)
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
}

int main()
{
	dis_t display;
	p_t player = init_player();
	t_t *tex = create_texture();

	srand(time(NULL));
	display.vector_map = generate_point();
	display.convex_map = generate_convex(&display);
	display.x = 0;
	display.y = 0;
	display.generated = generator(X_V, Y_V, display.x, display.y);
	sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, "ENGINE", sfClose, NULL);
	update_shape_texture(&display, tex);
	while (sfRenderWindow_isOpen(window)) {
		camera_bind_to_player(window, &display, &player, tex);
		sfRenderWindow_clear(window, sfBlack);
		display_convex(&display, window);
		if (check_world_position(&player, &display) != 0)
			render_player(display.vector_map[get_map_position(&player, &display)], window, &player);	
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	free_all(&display, &player, tex);
	return (0);
}