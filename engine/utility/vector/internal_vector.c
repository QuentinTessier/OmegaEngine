/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** internal_vector
*/

#include "utility/internal_vector.h"

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

OmVector *internal_OmVec_grow(OmVector *this, size_t count)
{
    bool ret = OmVec_reserve(this, compute_capacity(this->size + count));

    return ((ret) ? this : 0);
}