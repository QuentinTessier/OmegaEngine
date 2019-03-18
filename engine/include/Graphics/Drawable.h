/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Drawable
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "Component.h"

typedef struct OmDrawData {
    OmComponent Comp[1];

    bool isVisible;             // Tell if the item need to be rendered

    sfVector2f Velocity;        // Move update at every frames (time based)
    float Angle;                // Angle value for next rotation

    void (* Draw)(struct OmDrawData *item, sfRenderWindow *Window, sfTransform *World_Matrix);
} OmDrawable;