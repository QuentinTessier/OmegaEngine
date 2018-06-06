/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** player
*/

#include <stdlib.h>
#include "engine.h"

p_t init_player(void)
{
	p_t player;

	player.s = sfSprite_create();
	player.r.left = 0;
	player.r.top = 0;
	player.r.height = 64;
	player.r.width = 64;
	player.t = sfTexture_createFromFile("./assets/player.png", &player.r);
	sfSprite_setTexture(player.s, player.t, sfFalse);
	player.x = 14;
	player.y = 7;
	return (player);
}

void render_player(sfVector2f position, sfRenderWindow *window, p_t *player)
{
	sfSprite_setPosition(player->s, position);
	sfRenderWindow_drawSprite(window, player->s, NULL);
	return;
}