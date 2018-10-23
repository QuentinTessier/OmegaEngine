/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** object
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "object.h"
#include "scene.h"
#include "error.h"

static void init_object_functions(object_t **ob)
{
    (*ob)->add_object = &object_add_sorted_object;
    (*ob)->search_object = &object_search_object;
}

object_t *create_object(int depth)
{
    object_t *new = malloc(sizeof(object_t));
    int error;

    PTR_CALL(new);
    POP_ERROR(error);
    if (error != NO_ERROR)
        exit (84);
    init_object_functions(&new);
    new->depth = depth;
    new->data = NULL;
    new->next = NULL;
    return (new);
}

object_t *object_add_sorted_object(object_t **ob_list, object_t *new)
{
    object_t *tmp;

    if (*ob_list == NULL || (*ob_list)->depth <= new->depth) {
        new->next = *ob_list;
        *ob_list = new;
    } else {
        tmp = *ob_list;
        while (tmp->next != NULL && tmp->next->depth > new->depth)
            tmp = tmp->next;
        new->next = tmp->next;
        tmp->next = new;
    }
    return (new);
}

object_t *object_search_object(object_t *ob_list, int depth)
{
    while (ob_list != NULL || ob_list->depth == depth) {
        ob_list = ob_list->next;
    }
    return (ob_list);
}