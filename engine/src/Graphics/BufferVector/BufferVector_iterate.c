/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_iterate
*/

#include "Graphics/BufferVector.h"

void OmBufferVector_map(OmBufferVector *this,
            sfVertex (* func)(void *context, sfVertex elem, size_t idx),
            void *context)
{
    if (this == 0)
        return;
    for (size_t idx = 0; idx < this->size; idx++)
        this->data[idx] = func(context, this->data[idx], idx);
}

OmBufferVector *OmBufferVector_filter(OmBufferVector *this,
                    bool (* predicate)(void *context, sfVertex elem, size_t idx),
                    void *context)
{
    if (this == 0 || this->size == 0)
        return (0);
    for (ssize_t idx = ((ssize_t)(this->size)) - 1; idx >= 0; idx--)
        if (predicate(context, this->data[idx], idx) == false)
            OmBufferVectorS->remove(this, idx);
    return (this);
}

bool OmBufferVector_sort_helper(OmBufferVector *this,
            int (* predicate)(sfVertex, size_t, sfVertex, size_t))
{
    bool done = true;
    sfVertex tmp = VERTEX_BASIC;
    size_t before_last = this->size - 1;

    for (size_t idx = 0; idx < before_last; idx++)
        if (predicate(this->data[idx], idx, this->data[idx + 1],
            idx + 1) > 0) {
            done = false;
            tmp = this->data[idx];
            this->data[idx] = this->data[idx + 1];
            this->data[idx + 1] = tmp;
        }
    return (done);
}

OmBufferVector *OmBufferVector_sort(OmBufferVector *this,
        int (* predicate)(sfVertex elem1, size_t idx1, sfVertex elem2, size_t idx2))
{
    if (this == 0 || this->size == 0)
        return (0);
    while (OmBufferVector_sort_helper(this, predicate) == false);
    return (this);
}

void OmBufferVector_for_each(OmBufferVector *this,
            void (* func)(void *context, sfVertex elem, size_t idx),
            void *context)
{
    if (this == 0 || this->size == 0)
        return;
    for (size_t idx = 0; idx < this->size; idx++)
        func(context, this->data[idx], idx);
}

void *OmBufferVector_reduce(OmBufferVector *this,
        void *(* func)(void *context, void *acc, sfVertex elem, size_t idx),
        void *context, void *acc)
{
    if (this == 0)
        return (acc);
    for (size_t idx = 0; idx < this->size; idx++)
        acc = func(context, acc, this->data[idx], idx);
    return (acc);
}