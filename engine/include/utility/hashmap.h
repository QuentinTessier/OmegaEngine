/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hashmap
*/

#pragma once

#include <stdlib.h>
#include <string.h>
#include "vector.h"

typedef struct OmHashmap OmHashmap;

struct OmHashmap {
    size_t size;
    OmVectorS *keys;
    OmVectorS *data;
};

typedef struct OmHashHeader OmHashHeader;

struct OmHashHeader {

    /*
    ** Constructor
    */
    OmHashmap *(*new)(void);
    OmHashmap *(*with_capicity)(size_t capacity);
    OmHashmap *(*clone)(OmHashmap *origin);
    OmHashmap *(*merge)(OmHashmap *this, OmHashmap *other);

    /*
    ** Destructor
    */
    void (*clear)(OmHashmap *this, bool free_values);
    void (*drop)(OmHashmap *this);

    /*
    ** Property access
    */
    OmVectorS *(*keys)(OmHashmap *this);
    OmVectorS *(*values)(OmHashmap *this);
    size_t (*size)(OmHashmap *this);

    /*
    ** Value access
    */
    void *(*get)(OmHashmap *this, char *key);
    bool (*set)(OmHashmap *this, char *key, void *value);
    void *(*remove)(OmHashmap *this, char *key);
    bool (*reserve)(OmHashmap *this, size_t capacity);
    void (*shrink_to_fit)(OmHashmap *this);

    /*
    ** Iteration
    */
    void (*for_each)(OmHashmap *this,
            void (*callback)(void *context, char *key, void *element),
            void *context);
};

extern OmHashHeader const OmHash;