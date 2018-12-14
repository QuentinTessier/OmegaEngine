/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector_destruct
*/

#include "engine/utility/vector.h"

void OmVec_clear(OmVector *this, bool free_items)
{
    if (this == NULL)
        return;
    if (free_items)
        for (size_t i = 0; i < this->size; i++)
            free(this->arr[i]);
    this->size = 0;
    this->capacity = 0;
    free(this->arr);
    this->arr = 0;
}

void OmVec_drop(OmVector *this)
{
    if (this == NULL)
        return;
    free(this->arr);
    free(this);
}