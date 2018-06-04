/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** main
*/

#include <time.h>
#include <stdlib.h>
#include "engine.h"

void simple_player_movement(sfEvent event, sfRenderWindow *window, p_t *player)
{
	if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyUp)){
		player->y -= 1;
	}
	if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyDown)){
		player->y += 1;
	}
	if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyLeft)){
		player->x -= 1;
	}
	if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyRight)){
		player->x += 1;
	}
	return;
}

void event(sfRenderWindow *window, dis_t *display, p_t *player)
{
	sfEvent event;
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(window);
		}
		if (event.type == sfEvtKeyPressed
			&& sfKeyboard_isKeyPressed(sfKeyZ)){
			display->y -= 1;
			display->generated = generator(X_V, Y_V, display->x, display->y);
			update_shape(display);
		}
		if (event.type == sfEvtKeyPressed
			&& sfKeyboard_isKeyPressed(sfKeyS)){
			display->y += 1;
			display->generated = generator(X_V, Y_V, display->x, display->y);
			update_shape(display);
		}
		if (event.type == sfEvtKeyPressed
			&& sfKeyboard_isKeyPressed(sfKeyQ)){
			display->x -= 1;
			display->generated = generator(X_V, Y_V, display->x, display->y);
			update_shape(display);
		}
		if (event.type == sfEvtKeyPressed
			&& sfKeyboard_isKeyPressed(sfKeyD)){
			display->x += 1;
			display->generated = generator(X_V, Y_V, display->x, display->y);
			update_shape(display);
		}
		if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeySpace)){
			display->x = player->x - 14;
			display->y = player->y - 7;
			display->generated = generator(X_V, Y_V, display->x, display->y);
			update_shape(display);						
		}
		simple_player_movement(event, window, player);
	}
	return;
}


void free_all(dis_t *display)
{
	free(display->generated);
	free(display->vector_map);
	for (int i = 0; i < (X_V * Y_V); i++) {
		sfRectangleShape_destroy(display->convex_map[i]);
	}
	free(display->convex_map);
	free(display);
}

int main()
{
	dis_t *display = malloc(sizeof(dis_t));
	p_t *player = init_player();

	srand(time(NULL));
	display->vector_map = generate_point();
	display->convex_map = generate_convex(display);
	display->generated = generator(X_V, Y_V, display->x, display->y);
	display->x = 0;
	display->y = 0;
	sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, "ENGINE", sfClose, NULL);
	update_shape(display);	
	while (sfRenderWindow_isOpen(window)) {
		event(window, display, player);
		sfRenderWindow_clear(window, sfBlack);
		display_convex(display, window);
		if (check_world_position(player, display) != 0)
			render_player(display->vector_map[get_map_position(player, display)], window, player);	
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	free_all(display);
	return (0);
}