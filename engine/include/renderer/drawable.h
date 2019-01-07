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
    void *data;                                                                                 // The actual data created by the dev
    sfRenderStates *state;                                                                      // SFML sfRenderState for Vertex Arrays/Buffers, Shaders and Transforms

    void (* draw)(sfRenderWindow *window, struct OmDrawableS *elem, sfRenderStates *state);     // Specific Draw callback for this item
    void (* destroy)(struct OmDrawableS *item);                                                 // Specific Destroy callback for this item
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