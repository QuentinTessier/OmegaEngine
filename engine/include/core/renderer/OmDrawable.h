/*
** EPITECH PROJECT, 2018
** OmegaEngine
** File description:
** base_object
*/

#pragma once

#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/RenderWindow.h>

/*
**  Contain drawable data for the renderer
*/

typedef struct OmDrawableS {
    sfVertex *vertices;
    sfRenderStates states;
} OmDrawableS;

/*
**  This struct contain every functions needed by a OmDrawableS item
*/

typedef struct OmDrawable {
    OmDrawableS *(* const create)(void *data,
        void (* const draw)(sfRenderWindow *window, OmDrawableS *elem, sfRenderStates *state),
        void (* const destroy)(OmDrawableS *item));
    void (* const destroy)(OmDrawableS *handle);
} _OmDrawable;

extern _OmDrawable const OmDrawable;