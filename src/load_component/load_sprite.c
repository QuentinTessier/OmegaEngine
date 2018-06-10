/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** load_sprite
*/

#include <string.h>
#include "engine.h"

char *str_append(const char *dest, const char *app)
{
	char *result = malloc(sizeof(char) * strlen(dest) + strlen(app) + 1);
	size_t i = 0;
	size_t j = 0;

	while (i < strlen(dest)) {
		result[i] = dest[i];
		i++;
	}
	while (j < strlen(app)) {
		result[i] = app[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

spr_t *load_back_sprite(size_t nb, char *path, const sfVector2f *varray)
{
	spr_t * tab_spr = malloc(sizeof(spr_t) * nb);
	size_t i = 0;
	
	while (i < nb) {
		tab_spr[i].s = sfSprite_create();
		tab_spr[i].r = all_img;
		tab_spr[i].p = varray[i];
		tab_spr[i].t = sfTexture_createFromFile(str_append(path, strdup(BACKARRAY(i))), &tab_spr[i].r);
		sfSprite_setTexture(tab_spr[i].s, tab_spr[i].t, sfFalse);
		sfSprite_setPosition(tab_spr[i].s, tab_spr[i].p);
		i++;
	}
	return (tab_spr);
}

spr_t *load_middle_sprite(size_t nb, char *path, const sfVector2f *varray)
{
	spr_t *tab_spr = malloc(sizeof(spr_t) * nb);
	size_t i = 0;

	while (i < nb) {
		tab_spr[i].s = sfSprite_create();
		tab_spr[i].r = all_img;
		tab_spr[i].p = varray[i];
		tab_spr[i].t = sfTexture_createFromFile(str_append(path, strdup(MIDARRAY(i))), &tab_spr[i].r);
		sfSprite_setTexture(tab_spr[i].s, tab_spr[i].t, sfFalse);		
		sfSprite_setPosition(tab_spr[i].s, tab_spr[i].p);
		i++;
	}
	return (tab_spr);
}

spr_t *load_fore_sprite(size_t nb, char *path, const sfVector2f *varray)
{
	spr_t *tab_spr = malloc(sizeof(spr_t) * nb);
	size_t i = 0;

	while (i < nb) {
		tab_spr[i].s = sfSprite_create();
		tab_spr[i].r = all_img;
		tab_spr[i].p = varray[i];
		tab_spr[i].t = sfTexture_createFromFile(str_append(path, strdup(FOREARRAY(i))), &tab_spr[i].r);
		sfSprite_setTexture(tab_spr[i].s, tab_spr[i].t, sfFalse);		
		sfSprite_setPosition(tab_spr[i].s, tab_spr[i].p);
		i++;
	}
	return (tab_spr);
}

/*spr_t load_hero_sprite()
{
	spr_t sprite;

	sprite.filepath = HERO_SPR_PATH;
	sprite.s = sfSprite_create();
	sprite.r = hero_rect;
	sprite.t = sfTexture_createFromFile(HERO_SPR_PATH, &sprite.r);
	sprite.p = hero_pos;
	sfSprite_setTexture(sprite.s, sprite.t, sfFalse);
	sfSprite_setPosition(sprite.s, sprite.p);
	return (sprite);
}

void update_sprite(spr_t *sprite, sfIntRect new_rect)
{
	sprite->r = new_rect;
	sprite->t = sfTexture_createFromFile(sprite->filepath, &sprite->r);
	sfSprite_setTexture(sprite->s, sprite->t, sfFalse);
	return;
}*/