/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector_mutation_a
*/

#include <stdarg.h>
#include <string.h>
#include "engine/utility/vector.h"
#include "engine/utility/internal_vector.h"

ssize_t OmVec_push_back(OmVector *this, size_t nb_args, ...)
{
    va_list list;
    size_t l_size = this->size;
    size_t n_size = this->size + nb_args;

    if (this == NULL)
        return (-1);
    if (nb_args == 0)
        return (this->size);
    if (n_size > this->capacity && internal_OmVec_grow(this, nb_args) == NULL)
        return (-1);
    this->size = n_size;
    va_start(list, nb_args);
    for (size_t i = l_size; i < n_size; i++)
        OmVec_set(this, i, va_arg(list, void *));
    va_end(list);
    return (this->size);
}

ssize_t OmVec_push_front(OmVector *this, size_t nb_args, ...)
{
    va_list list;

    if (this == NULL)
        return (-1);
    if (nb_args == 0)
        return (this->size);
    if ((this->size + nb_args) > this->capacity &&
            internal_OmVec_grow(this, nb_args) == NULL)
        return (-1);
    memmove(this->arr + nb_args, this->arr, this->size * sizeof(void *));
    this->size += nb_args;
    va_start(list, nb_args);
    for (size_t i = 0; i < nb_args; i++)
        OmVec_set(this, i, va_arg(list, void *));
    va_end(list);
    return (this->size);
}

void *OmVec_pop_back(OmVector *this)
{
    void *item = OmVec_back(this);

    if (this == NULL || this->size == 0)
        return (NULL);
    this->size -= 1;
    return (item);
}

void *OmVec_pop_front(OmVector *this)
{
    void *item = OmVec_front(this);

    if (this == NULL || this->size == 0)
        return (NULL);
    this->size -= 1;
    memmove(this->arr, this->arr + 1, this->size * sizeof(void *));
    return (item);
}

bool OmVec_insert(OmVector *this, size_t idx, void *element)
{
    size_t l_size = this->size;

    if (this == NULL || this->size < idx)
        return (false);
    if (this->size == idx)
        return (OmVec_push_back(this, 1, element) != -1);
    if ((this->size + 1) > this->capacity && internal_OmVec_grow(this, 1) == NULL)
        return (false);
    memmove(this->arr + idx + 1, this->arr + idx, (l_size - idx) * sizeof(void *));
    OmVec_set(this, idx, element);
    return (true);
}

void *OmVec_remove(OmVector *this, size_t idx)
{
    void *tmp;

    if (this == NULL || this->size < idx)
        return (0);
    tmp = this->arr[idx];
    this->size -= 1;
    memmove(this->arr + idx, this->arr + idx + 1, (this->size - idx) * sizeof(void *));
    return (tmp);
}

OmVector *OmVec_reverse(OmVector *this)
{
    void *tmp;
    size_t lo = 0;
    size_t hi = this->size - 1;

    if (this == NULL || this->size == 0)
        return (0);
    while (hi > lo) {
        tmp = this->arr[lo];
        this->arr[lo] = this->arr[hi];
        this->arr[hi] = tmp;
        lo += 1;
        hi -= 1;
    }
    return (this);
}

OmVector *OmVec_concat(OmVector *this, OmVector *other)
{
    if (this == NULL || other == NULL)
        return (this);
    OmVec_reserve(this, this->size + other->size);
    for (size_t idx = 0; idx < other->size; idx++)
        OmVec_push_back(this, 1, other->arr[idx]);
    return (this);
}

bool OmVec_reserve(OmVector *this, size_t capacity)
{
    void **arr;

    if (this == NULL || capacity <= this->capacity)
        return (false);
    arr = realloc(this->arr, capacity * sizeof(void *));
    if (arr == 0)
        return (false);
    this->arr = arr;
    this->capacity = capacity;
    return (true);
}

void OmVec_shrink_to_fit(OmVector *this)
{
    void **arr;

    if (this == NULL || this->size == this->capacity)
        return;
    arr = realloc(this->arr, this->size * sizeof(void *));
    if (arr == NULL)
        return;
    this->arr = arr;
    this->capacity = this->size;
}