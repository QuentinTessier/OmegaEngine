/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_data
*/

#include <string.h>
#include "DataStruct/OmVector_Internal.h"
#include "DataStruct/Vector.h"

size_t OmVector_size(OmVector *this)
{
    return ((this != 0) ? this->size : 0);
}

size_t OmVector_capacity(OmVector *this)
{
    return ((this != 0) ? this->capacity : 0);
}

void *OmVector_at(OmVector *this, size_t idx)
{
    if (this == 0 || this->size == 0 || this->size < idx)
        return (0);
    return (this->data[idx]);
}

bool OmVector_insert(OmVector *this, size_t idx, void *item)
{
    size_t last_size = this->size;

    if (this == 0 || this->size < idx)
        return (false);
    if (this->size == idx)
        return (OmVectorS->push_back(this, 1, item) != -1);
    if ((this->size + 1) > this->capacity &&
            internal_vec_grow(this, 1) == 0)
            return (false);
    memmove(this->data + idx + 1, this->data + idx,
            (last_size - idx) * sizeof(void *));
    OmVectorS->set(this, idx, item);
    return (true);
}

bool OmVector_set(OmVector *this, size_t idx, void *item)
{
    if (this == 0 || this->size == 0 || this->size < idx)
        return (0);
    this->data[idx] = item;
    return (true);
}

bool OmVector_includes(OmVector *this, void *elem)
{
    return (this ? (OmVectorS->index_of(this, elem) != -1) : false);
}

void *OmVector_front(OmVector *this)
{
    return ((this && this->size) ? this->data[0] : 0);
}

void *OmVector_back(OmVector *this)
{
    return ((this && this->size) ? this->data[this->size - 1] : 0);
}

void **OmVector_data(OmVector *this)
{
    return ((this && this->size) ? this->data : 0);
}