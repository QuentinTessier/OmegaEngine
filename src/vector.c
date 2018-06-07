/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** vector
*/

#include <stdio.h>
#include <stdlib.h>
#include "engine.h"

sfVector2f *generate_vector(win_t *win_info)
{
	int count = 0;
	sfVector2f *vector_map = malloc(sizeof(sfVector2f) * win_info->sq_i);

	for (int i = 0; i < win_info->sq_y; i++) {
		for (int j = 0; j < win_info->sq_x; j++) {
			vector_map[count].x = j * S_V;
			vector_map[count].y = i * S_V;
			count++;
		}
	}
	return (vector_map);
}