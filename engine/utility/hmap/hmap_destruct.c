/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_destruct
*/

#include "utility/hashmap.h"

void OmHash_clear(OmHashmap *this, bool free_values)
{
    OmVec_clear(this->keys, free_values);
    OmVec_clear(this->data, free_values);
}

void OmHash_drop(OmHashmap *this)
{
    OmVec_drop(this->keys);
    OmVec_drop(this->data);
}