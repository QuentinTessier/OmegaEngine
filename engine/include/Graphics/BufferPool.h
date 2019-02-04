/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** BufferPool
*/

#pragma once

#include "Buffers.h"

#define POOL_SIZE 32

typedef struct OmBufferPool {
    unsigned int count;

    OmBuffer *data;
} OmBufferPool;

OmBufferPool B_Pool[1];

typedef struct {
    void (* const Init)();
    void (* const Destroy)();
    unsigned int (* const Add)(OmBuffer buffer);
    void (* const Remove)(unsigned int ID);
    OmBuffer (* const Get)(unsigned int ID);
} _OmBufferPool;

extern _OmBufferPool OmBufferPoolS[1];