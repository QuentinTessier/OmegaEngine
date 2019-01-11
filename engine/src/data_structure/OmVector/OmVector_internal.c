/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** internal_vector
*/

#include "data_structure/data_internal/OmVector_Internal.h"

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

OmVectorS *internal_OmVec_grow(OmVectorS *this, size_t count)
{
    bool ret = OmVector.reserve(this, compute_capacity(this->size + count));

    return ((ret) ? this : 0);
}