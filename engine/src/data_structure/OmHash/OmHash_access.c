/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_access
*/

#include "data_structure/OmHash.h"

OmVectorS *OmHash_keys(OmHashS *this)
{
    return ((this) ? this->keys : 0);
}

OmVectorS *OmHash_values(OmHashS *this)
{
    return ((this) ? this->data : 0);
}

size_t OmHash_size(OmHashS *this)
{
    return ((this) ? this->size : 0);
}