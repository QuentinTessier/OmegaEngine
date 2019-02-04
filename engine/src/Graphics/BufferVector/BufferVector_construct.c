/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_construct
*/

#include <stdlib.h>
#include <string.h>
#include "Graphics/BufferVector.h"

OmBufferVector *OmBufferVector_create(void)
{
    return (calloc(1, sizeof(OmBufferVector)));
}

void OmBufferVector_init(OmBufferVector *this, size_t capacity)
{
    this->data = calloc(capacity, sizeof(sfVertex));
    this->capacity = capacity;
    this->size = 0;
}

OmBufferVector *OmBufferVector_with_capacity(size_t capacity)
{
    OmBufferVector *this = OmBufferVectorS->create();

    if (this == 0)
        return (0);
    this->data = calloc(capacity, sizeof(sfVertex));
    if (this->data == 0) {
        free(this);
        return (0);
    }
    this->capacity = capacity;
    return (this);
}

OmBufferVector *OmBufferVector_clone(OmBufferVector *src)
{
    OmBufferVector *this;

    if (src == 0)
        return (0);
    this = OmBufferVectorS->create();
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