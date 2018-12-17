/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_namespace
*/

#include "utility/hashmap.h"

/*
** Constructor
*/
OmHashmap *OmHash_new(void);
OmHashmap *OmHash_from_capicity(size_t capacity);
OmHashmap *OmHash_clone(OmHashmap *origin);
OmHashmap *OmHash_merge(OmHashmap *this, OmHashmap *other);

/*
** Destructor
*/
void OmHash_clear(OmHashmap *this, bool free_values);
void OmHash_drop(OmHashmap *this);

/*
** Property access
*/
OmVector *OmHash_keys(OmHashmap *this);
OmVector *OmHash_values(OmHashmap *this);
size_t OmHash_size(OmHashmap *this);

/*
** Value access
*/
void *OmHash_get(OmHashmap *this, char *key);
bool OmHash_set(OmHashmap *this, char *key, void *value);
void *OmHash_remove(OmHashmap *this, char *key);
bool OmHash_reserve(OmHashmap *this, size_t capacity);
void OmHash_shrink_to_fit(OmHashmap *this);

/*
** Iteration
*/
void OmHash_for_each(OmHashmap *this,
        void (*callback)(void *context, char *key, void *element),
        void *context);

OmHashHeader const OmHash = {
    OmHash_new,
    OmHash_from_capicity,
    OmHash_clone,
    OmHash_merge,
    OmHash_clear,
    OmHash_drop,
    OmHash_keys,
    OmHash_values,
    OmHash_size,
    OmHash_get,
    OmHash_set,
    OmHash_remove,
    OmHash_reserve,
    OmHash_shrink_to_fit,
    OmHash_for_each
};