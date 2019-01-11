/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_destruct
*/

#include "data_structure/OmVector.h"
#include "data_structure/OmHash.h"

void OmHash_clear(OmHashS *this, bool free_values)
{
    OmVector.clear(this->keys, free_values);
    OmVector.clear(this->data, free_values);
}

void OmHash_drop(OmHashS *this)
{
    OmVector.drop(this->keys);
    OmVector.drop(this->data);
}