/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmWindow
*/

#pragma once

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Clock.h>
#include "renderer/renderer.h"

typedef struct OmWindowS {
    sfRenderWindow *window;
    sfVector2u window_size;
    sfUint32 window_style;

    sfClock *clock;
    float renderer_frequency;
    OmRendererS *renderer;
} OmWindowS;