/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Scene
*/

#pragma once

#include <SFML/Graphics.h>

typedef struct scene scene_t;
typedef struct root root_t;

typedef void (*s_InitItem_t)(scene_t **self);
typedef void (*s_DrawItem_t)(const root_t *root, scene_t *self);

struct scene {
	sfCircleShape *item;

	s_DrawItem_t DrawItem;
};

void Create_scene(scene_t **self, float raduis);
void scene_DrawItem(const root_t *root, scene_t *scene);