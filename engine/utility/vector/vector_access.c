/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector_access
*/

#include "utility/vector.h"

size_t OmVec_size(OmVectorS *this)
{
    return ((this == NULL) ? 0 : this->size);
}

size_t OmVec_capacity(OmVectorS *this)
{
    return ((this == NULL) ? 0 : this->capacity);
}