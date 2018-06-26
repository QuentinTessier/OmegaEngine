/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** simple_animation
*/

#include "engine.h"

spr_t new_sprite(char *path, sfIntRect size, sfVector2f pos)
{
	spr_t new_spr;
	sfImage *image = sfImage_createFromFile(path);

	new_spr.s = sfSprite_create();
	new_spr.t = sfTexture_createFromImage(image, &size);
	new_spr.p = pos;
	sfSprite_setTexture(new_spr.s, new_spr.t, sfFalse);
	sfSprite_setPosition(new_spr.s, new_spr.p);
	return (new_spr);
}

void scale_Sprite(sfSprite *s, sfVector2f scaler)
{
	sfSprite_scale(sgSprite, scale);
}

void move_rectSprite(sfSprite *s, sfIntRect new_rect)
{
	sfSprite_setTextureRect(s, new_rect);
	return;
}