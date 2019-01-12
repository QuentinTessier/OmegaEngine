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
    bool (* const set)(OmHashS *this, char *key, const char *path);
    sfTexture *(* const get)(OmHashS *this, const char *key);
    sfTexture *(* const remove)(OmHashS *this, const char *key);
} _OmTexture;

extern _OmTexture const OmTexture;