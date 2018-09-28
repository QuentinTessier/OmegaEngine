/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Root
*/

#pragma once

#include <SFML/Graphics.h>

typedef struct root root_t;

typedef struct scene scene_t;

typedef void (*r_WindowLoop_t)(root_t *self);
typedef void (*r_CreateSceneGraph_t)(root_t *self, int scene_count);
typedef void (*r_EventHandler_t)(root_t *self, sfEvent event);

struct root {
	sfRenderWindow *window;
	sfVector2u w_size;
	char *w_name;

	int curr_graph;
	scene_t **s_graph;
	int s_count;

	r_CreateSceneGraph_t CreateSceneGraph;
	r_WindowLoop_t WindowLoop;
	r_EventHandler_t EventHandler;
};

void root_WindowLoop(root_t *self);
void root_CreateSceneGraph(root_t *self, int s_count);
void create_root(root_t *root, sfVector2u size, char *name, sfUint32 style);
void root_EventHandler(root_t *self, sfEvent event);