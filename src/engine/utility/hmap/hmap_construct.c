/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_construct
*/

#include "engine/utility/hashmap.h"

OmHashmap *OmHash_new(void)
{
    OmHashmap *new = malloc(sizeof(OmHashmap));

    if (!new)
        return (NULL);
    new->size = 0;
    new->keys = OmVec_new();
    new->data = OmVec_new();
    if (new->keys == NULL || new->data == NULL) {
        free(new);
        return (NULL);
    }
    return (new);
}

OmHashmap *OmHash_from_capicity(size_t capacity)
{
    OmHashmap *new = malloc(sizeof(OmHashmap));

    if (!new)
        return (NULL);
    new->size = 0;
    new->keys = OmVec_from_capacity(capacity);
    new->data = OmVec_from_capacity(capacity);
    if (!new->keys || !new->data) {
        free(new);
        return (NULL);
    }
    return (new);
}

OmHashmap *OmHash_clone(OmHashmap *origin)
{
    OmHashmap *new = malloc(sizeof(OmHashmap));

    if (!new)
        return (NULL);
    new->size = origin->size;
    new->keys = OmVec_clone(origin->keys);
    new->data = OmVec_clone(origin->data);
    return (new);
}

OmHashmap *OmHash_merge(OmHashmap *this, OmHashmap *other)
{
    if (this == 0 || other == 0)
        return (this);
    for (size_t idx = 0; idx < other->size; idx++)
        OmHash.set(this, other->data->arr[idx], other->data->arr[idx]);
    return (this);
}