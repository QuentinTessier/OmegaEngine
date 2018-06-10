/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** simple_CSFML_comp_a
*/

#include <sys/types.h>
#include <SFML/Graphics.h>
#include <engine.h>

void render_tab_sfRectangle(size_t length, sfRenderWindow *window, sfRectangleShape **shape)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawRectangleShape(window, shape[i], NULL);
		i++;
	}
	return;
}

void render_tab_sfConvexShape(size_t length, sfRenderWindow *window, sfConvexShape **shape)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawConvexShape(window, shape[i], NULL);
		i++;
	}
	return;
}

void render_tab_sfSprite(size_t length, sfRenderWindow *window, sfSprite **sprite)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawSprite(window, sprite[i], NULL);
		i++;
	}
	return;
}

void render_tab_sfCircleShape(size_t length, sfRenderWindow *window, sfCircleShape **shape)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawCircleShape(window, shape[i], NULL);
		i++;
	}
	return;
}

void render_tab_struct(size_t length, wc_t *w_info, spr_t *sprite)
{
	size_t i = 0;

	while (i < length) {
		if (check_window_sprite(w_info->r, sprite[i].s) == 1)
			sfRenderWindow_drawSprite(w_info->w, sprite[i].s, NULL);
		i++;
	}
	return;
}