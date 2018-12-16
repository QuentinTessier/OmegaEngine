/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_access
*/

#include "engine/utility/hashmap.h"

OmVector *OmHash_keys(OmHashmap *this)
{
    return ((this) ? this->keys : 0);
}

OmVector *OmHash_values(OmHashmap *this)
{
    return ((this) ? this->data : 0);
}

size_t OmHash_size(OmHashmap *this)
{
    return ((this) ? this->size : 0);
}