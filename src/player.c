/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** player
*/

#include <stdlib.h>
#include "engine.h"

p_t init_player(win_t *win_info)
{
	p_t player;

	player.s = sfSprite_create();
	player.r.left = 0;
	player.r.top = 0;
	player.r.height = S_V;
	player.r.width = S_V;
	player.t = sfTexture_createFromFile("./assets/player.png", &player.r);
	sfSprite_setTexture(player.s, player.t, sfFalse);
	player.x = win_info->sq_x / 2;
	player.y = win_info->sq_y / 2;
	return (player);
}

void render_player(sfVector2f position, sfRenderWindow *window, p_t *player)
{
	sfSprite_setPosition(player->s, position);
	sfRenderWindow_drawSprite(window, player->s, NULL);
	return;
}