/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** sprite
*/

#include <sys/types.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "engine.h"

void sprite_create(_sprite_t *sprite, char *path, sfVector2f position)
{
	sprite->pos = position;
	sprite->s = sfSprite_create();
	sprite->t = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(sprite->s, sprite->t, sfFalse);
	sfSprite_setTextureRect(sprite->s, Get_rect(&sprite->f[0]));
	sfSprite_setPosition(sprite->s, sprite->pos);
}

void sprite_flipbook(_sprite_t *sprite, size_t nb, ...)
{
	va_list list;
	size_t i = 0;
	int n;
	sfVector2f pos;
	sfVector2f size;

	sprite->f = malloc(sizeof(_flipbook_t) * nb);
	va_start(list, nb);
	while (i < nb) {
		n = va_arg(list, int);
		pos = va_arg(list, sfVector2f);
		size = va_arg(list, sfVector2f);
		New_flipbook(&sprite->f[i], pos, size, n);
		i++;
	}
}

void destroy_item(_sprite_t *sprite)
{
	free(sprite->f);
	sfSprite_destroy(sprite->s);
	sfTexture_destroy(sprite->t);
}