/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** data_container
*/

#pragma once

#include <sys/types.h>

typedef struct OmObject OmObject;

struct OmObject {
    int type;
    char *name;
    void *data;
};

typedef struct OmObjectContainer {
    size_t size;
    size_t offset;
    OmObject *data_array;
} OmObjectContainer;

typedef struct {
    OmObjectContainer *(* const create)(size_t size);
    OmObject *(* const add)(OmObjectContainer *handle, const char *name, int type, void *data);
    OmObject *(* const get)(OmObjectContainer *handle, const char *name);
    void (* const destroy)(OmObjectContainer *handle);
} _OmObjectContainer;

extern _OmObjectContainer const OmObjectCont;