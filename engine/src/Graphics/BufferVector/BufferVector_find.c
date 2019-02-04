/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_find
*/

#include "Graphics/BufferVector.h"

static bool sfVertex_compare(sfVertex a, sfVertex b)
{
    if (a.position.x != b.position.x || a.position.y != b.position.y)
        return (false);
    if (a.color.r != b.color.r || a.color.g != b.color.g || a.color.b != b.color.b || a.color.a != b.color.a)
        return (false);
    if (a.texCoords.x != b.texCoords.x || a.texCoords.y != b.texCoords.y)
        return (false);
    return (true);
}

ssize_t OmBufferVector_index_of(OmBufferVector *this, sfVertex elem)
{
    size_t idx = 0;

    if (this == 0 || this->size == 0)
        return (-1);
    for (idx = 0; idx < this->size && !sfVertex_compare(this->data[idx], elem); idx++);
    return ((idx < this->size) ?  (ssize_t)(idx) : (ssize_t)(-1));
}

ssize_t OmBufferVector_last_index_of(OmBufferVector *this, sfVertex elem)
{
    size_t idx;

    if (this == 0|| this->size == 0)
        return (-1);
    for (idx = this->size - 1; idx && !sfVertex_compare(this->data[idx], elem); idx--);
    if (idx || (idx == 0 && sfVertex_compare(this->data[idx], elem)))
        return ((ssize_t)(idx));
    return ((ssize_t)(-1));
}

ssize_t OmBufferVector_find_index(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context)
{
    size_t idx = 0;

    if (this == 0 || this->size == 0)
        return (-1);
    while (idx < this->size &&
        predicate(context, this->data[idx], idx) == false)
        idx += 1;
    return ((idx < this->size) ? (ssize_t)(idx) : (ssize_t)(-1));
}

ssize_t OmBufferVector_find_last_index(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context)
{
    size_t idx = this->size - 1;

    if (this == 0 || this->size == 0)
        return (-1);
    while (idx && predicate(context, this->data[idx], idx) == false)
        idx -= 1;
    if (idx || (idx == 0 && predicate(context, this->data[0], 0) == true))
        return ((ssize_t)(idx));
    return ((ssize_t)(-1));
}

sfVertex OmBufferVector_find(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context)
{
    size_t idx = 0;

    if (this == 0 || this->size == 0)
        return (VERTEX_BASIC);
    while (idx < this->size &&
            predicate(context, this->data[idx], idx) == false)
            idx += 1;
    return ((idx < this->size) ? this->data[idx] : VERTEX_BASIC);
}

sfVertex OmBufferVector_find_last(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context)
{
    size_t idx = this->size - 1;

    if (this == 0 || this->size == 0)
        return (VERTEX_BASIC);
    while (idx && predicate(context, this->data[idx], idx) == false)
            idx -= 1;
    if (idx || (idx == 0 && predicate(context, this->data[0], 0) == true))
        return (this->data[idx]);
    return (VERTEX_BASIC);
}