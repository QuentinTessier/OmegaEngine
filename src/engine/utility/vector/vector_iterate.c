/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** vector_iterate
*/

#include "engine/utility/vector.h"

void OmVec_map(OmVector *this,
        void *(*func)(void *context, void *elem, size_t idx),
        void *context)
{
    if (this == 0)
        return;
    for (size_t idx = 0; idx < this->size; idx++)
        this->arr[idx] = func(context, this->arr[idx], idx);
}

OmVector *OmVec_filter(OmVector *this,
        void *(*predicate)(void *context, void *elem, size_t idx),
        void *context)
{
    if (this == NULL || this->size == 0)
        return (NULL);
    for (ssize_t idx = ((ssize_t)(this->size)) - 1; idx >= 0; idx--)
        if (predicate(context, this->arr[idx], idx) == false)
            OmVec_remove(this, idx);
    return (this);
}

bool OmVec_sort_helper(OmVector *this,
        int (*predicate)(void *, size_t, void *, size_t))
{
    bool done = true;
    void *tmp;
    size_t before_l = this->size - 1;

    for (size_t idx = 0; idx < before_l; idx++)
        if (predicate(this->arr[idx], idx, this->arr[idx + 1], idx + 1) > 0) {
            done = false;
            tmp = this->arr[idx];
            this->arr[idx] = this->arr[idx + 1];
            this->arr[idx + 1] = tmp;
        }
    return (done);
}

OmVector *OmVec_sort(OmVector *this,
        int (*predicate)(void *a, size_t idx1, void *b, size_t idx))
{
    if (this == NULL || this->size == 0)
        return (NULL);
    while (OmVec_sort_helper(this, predicate) == false);
    return (this);
}

void OmVec_for_each(OmVector *this,
        int (*func)(void *context, void *elem, size_t idx), void *context)
{
    if (this == 0 || this->size == 0)
        return;
    for (size_t idx = 0; idx < this->size; idx++)
        func(context, this->arr[idx], idx);
}

void *OmVec_reduce(OmVector *this,
        void *(*func)(void *context, void *acc, void *elem, size_t idx),
        void *context, void *acc)
{
    if (this == 0)
        return (acc);
    for (size_t idx = 0; idx < this->size; idx++)
        acc = func(context, acc, this->arr[idx], idx);
    return (acc);
}