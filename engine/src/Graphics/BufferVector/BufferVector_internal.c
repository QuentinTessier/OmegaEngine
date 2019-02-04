/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_internal
*/

#include "Graphics/BufferVector_Internal.h"
#include "Graphics/BufferVector.h"

static size_t compute_capacity(size_t capacity)
{
    capacity -= 1;
    capacity |= capacity >> 1;
    capacity |= capacity >> 2;
    capacity |= capacity >> 4;
    capacity |= capacity >> 8;
    capacity |= capacity >> 16;
    capacity |= capacity >> 32;
    return (capacity + 1);
}

OmBufferVector *internal_buffvec_grow(OmBufferVector *this, size_t count)
{
    bool ret = OmBufferVectorS->reserve(this, compute_capacity(this->size + count));

    return (ret ? this : 0);
}