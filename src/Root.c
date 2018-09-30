/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Root
*/

#include <stdlib.h>
#include "Root.h"
#include "Scene.h"

static const root_t root_setup = {
	NULL, (sfVector2u){0, 0}, NULL, 0, NULL, 0, &root_CreateSceneGraph, &root_WindowLoop, &root_EventHandler
};

void create_root(root_t *root, sfVector2u size, char *name, sfUint32 style)
{
	*root = root_setup;
	root->window = sfRenderWindow_create((sfVideoMode){size.x, size.y, 32}, name, style, NULL);
	root->w_size = size;
	root->w_name = name;
	root->s_graph = NULL;
	root->s_count = -1;
}

void root_WindowLoop(root_t *self)
{
	while (sfRenderWindow_isOpen(self->window)) {
		sfEvent event;
		while (sfRenderWindow_pollEvent(self->window, &event))
			self->EventHandler(self, event);
		sfRenderWindow_clear(self->window, sfBlack);
		sfRenderWindow_display(self->window);
	}
}

void root_CreateSceneGraph(root_t *self, int s_count)
{
	if (self->s_count == -1) {
		self->s_graph = malloc(sizeof(scene_t *) * s_count);
		for (int i = 0; i < s_count; i++)
			self->s_graph[i] = NULL;
		self->s_count = s_count;
	}
}

void root_EventHandler(root_t *self, sfEvent event)
{
	if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
		sfRenderWindow_close(self->window);
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
		self->curr_graph = 1;
}