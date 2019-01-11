/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hashmap
*/

#pragma once

#include <stdlib.h>
#include <string.h>
#include "OmVector.h"

typedef struct OmHashS OmHashS;

struct OmHashS {
    size_t size;
    OmVectorS *keys;
    OmVectorS *data;
};

typedef struct {

    /*
    ** Constructor
    */
    OmHashS *(*new)(void);
    OmHashS *(*with_capacity)(size_t capacity);
    OmHashS *(*clone)(OmHashS *origin);
    OmHashS *(*merge)(OmHashS *this, OmHashS *other);

    /*
    ** Destructor
    */
    void (*clear)(OmHashS *this, bool free_values);
    void (*drop)(OmHashS *this);

    /*
    ** Property access
    */
    OmVectorS *(*keys)(OmHashS *this);
    OmVectorS *(*values)(OmHashS *this);
    size_t (*size)(OmHashS *this);

    /*
    ** Value access
    */
    void *(*get)(OmHashS *this, char *key);
    bool (*set)(OmHashS *this, char *key, void *value);
    void *(*remove)(OmHashS *this, char *key);
    bool (*reserve)(OmHashS *this, size_t capacity);
    void (*shrink_to_fit)(OmHashS *this);

    /*
    ** Iteration
    */
    void (*for_each)(OmHashS *this,
            void (*callback)(void *context, char *key, void *element),
            void *context);
} _OmHash;

extern _OmHash const OmHash;