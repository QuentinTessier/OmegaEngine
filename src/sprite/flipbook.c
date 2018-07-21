/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** flipbook
*/

#include "engine.h"

void New_flipbook(_flipbook_t *flip, sfVector2f pos, sfVector2f size, int nb)
{
	flip->pos = pos;
	flip->current_pos = pos;
	flip->nb = 0;
	flip->nb_max = nb;
	flip->size = size;
	return;
}

void Move_flipbook(_flipbook_t *flip)
{
	if (flip->nb == flip->nb_max) {
		flip->current_pos = flip->pos;
		flip->nb = 0;
		return;
	}
	flip->current_pos.x += flip->size.x;
	flip->current_pos.y += flip->size.y;
	flip->nb++;
	return;
}

sfIntRect Get_rect(_flipbook_t *flip)
{
	sfIntRect rect;

	rect.top = flip->current_pos.y;
	rect.left = flip->current_pos.x;
	rect.height = flip->size.y;
	rect.width = flip->size.x;
	return (rect);
}