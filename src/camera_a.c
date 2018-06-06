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

static int modular_event_map(sfKeyCode code, dis_t *display, p_t *player)
{
	int index = index_movement(code);
	int mov[5][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {player->x - 14, player->y - 7}};

	if (index < 0)
		return (-1);
	display->x += mov[index][0];
	display->y += mov[index][1];
	if (index == 4) {
		display->x = mov[index][0];
		display->y = mov[index][1];
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

void camera_separeted_player(sfRenderWindow *window, dis_t *display, p_t *player, t_t *tex)
{
	sfEvent event;
	int index = 0;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtKeyPressed) {
			index = modular_event_map(event.key.code, display, player);
			modular_event_player(event.key.code, player);
		}
	}
	if (index == 0) {
		display->generated = generator(X_V, Y_V, display->x, display->y);
		update_shape_texture(display, tex);
	}
	return;
}