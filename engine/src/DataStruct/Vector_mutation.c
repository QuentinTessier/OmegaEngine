/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_mutation
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "DataStruct/OmVector_Internal.h"
#include "DataStruct/Vector.h"

ssize_t OmVector_push_back(OmVector *this, size_t nb_args, ...)
{
    va_list list;
    size_t last_size = this->size;
    size_t total_size = this->size + nb_args;

    if (this == 0)
        return (-1);
    if (nb_args == 0)
        return (this->size);
    if (total_size > this->capacity &&
        internal_vec_grow(this, nb_args) == 0)
        return (-1);
    this->size = total_size;
    va_start(list, nb_args);
    for (size_t i = last_size; i < total_size; i++)
        OmVectorS->set(this, i, va_arg(list, void *));
    va_end(list);
    return (this->size);
}

ssize_t OmVector_push_front(OmVector *this, size_t nb_args, ...)
{
    va_list list;

    if (this == 0)
        return (-1);
    if (nb_args == 0)
        return (this->size);
    if ((this->size + nb_args) > this->capacity &&
        internal_vec_grow(this, nb_args) == 0)
        return (-1);
    memmove(this->data + nb_args, this->data, this->size * sizeof(void *));
    this->size += nb_args;
    va_start(list, nb_args);
    for (size_t i = 0; i < nb_args; i++)
        OmVectorS->set(this, i, va_arg(list, void *));
    va_end(list);
    return (this->size);
}

void *OmVector_pop_back(OmVector *this)
{
    void *item = OmVectorS->back(this);

    if (this == 0 || this->size == 0)
        return (0);
    this->size -= 1;
    return (item);
}

void *OmVector_pop_front(OmVector *this)
{
    void *item = OmVectorS->front(this);

    if (this == 0 || this->size == 0)
        return (0);
    this->size -= 1;
    memmove(this->data, this->data + 1, this->size * sizeof(void *));
    return (item);
}

void *OmVector_remove(OmVector *this, size_t idx)
{
    void *item;

    if (this == 0 || this->size < idx)
        return (0);
    item = this->data[idx];
    this->size -= 1;
    memmove(this->data + idx, this->data + idx + 1, (this->size - idx) * sizeof(void *));
    return (item);
}

OmVector *OmVector_reverse(OmVector *this)
{
    void *tmp;
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

bool OmVector_reserve(OmVector *this, size_t capacity)
{
    void **arr;

    if (this == 0 || capacity <= this->capacity)
        return (false);
    arr = realloc(this->data, capacity * sizeof(void *));
    if (arr == 0)
        return (false);
    this->data = arr;
    this->capacity = capacity;
    return (true);
}

OmVector *OmVector_concat(OmVector *this, OmVector *other)
{
    if (this == 0 || other == 0)
        return (this);
    OmVectorS->reserve(this, this->size + other->size);
    for (size_t idx = 0; idx < other->size; idx++)
        OmVectorS->push_back(this, 1, other->data[idx]);
    return (this);
}

void OmVector_shrink_to_fit(OmVector *this)
{
    void **arr = 0;

    if (this == 0 || this->size == this->capacity)
        return;
    arr = realloc(this->data, this->size * sizeof(void *));
    if (arr == 0)
        return;
    this->data = arr;
    this->capacity = this->size;
}