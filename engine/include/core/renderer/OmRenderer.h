/*
** EPITECH PROJECT, 2018
** OmegaEngine
** File description:
** renderer
*/

#pragma once

#include <sys/types.h>
#include "OmDrawable.h"

/*
**  The renderer is a pool of OmDrawables that a cleared every frame and updated inside the game logic
*/

typedef struct OmRendererS OmRendererS;

struct OmRendererS {
    int max;
    int top;
    OmDrawableS **data;
};

typedef struct {
    OmRendererS *(* const create)(size_t pool_size);
    void (* const destroy)(OmRendererS *handle);
    void (* const push)(OmRendererS *handle, OmDrawableS *data_ptr);
    void (* const insert)(OmRendererS *handle, int idx, OmDrawableS *ptr_data);
    void (* const clear)(OmRendererS *handle);
    void (* const draw)(OmRendererS *handle, sfRenderWindow *window);
} _OmRenderer;

extern _OmRenderer const OmRenderer;