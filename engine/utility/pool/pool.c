/*
** EPITECH PROJECT, 2018
** CSFML_2D_RENDERER
** File description:
** pool
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility/pool.h"

OmPoolS *OmPool_create(size_t pool_size)
{
    OmPoolS *new = malloc(sizeof(OmPoolS));

    if (!new)
        return (0);
    new->top = -1;
    new->max = pool_size;
    new->data = malloc(sizeof(void *) * new->max);
    if (!new->data) {
        free(new->data);
        return (0);
    }
    return (new);
}

void OmPool_destroy(OmPoolS *handle)
{
    free(handle->data);
    free(handle);
}

void OmPool_push(OmPoolS *handle, void *data_ptr)
{
    if ((size_t)handle->top == handle->max - 1)
        return;
    handle->data[++handle->top] = data_ptr;
}

void *OmPool_pop(OmPoolS *handle, size_t idx)
{
    void *tmp;
    size_t to_move;

    if (handle->top == -1 || (size_t)handle->top < idx)
        return (0);
    tmp = handle->data[idx];
    to_move = handle->top - idx;
    memmove(handle->data + idx, handle->data + idx + 1, to_move * sizeof(void *));
    handle->top--;
    return (tmp);
}

void OmPool_insert(OmPoolS *handle, size_t idx, void *data_ptr)
{
    if ((size_t)handle->top == handle->max - 1)
        return;
    if (handle->top == -1 || (size_t)handle->top < idx) {
        OmPool_push(handle, data_ptr);
        return;
    }
    if ((size_t)handle->top + 1 >= handle->max - 1)
        return;
    memmove(handle->data + idx + 1, handle->data + idx, (handle->top - idx + 1) * sizeof(void *));
    handle->data[idx] = data_ptr;
    handle->top++;
}

void OmPool_clear(OmPoolS *handle)
{
    handle->top = -1;
}