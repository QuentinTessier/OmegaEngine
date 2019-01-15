/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmTexture
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics/Texture.h>
#include "data_structure/OmHash.h"

typedef struct {
    bool (* const set)(OmHashS *this, char *path);
    sfTexture *(* const get)(OmHashS *this, char *key);
    sfTexture *(* const remove)(OmHashS *this, char *key);
} _OmTexture;

extern _OmTexture const OmTexture;