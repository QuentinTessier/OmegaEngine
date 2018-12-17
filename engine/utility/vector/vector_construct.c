/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector
*/

#include <string.h>
#include "utility/vector.h"

OmVectorS *OmVec_new(void)
{
    return (calloc(1, sizeof(OmVectorS)));
}

OmVectorS *OmVec_from_capacity(size_t capacity)
{
    OmVectorS *new = OmVec_new();

    if (new == NULL)
        return (NULL);
    new->arr = calloc(capacity, sizeof(void *));
    if (new->arr == NULL) {
        free(new);
        return (NULL);
    }
    new->capacity = capacity;
    return (new);
}

OmVectorS *OmVec_clone(OmVectorS *vector)
{
    OmVectorS *new;

    if (vector == NULL)
        return (NULL);
    new = OmVec_new();
    if (new == NULL)
        return (NULL);
    new->arr = calloc(vector->size, sizeof(void *));
    if (new->arr == NULL) {
        free(new);
        return (NULL);
    }
    memcpy(new->arr, vector->arr, sizeof(void *) * vector->size);
    new->capacity = vector->size;
    new->size = vector->size;
    return (new);
}