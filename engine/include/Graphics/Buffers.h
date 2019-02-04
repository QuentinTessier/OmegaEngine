/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Buffers
*/

#pragma once

#include <SFML/Graphics/VertexBuffer.h>
#include <SFML/Graphics/VertexArray.h>
#include "Graphics/BufferVector.h"

enum OmBufferDataType {
    BUF_UNUSED = -1,
    BUF_VARR,
    BUF_VBUF
};

typedef union OmBufferData {
    sfVertexArray *vArray;
    sfVertexBuffer *vBuffer;
} OmBufferData;

typedef struct OmBuffer {
    int vType;

    OmBufferVector vVector[1];
    OmBufferData vData;
} OmBuffer;

typedef struct {
    void (* const Init_vArray)(OmBuffer *handle);
    void (* const Init_vBuffer)(OmBuffer *handle);
    void (* const Destroy)(OmBuffer handle);
} _OmBuffer;

extern _OmBuffer OmBufferS[1];