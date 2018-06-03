/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** vector
*/

#include <stdio.h>
#include <stdlib.h>
#include "engine.h"

sfVector2f *generate_point(void)
{
	int count = 0;
	sfVector2f *vector_map = malloc(sizeof(sfVector2f) * 31 * 17);

	for (int i = 0; i <= Y_V; i++) {
		for (int j = 0; j <= X_V; j++) {
			vector_map[count].x = j * 64;
			vector_map[count].y = i * 64;
			count++;
		}
	}
	return (vector_map);
}