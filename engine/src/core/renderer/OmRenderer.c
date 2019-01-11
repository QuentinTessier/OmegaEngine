/*
** EPITECH PROJECT, 2018
** OmegaEngine
** File description:
** renderer
*/

#include <stdlib.h>
#include <string.h>
#include "core/renderer/OmRenderer.h"

OmRendererS *OmRenderer_create(size_t renderer_size)
{
    OmRendererS *new = malloc(sizeof(OmRendererS));

    if (new == 0)
        return (0);
    new->top = -1;
    new->max = renderer_size;
    new->data = malloc(sizeof(OmDrawableS) * new->max);
    new->buffer = sfVertexBuffer_create(0, sfTriangles, sfVertexBufferDynamic);
    if (new->data == 0 || new->buffer == 0) {
        free(new);
        return (0);
    }
    return (new);
}

void OmRenderer_destroy(OmRendererS *handle)
{
    free(handle->data);
    free(handle);
}

void OmRenderer_push(OmRendererS *handle, OmDrawableS item)
{
    if (handle->top >= handle->max - 1)
        return;
    handle->top += 1;
    handle->data[handle->top] = item;
}

void OmRenderer_insert(OmRendererS *handle, int idx, OmDrawableS item)
{
    if (idx < 0)
        return;
    if (handle->top >= handle->max - 1)
        return;
    if (handle->top == -1 || handle->top < idx) {
        OmRenderer_push(handle, item);
        return;
    }
    memmove(handle->data + idx + 1, handle->data + idx, (handle->top - idx + 1) * sizeof(OmDrawableS));
    handle->data[idx] = item;
    handle->top++;
}

void OmRenderer_clear(OmRendererS *handle)
{
    handle->top = -1;
}

void OmRenderer_draw(OmRendererS *handle, sfRenderWindow *window)
{
    OmDrawableS tmp;
    int i = 0;

    while (i <= handle->top) {
        tmp = handle->data[i];
        sfVertexBuffer_setPrimitiveType(handle->buffer, tmp.type);
        sfVertexBuffer_update(handle->buffer, tmp.vertices, tmp.count, tmp.offset);
        sfRenderWindow_drawVertexBuffer(window, handle->buffer, &tmp.states);
        i++;
    }
    OmRenderer_clear(handle);
}

_OmRenderer const OmRenderer = {
    OmRenderer_create,
    OmRenderer_destroy,
    OmRenderer_push,
    OmRenderer_insert,
    OmRenderer_clear,
    OmRenderer_draw
};