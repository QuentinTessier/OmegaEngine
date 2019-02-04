/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Buffers
*/

#include <stdlib.h>
#include <sys/types.h>
#include "Graphics/BufferPool.h"

void OmBufferPool_Init(void)
{
    B_Pool->data = malloc(sizeof(OmBuffer) * POOL_SIZE);
    B_Pool->count = POOL_SIZE;

    for (unsigned int i = 0; i < B_Pool->count; i++) {
        B_Pool->data[i].vType = BUF_UNUSED;
    }
}

void OmBufferPool_Destroy(void)
{
    for (unsigned int i = 0; i < B_Pool->count; i++) {
        OmBufferS->Destroy(B_Pool->data[i]);
    }
    free(B_Pool->data);
}

unsigned int OmBufferPool_Add(OmBuffer buffer)
{
    unsigned int idx = B_Pool->count + 1;

    for (unsigned int i = 0; i < B_Pool->count; i++) {
        if (B_Pool->data[i].vType == BUF_UNUSED) {
            idx = i;
            break;
        }
    }
    if (idx == B_Pool->count + 1)
        return (idx);
    B_Pool->data[idx] = buffer;
    return (idx);
}

void OmBufferPool_Remove(unsigned int ID)
{
    if (ID > B_Pool->count)
        return;
    if (B_Pool->data[ID].vType == BUF_UNUSED)
        return;
    else if (B_Pool->data[ID].vType == BUF_VARR)
        sfVertexArray_destroy(B_Pool->data[ID].vData.vArray);
    else
        sfVertexBuffer_destroy(B_Pool->data[ID].vData.vBuffer);
    B_Pool->data[ID].vType = BUF_UNUSED;
}

OmBuffer OmBufferPool_Get(unsigned int ID)
{
    if (ID > B_Pool->count)
        return;
    return (B_Pool->data[ID]);
}

_OmBufferPool OmBufferPoolS[1] =
{
    {
        OmBufferPool_Init,
        OmBufferPool_Destroy,
        OmBufferPool_Add,
        OmBufferPool_Remove,
        OmBufferPool_Get
    }
};