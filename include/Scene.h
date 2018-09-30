/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Scene
*/

#pragma once

#include <SFML/Graphics.h>

#include "Object.h"

typedef struct scene scene_t;
typedef struct root root_t;

typedef object_t *(*s_AddSortedObj_t)(object_t **l_ob, int depth);

struct scene {
	unsigned int count;

	object_t **l_ob;

	s_AddSortedObj_t AddSortedObject;
};

void Create_scene(scene_t **self, int count);
object_t *s_AddSortedObject(object_t **l_ob, int depth);