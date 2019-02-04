/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_destruct
*/

#include <stdlib.h>
#include "DataStruct/Vector.h"

void OmVector_clear(OmVector *this, bool free_items)
{
    if (this == 0)
        return;
    if (free_items)
        for (size_t i = 0; i < this->size; i++)
            free(this->data[i]);
    this->size = 0;
    this->capacity = 0;
    free(this->data);
    this->data = 0;
}

void OmVector_drop(OmVector *this)
{
    if (this == 0)
        return;
    free(this->data);
    free(this);
}