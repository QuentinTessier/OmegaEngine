/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** pause
*/

#include "engine.h"

void pause_game_for_duration(float duration)
{
	sfClock *c = sfClock_create();
	sfTime t;
	float s;


	while (s <= duration) {
		t = sfClock_getElapsedTime(c);
		s = sfTime_asSeconds(t);
	}
	sfClock_destroy(c);
}