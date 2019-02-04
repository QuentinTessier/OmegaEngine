/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_mutation
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "Graphics/BufferVector_Internal.h"
#include "Graphics/BufferVector.h"

ssize_t OmBufferVector_push_back(OmBufferVector *this, size_t nb_args, ...)
{
    va_list list;
    size_t last_size = this->size;
    size_t total_size = this->size + nb_args;

    if (this == 0)
        return (-1);
    if (nb_args == 0)
        return (this->size);
    if (total_size > this->capacity &&
        internal_buffvec_grow(this, nb_args) == 0)
        return (-1);
    this->size = total_size;
    va_start(list, nb_args);
    for (size_t i = last_size; i < total_size; i++)
        OmBufferVectorS->set(this, i, va_arg(list, sfVertex));
    va_end(list);
    return (this->size);
}

ssize_t OmBufferVector_push_front(OmBufferVector *this, size_t nb_args, ...)
{
    va_list list;

    if (this == 0)
        return (-1);
    if (nb_args == 0)
        return (this->size);
    if ((this->size + nb_args) > this->capacity &&
        internal_buffvec_grow(this, nb_args) == 0)
        return (-1);
    memmove(this->data + nb_args, this->data, this->size * sizeof(void *));
    this->size += nb_args;
    va_start(list, nb_args);
    for (size_t i = 0; i < nb_args; i++)
        OmBufferVectorS->set(this, i, va_arg(list, sfVertex));
    va_end(list);
    return (this->size);
}

sfVertex OmBufferVector_pop_back(OmBufferVector *this)
{
    sfVertex item = OmBufferVectorS->back(this);

    if (this == 0 || this->size == 0)
        return (VERTEX_BASIC);
    this->size -= 1;
    return (item);
}

sfVertex OmBufferVector_pop_front(OmBufferVector *this)
{
    sfVertex item = OmBufferVectorS->front(this);

    if (this == 0 || this->size == 0)
        return (VERTEX_BASIC);
    this->size -= 1;
    memmove(this->data, this->data + 1, this->size * sizeof(void *));
    return (item);
}

sfVertex OmBufferVector_remove(OmBufferVector *this, size_t idx)
{
    sfVertex item;

    if (this == 0 || this->size < idx)
        return (VERTEX_BASIC);
    item = this->data[idx];
    this->size -= 1;
    memmove(this->data + idx, this->data + idx + 1, (this->size - idx) * sizeof(void *));
    return (item);
}

OmBufferVector *OmBufferVector_reverse(OmBufferVector *this)
{
    sfVertex tmp;
    size_t lo = 0;
    size_t hi = this->size - 1;

    if (this == 0 || this->size == 0)
        return (0);
    while (hi > lo) {
        tmp = this->data[lo];
        this->data[lo] = this->data[hi];
        this->data[hi] = tmp;
        lo += 1;
        hi -= 1;
    }
    return (this);
}

bool OmBufferVector_reserve(OmBufferVector *this, size_t capacity)
{
    sfVertex *arr;

    if (this == 0 || capacity <= this->capacity)
        return (false);
    arr = realloc(this->data, capacity * sizeof(sfVertex));
    if (arr == 0)
        return (false);
    this->data = arr;
    this->capacity = capacity;
    return (true);
}

OmBufferVector *OmBufferVector_concat(OmBufferVector *this, OmBufferVector *other)
{
    if (this == 0 || other == 0)
        return (this);
    OmBufferVectorS->reserve(this, this->size + other->size);
    for (size_t idx = 0; idx < other->size; idx++)
        OmBufferVectorS->push_back(this, 1, other->data[idx]);
    return (this);
}

void OmBufferVector_shrink_to_fit(OmBufferVector *this)
{
    sfVertex *arr = 0;

    if (this == 0 || this->size == this->capacity)
        return;
    arr = realloc(this->data, this->size * sizeof(sfVertex));
    if (arr == 0)
        return;
    this->data = arr;
    this->capacity = this->size;
}