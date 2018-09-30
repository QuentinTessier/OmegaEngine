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
	0, NULL, &s_AddSortedObject
};

static const object_t object_setup = {
	0, 0, 0, 0, NULL, NULL, &o_Init_as_Texture, NULL
};

void Create_scene(scene_t **self, int count)
{
	*self = malloc(sizeof(scene_t));
	**self = scene_setup;
	(*self)->l_ob = malloc(sizeof(object_t) * count);
	for (int i = 0; i < count; i++)
		(*self)->l_ob[i] = NULL;
}

object_t *s_AddSortedObject(object_t **l_ob, int depth)
{
	object_t *tmp;
	object_t *new = malloc(sizeof(object_t));
	*new = object_setup;
	new->depth = depth;

	if (*l_ob == NULL ||
		(*l_ob)->depth >= new->depth) {
			new->next = *l_ob;
			*l_ob = new;
	} else {
		tmp = *l_ob;
		while (tmp->next != NULL &&
			tmp->next->depth < new->depth) {
				tmp = tmp->next;
		}
		new->next = tmp->next;
		tmp->next = new;
	}
	return (new);
}