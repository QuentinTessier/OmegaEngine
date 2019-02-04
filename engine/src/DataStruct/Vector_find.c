/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_find
*/

#include "DataStruct/Vector.h"

ssize_t OmVector_index_of(OmVector *this, void *elem)
{
    size_t idx = 0;

    if (this == 0 || this->size == 0)
        return (-1);
    for (idx = 0; idx < this->size && this->data[idx] != elem; idx++);
    return ((idx < this->size) ?  (ssize_t)(idx) : (ssize_t)(-1));
}

ssize_t OmVector_last_index_of(OmVector *this, void *elem)
{
    size_t idx;

    if (this == 0|| this->size == 0)
        return (-1);
    for (idx = this->size - 1; idx && this->data[idx] != elem; idx--);
    if (idx || (idx == 0 && this->data[idx] == elem))
        return ((ssize_t)(idx));
    return ((ssize_t)(-1));
}

ssize_t OmVector_find_index(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context)
{
    size_t idx = 0;

    if (this == 0 || this->size == 0)
        return (-1);
    while (idx < this->size &&
        predicate(context, this->data[idx], idx) == false)
        idx += 1;
    return ((idx < this->size) ? (ssize_t)(idx) : (ssize_t)(-1));
}

ssize_t OmVector_find_last_index(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context)
{
    size_t idx = this->size - 1;

    if (this == 0 || this->size == 0)
        return (-1);
    while (idx && predicate(context, this->data[idx], idx) == false)
        idx -= 1;
    if (idx || (idx == 0 && predicate(context, this->data[0], 0) == true))
        return ((ssize_t)(idx));
    return ((ssize_t)(-1));
}

void *OmVector_find(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context)
{
    size_t idx = 0;

    if (this == 0 || this->size == 0)
        return (0);
    while (idx < this->size &&
            predicate(context, this->data[idx], idx) == false)
            idx += 1;
    return ((idx < this->size) ? this->data[idx] : 0);
}

void *OmVector_find_last(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context)
{
    size_t idx = this->size - 1;

    if (this == 0 || this->size == 0)
        return (0);
    while (idx && predicate(context, this->data[idx], idx) == false)
            idx -= 1;
    if (idx || (idx == 0 && predicate(context, this->data[0], 0) == true))
        return (this->data[idx]);
    return (0);
}