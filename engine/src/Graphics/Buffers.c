/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Buffers
*/

#include "Graphics/Buffers.h"

void OmBuffer_Init_vArray(OmBuffer *handle, sfPrimitiveType Primitive)
{
    handle->vType = BUF_VARR;
    handle->vData.vArray = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(handle->vData.vArray, Primitive);
}

void OmBuffer_Init_vBuffer(OmBuffer *handle, sfPrimitiveType Primitive, sfVertexBufferUsage Usage)
{
    handle->vType = BUF_VBUF;
    handle->vData.vBuffer = sfVertexBuffer_create(0, Primitive, Usage);
}

void OmBuffer_Destroy(OmBuffer handle)
{
    if (handle.vType == BUF_UNUSED)
        return;
    else if (handle.vType == BUF_VARR)
        sfVertexArray_destroy(handle.vData.vArray);
    else
        sfVertexBuffer_destroy(handle.vData.vBuffer);
}

_OmBuffer OmBufferS[1] =
{
    {
        OmBuffer_Init_vArray,
        OmBuffer_Init_vBuffer,
        OmBuffer_Destroy
    }
};