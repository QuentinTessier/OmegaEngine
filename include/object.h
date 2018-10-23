/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** object
*/

#pragma once

typedef struct object object_t;

typedef object_t *(*add_sorted_object_t)(object_t **ob_list, object_t *new);
typedef object_t *(*search_object_t)(object_t *ob_list);

struct object {
    int depth;
    void *data;

    object_t *next;
    add_sorted_object_t add_object;
    search_object_t search_object;
};

object_t *create_object(int depth);
object_t *object_add_sorted_object(object_t **ob_list, object_t *new);
object_t *object_search_object(object_t *ob_list, int depth);