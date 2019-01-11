/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_iterate
*/

#include "data_structure/OmHash.h"

void OmHash_for_each(OmHashS *this,
        void (*callback)(void *context, char *key, void *element),
        void *context)
{
    if (this == 0 || callback == 0)
        return;
    for (size_t idx = 0; idx < this->size; idx++)
        callback(context, this->keys->arr[idx], this->data->arr[idx]);
}