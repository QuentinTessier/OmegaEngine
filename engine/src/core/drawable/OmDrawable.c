/*
** EPITECH PROJECT, 2018
** OmegaEngine
** File description:
** drawable
*/

#include <stdlib.h>
#include <string.h>
#include "core/renderer/OmDrawable.h"

OmDrawableS OmDrawable_new(sfPrimitiveType type)
{
    OmDrawableS new;

    new.vertices = 0;
    new.type = type;
    new.count = 0;
    new.offset = 0;
    return (new);
}

void OmDrawable_update_vertices(OmDrawableS *handle, unsigned int count, const sfVertex *array, unsigned int offset)
{
    handle->count = count;
    handle->offset = offset;
    handle->vertices = realloc(handle->vertices, sizeof(sfVertex) * count);
    memcpy(handle->vertices, array, sizeof(sfVertex) * count);
}

void OmDrawable_update_states(OmDrawableS *handle, sfShader *shader, sfTransform matrix, sfTexture *texture)
{
    handle->states.shader = shader;
    handle->states.blendMode = sfBlendAdd;
    handle->states.texture = texture;
    handle->states.transform = matrix;
}

OmDrawableS OmDrawable_ImportFromFile(const char *path);

_OmDrawable const OmDrawable = {
    OmDrawable_new,
    OmDrawable_update_vertices,
    OmDrawable_update_states,
    OmDrawable_ImportFromFile
};