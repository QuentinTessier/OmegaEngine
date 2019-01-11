/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector_find_item
*/

#include "data_structure/OmVector.h"

ssize_t OmVec_index_of(OmVectorS *this, void *element)
{
    size_t idx = 0;

    if (this == NULL || this->size == 0)
        return (-1);
    for (idx = 0; idx < this->size && this->arr[idx] != element; idx++);
    return ((idx < this->size) ? (ssize_t)(idx) : (ssize_t)(-1));
}

ssize_t OmVec_last_index_of(OmVectorS *this, void *element)
{
    size_t idx;

    if (this == NULL || this->size == 0)
        return (-1);
    for (idx = this->size - 1; idx && this->arr[idx] != element; idx--);
    if (idx || (idx == 0 && this->arr[idx] == element))
        return ((ssize_t)(idx));
    return ((ssize_t)(-1));
}

ssize_t OmVec_find_index(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context)
{
    size_t idx = 0;

    if (this == NULL || this->size == 0)
        return (-1);
    while (idx < this->size &&
        predicate(context, this->arr[idx], idx) == false)
        idx += 1;
    return ((idx < this->size) ? (ssize_t)(idx) : (ssize_t)(-1));
}

ssize_t OmVec_find_last_index(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context)
{
    size_t idx = this->size - 1;

    if (this == NULL || this->size == 0)
        return (-1);
    while (idx && predicate(context, this->arr[idx], idx) == false)
        idx -= 1;
    if (idx || (idx == 0 && predicate(context, this->arr[idx], idx) == true))
        return ((size_t)(idx));
    return ((ssize_t)(-1));
}

void *OmVec_find(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context)
{
    size_t idx = 0;

    if (this == NULL || this->size  == 0)
        return (NULL);
    while (idx < this->size &&
        predicate(context, this->arr[idx], idx) == false)
        idx += 1;
    return ((idx < this->size) ? this->arr[idx] : 0);
}

void *OmVec_find_last(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context)
{
    size_t idx = this->size - 1;

    if (this == NULL || this->size  == 0)
        return (NULL);
    while (idx && predicate(context, this->arr[idx], idx) == false)
        idx -= 1;
    if (idx || (idx == 0 && predicate(context, this->arr[0], 0) == true))
        return (this->arr[idx]);
    return (0);
}