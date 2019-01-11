/*
** EPITECH PROJECT, 2018
** OmegaEngine
** File description:
** drawable
*/

#include <stdlib.h>
#include "core/renderer/OmDrawable.h"

/*OmDrawableS *OmDrawable_create(void *data,
    void (* const draw)(sfRenderWindow *window, OmDrawableS *elem, sfRenderStates *state),
    void (* const destroy)(OmDrawableS *item))
{
    OmDrawableS *new = malloc(sizeof(OmDrawableS));

    if (new == 0)
        return (0);
    new->data = data;
    new->state = NULL;
    new->destroy = destroy;
    new->draw = draw;
    return (new);
}

void OmDrawable_destroy(OmDrawableS *handle)
{
    handle->destroy(handle);
    free(handle);
}

_OmDrawable const OmDrawable = {
    OmDrawable_create,
    OmDrawable_destroy
};*/