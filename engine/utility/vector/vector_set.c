/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector_set
*/

#include "utility/vector.h"

bool OmVec_set(OmVector *this, size_t idx, void *item)
{
    if (this == NULL || this->size == 0 || this->size < idx)
        return (false);
    this->arr[idx] = item;
    return (true);
}

void *OmVec_back(OmVector *this)
{
    return ((this && this->size) ? this->arr[this->size - 1] : 0);
}

void *OmVec_front(OmVector *this)
{
    return ((this && this->size) ? this->arr[0] : 0);
}

void *OmVec_at(OmVector *this, size_t idx)
{
    if (this == 0 || this->size == 0 || this->size < idx)
        return (0);
    return (this->arr[idx]);
}