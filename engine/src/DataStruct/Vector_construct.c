/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_construct
*/

#include <stdlib.h>
#include <string.h>
#include "DataStruct/Vector.h"

OmVector *OmVector_create(void)
{
    return (calloc(1, sizeof(OmVector)));
}

OmVector *OmVector_with_capacity(size_t capacity)
{
    OmVector *this = OmVectorS->Create();

    if (this == 0)
        return (0);
    this->data = calloc(capacity, sizeof(void *));
    if (this->data == 0) {
        free(this);
        return (0);
    }
    this->capacity = capacity;
    return (this);
}

OmVector *OmVector_clone(OmVector *src)
{
    OmVector *this;

    if (src == 0)
        return (0);
    this = OmVectorS->Create();
    if (this == 0)
        return (0);
    this->data = calloc(src->size, sizeof(void *));
    if (this->data == 0) {
        free(this);
        return (0);
    }
    memcpy(this->data, src->data, src->size * sizeof(void *));
    this->capacity = src->size;
    this->size = src->size;
    return (this);
}