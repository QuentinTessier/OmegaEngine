/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** check_collider
*/

#include "engine.h"

sfBool check_collisionrect(sfFloatRect a, sfFloatRect b)
{
	return (sfFloatRect_intersects(&a , &b, NULL));
}