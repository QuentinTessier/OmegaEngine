/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** root
*/

#pragma once

#include <SFML/Graphics.h>
#include "scene.h"

typedef struct root root_t;

typedef void (*launch_loop_t)(root_t *self);
typedef root_t *(*create_scene_array_t)(root_t *self, int nb, int focus_scene);
typedef root_t *(*add_scene_at_index_t)(root_t *self, int index, scene_t *new);

struct root {
    sfRenderWindow *w_win;
    sfVector2u w_size;
    char *w_name;

    int s_current;
    int s_max;
    scene_t **s_graph;

    launch_loop_t launch_loop;
    create_scene_array_t create_scene_array;
    add_scene_at_index_t add_scene_index;
};

root_t create_root(root_t self, sfVector2u size, char *name, sfUint32 style);
root_t *root_create_scene_array(root_t *self, int nb, int focus_scene);
root_t *root_add_scene_at_index(root_t *self, int index, scene_t *new);
void root_launch_loop(root_t *self);