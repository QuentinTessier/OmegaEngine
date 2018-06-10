/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "engine.h"

void init_window(wc_t *w_info)
{
	w_info->v = (sfVideoMode){W_WIDTH, W_HEIGHT, 32};
	w_info->w = sfRenderWindow_create(w_info->v, W_NAME, sfClose, NULL);
	w_info->r = sfRectangleShape_create();
	sfRectangleShape_setSize(w_info->r, (sfVector2f){W_WIDTH, W_HEIGHT});
	sfRectangleShape_setPosition(w_info->r, (sfVector2f){0, 0});
	return;
}

int main()
{
	wc_t w_info;
	spr_t *background = load_tab_sprite(3, "./assets/", backvarray);
	init_window(&w_info);

	while (sfRenderWindow_isOpen(w_info.w)) {
		sfEvent event;
		while (sfRenderWindow_pollEvent(w_info.w, &event))
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(w_info.w);
		sfRenderWindow_clear(w_info.w, sfBlack);
		RD_SFT_SP_ST(3, &w_info, background);
		sfRenderWindow_display(w_info.w);
	}
	sfRenderWindow_destroy(w_info.w);
	return (0);
}