/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** data_container
*/

#include <stdlib.h>
#include "engine/framework/data_container.h"

static OmObjectContainer *create(size_t size)
{
    OmObjectContainer *handle = 0;

    handle = malloc(sizeof(*handle));
    if (!handle)
        return (NULL);
    handle->size = size;
    handle->offset = 0;
    handle->data_array = malloc(sizeof(OmObject) * size);
    if (!handle->data_array) {
        free(handle);
        return (NULL);
    }
    return (handle);
}

OmObject *add(OmObjectContainer *handle, const char *name, int type, void *data)
{
    OmObject *new_ob = malloc(sizeof(OmObject));
}