/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_construct
*/

#include "data_structure/OmVector.h"
#include "data_structure/OmHash.h"

OmHashS *OmHash_new(void)
{
    OmHashS *new = malloc(sizeof(OmHashS));

    if (!new)
        return (NULL);
    new->size = 0;
    new->keys = OmVector.new();
    new->data = OmVector.new();
    if (new->keys == NULL || new->data == NULL) {
        free(new);
        return (NULL);
    }
    return (new);
}

OmHashS *OmHash_from_capacity(size_t capacity)
{
    OmHashS *new = malloc(sizeof(OmHashS));

    if (!new)
        return (NULL);
    new->size = 0;
    new->keys = OmVector.from_capacity(capacity);
    new->data = OmVector.from_capacity(capacity);
    if (!new->keys || !new->data) {
        free(new);
        return (NULL);
    }
    return (new);
}

OmHashS *OmHash_clone(OmHashS *origin)
{
    OmHashS *new = malloc(sizeof(OmHashS));

    if (!new)
        return (NULL);
    new->size = origin->size;
    new->keys = OmVector.clone(origin->keys);
    new->data = OmVector.clone(origin->data);
    return (new);
}

OmHashS *OmHash_merge(OmHashS *this, OmHashS *other)
{
    if (this == 0 || other == 0)
        return (this);
    for (size_t idx = 0; idx < other->size; idx++)
        OmHash.set(this, other->data->arr[idx], other->data->arr[idx]);
    return (this);
}