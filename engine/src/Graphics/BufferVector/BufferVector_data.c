/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_data
*/

#include <string.h>
#include "Graphics/BufferVector_Internal.h"
#include "Graphics/BufferVector.h"

size_t OmBufferVector_size(OmBufferVector *this)
{
    return ((this != 0) ? this->size : 0);
}

size_t OmBufferVector_capacity(OmBufferVector *this)
{
    return ((this != 0) ? this->capacity : 0);
}

sfVertex OmBufferVector_at(OmBufferVector *this, size_t idx)
{
    if (this == 0 || this->size == 0 || this->size < idx)
        return (VERTEX_BASIC);
    return (this->data[idx]);
}

bool OmBufferVector_insert(OmBufferVector *this, size_t idx, sfVertex item)
{
    size_t last_size = this->size;

    if (this == 0 || this->size < idx)
        return (false);
    if (this->size == idx)
        return (OmBufferVectorS->push_back(this, 1, item) != -1);
    if ((this->size + 1) > this->capacity &&
            internal_buffvec_grow(this, 1) == 0)
            return (false);
    memmove(this->data + idx + 1, this->data + idx,
            (last_size - idx) * sizeof(void *));
    OmBufferVectorS->set(this, idx, item);
    return (true);
}

bool OmBufferVector_set(OmBufferVector *this, size_t idx, sfVertex item)
{
    if (this == 0 || this->size == 0 || this->size < idx)
        return (0);
    this->data[idx] = item;
    return (true);
}

bool OmBufferVector_includes(OmBufferVector *this, sfVertex elem)
{
    return (this ? (OmBufferVectorS->index_of(this, elem) != -1) : false);
}

sfVertex OmBufferVector_front(OmBufferVector *this)
{
    return ((this && this->size) ? this->data[0] : VERTEX_BASIC);
}

sfVertex OmBufferVector_back(OmBufferVector *this)
{
    return ((this && this->size) ? this->data[this->size - 1] : VERTEX_BASIC);
}

sfVertex *OmBufferVector_data(OmBufferVector *this)
{
    return ((this && this->size) ? this->data : 0);
}