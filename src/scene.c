/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** scene
*/

#include <stdlib.h>
#include "root.h"
#include "scene.h"
#include "error.h"

scene_t *create_scene()
{
    scene_t *new = malloc(sizeof(scene_t));
    int error;

    PTR_CALL(new);
    POP_ERROR(error);
    if (error != NO_ERROR)
        exit (84);
    new->ob_list_size = 0;
    new->ob_list = NULL;
    new->scene_add_object = &scene_add_object;
    new->draw = &scene_draw;
    return (new);
}

scene_t *scene_draw(scene_t *self, root_t *root)
{
    object_t *tmp = self->ob_list;

    while (tmp != NULL) {
        sfRenderWindow_drawCircleShape(root->w_win, tmp->data, NULL);
        tmp = tmp->next;
    }
    return (self);
}

scene_t *scene_add_object(scene_t *self, object_t *new)
{
    object_add_sorted_object(&self->ob_list, new);
    return (self);
}