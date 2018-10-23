/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** scene
*/

#pragma once

#include "object.h"

typedef struct root root_t;
typedef struct scene scene_t;

typedef scene_t *(*scene_add_object_t)(scene_t *self, object_t *new);
typedef scene_t *(*scene_draw_t)(scene_t *self, root_t *root);

struct scene {
    int ob_list_size;

    object_t *ob_list;
    scene_add_object_t scene_add_object;
    scene_draw_t draw;
};

scene_t *create_scene();
scene_t *scene_draw(scene_t *self, root_t *root);
scene_t *scene_add_object(scene_t *self, object_t *new);