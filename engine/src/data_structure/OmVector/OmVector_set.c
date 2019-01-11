/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector_set
*/

#include "data_structure/OmVector.h"

bool OmVec_set(OmVectorS *this, size_t idx, void *item)
{
    if (this == NULL || this->size == 0 || this->size < idx)
        return (false);
    this->arr[idx] = item;
    return (true);
}

void *OmVec_back(OmVectorS *this)
{
    return ((this && this->size) ? this->arr[this->size - 1] : 0);
}

void *OmVec_front(OmVectorS *this)
{
    return ((this && this->size) ? this->arr[0] : 0);
}

void *OmVec_at(OmVectorS *this, size_t idx)
{
    if (this == 0 || this->size == 0 || this->size < idx)
        return (0);
    return (this->arr[idx]);
}