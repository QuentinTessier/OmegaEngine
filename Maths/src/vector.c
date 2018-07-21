/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** vector
*/

#include <unistd.h>
#include <math.h>
#include "MVector.h"

MVector add_vectors(MVector a, MVector b, MVector *c)
{
	MVector temp = {a.x + b.x, a.y + b.y};

	if (c != NULL) {
		*c = temp;
	}
	return (temp);
}

unsigned int length_vector(MVector a)
{
	return (sqrt((double)(a.x * a.x + a.y * a.y)));
}

double Dot_Product(MVector a, MVector b)
{
	return ((double)(a.x * b.x + a.y + b.y))
}