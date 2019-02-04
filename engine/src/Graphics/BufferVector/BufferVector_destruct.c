/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_destruct
*/

#include <stdlib.h>
#include "Graphics/BufferVector.h"

void OmBufferVector_clear(OmBufferVector *this)
{
    if (this == 0)
        return;
    this->size = 0;
    this->capacity = 0;
    free(this->data);
    this->data = 0;
}

void OmBufferVector_drop(OmBufferVector *this)
{
    if (this == 0)
        return;
    free(this->data);
    free(this);
}