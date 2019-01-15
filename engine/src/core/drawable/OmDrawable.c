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
    new.states.blendMode = sfBlendAlpha;
    new.states.shader = 0;
    new.states.texture = 0;
    new.states.transform = sfTransform_Identity;
    new.parser_infos = 0;
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

void OmDrawable_move(OmDrawableS *handle, sfVector2f offset)
{
    for (unsigned int i = 0; i <= handle->count; i++) {
        handle->vertices[i].position.x += offset.x;
        handle->vertices[i].position.y += offset.y;
    }
}

void OmDrawable_TexMove(OmDrawableS *handle, sfVector2f offset)
{
    for (unsigned int i = 0; i <= handle->count; i++) {
        handle->vertices[i].texCoords.x += offset.x;
        handle->vertices[i].texCoords.y += offset.y;
    }
}

OmDrawableS OmDrawable_ImportFromFile(const char *path, const char *object_name, OmHashS *textures);

_OmDrawable const OmDrawable = {
    OmDrawable_new,
    OmDrawable_update_vertices,
    OmDrawable_update_states,
    OmDrawable_ImportFromFile,
    OmDrawable_move,
    OmDrawable_TexMove
};