/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_iterate
*/

#include "DataStruct/Vector.h"

void OmVector_map(OmVector *this,
            void *(* func)(void *context, void *elem, size_t idx),
            void *context)
{
    if (this == 0)
        return;
    for (size_t idx = 0; idx < this->size; idx++)
        this->data[idx] = func(context, this->data[idx], idx);
}

OmVector *OmVector_filter(OmVector *this,
                    bool (* predicate)(void *context, void *elem, size_t idx),
                    void *context)
{
    if (this == 0 || this->size == 0)
        return (0);
    for (ssize_t idx = ((ssize_t)(this->size)) - 1; idx >= 0; idx--)
        if (predicate(context, this->data[idx], idx) == false)
            OmVectorS->Remove(this, idx);
    return (this);
}

bool OmVector_sort_helper(OmVector *this,
            int (* predicate)(void *, size_t, void*, size_t))
{
    bool done = true;
    void *tmp = 0;
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

OmVector *OmVector_sort(OmVector *this,
        int (* predicate)(void *elem1, size_t idx1, void *elem2, size_t idx2))
{
    if (this == 0 || this->size == 0)
        return (0);
    while (OmVector_sort_helper(this, predicate) == false);
    return (this);
}

void OmVector_for_each(OmVector *this,
            void (* func)(void *context, void *elem, size_t idx),
            void *context)
{
    if (this == 0 || this->size == 0)
        return;
    for (size_t idx = 0; idx < this->size; idx++)
        func(context, this->data[idx], idx);
}

void *OmVector_reduce(OmVector *this,
        void *(* func)(void *context, void *acc, void *elem, size_t idx),
        void *context, void *acc)
{
    if (this == 0)
        return (acc);
    for (size_t idx = 0; idx < this->size; idx++)
        acc = func(context, acc, this->data[idx], idx);
    return (acc);
}