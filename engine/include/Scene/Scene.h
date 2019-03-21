/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Scene
*/

#pragma once

#include "Component.h"

enum OmScene_Actions {
    OmActions_Draw
};

typedef struct OmScene {
    OmComponent Comp[1];

    sfView *camera;
    sfTransform Scene_Matrix;
} OmScene;

struct _OmScene {
    OmScene *(* const Create)(void);
    void (* const Destroy)(OmScene *item, bool free_child);
    OmScene *(* const Init)(OmScene *item, sfFloatRect region);
};