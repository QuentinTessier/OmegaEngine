/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Drawable
*/

#pragma once

#include <SFML/Window/Event.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Shader.h>

typedef struct OmDrawable {
    char D_Visible;

    sfVector2f Position;
    sfVector2f Velocity;
    float Angle;

    sfShader *shader;

    unsigned int B_ID;

    // Overridable methods
    void (* Draw)(struct OmDrawable *);
    void (* OnUpdate)(struct OmDrawable *);
    void (* OnEvent)(struct OmDrawable *, sfEvent event);
} OmDrawable;

typedef struct {
    OmDrawable *(* const Create)();
    OmDrawable *(* const Init)();
} _OmDrawable;

extern _OmDrawable OmDrawableS[1];