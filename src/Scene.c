/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Scene
*/

#include <stdlib.h>
#include "Root.h"
#include "Scene.h"

static const scene_t scene_setup = {
	NULL, &scene_DrawItem
};

void Create_scene(scene_t **self, float raduis)
{
	*self = malloc(sizeof(scene_t));
	**self = scene_setup;
	(*self)->item = sfCircleShape_create();
	sfCircleShape_setRadius((*self)->item, raduis);
	sfCircleShape_setFillColor((*self)->item, sfRed);
}

void scene_DrawItem(const root_t *root, scene_t *scene)
{
	sfRenderWindow_drawCircleShape(root->window, scene->item, NULL);
}