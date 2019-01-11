/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** hmap_namescape
*/

#include "data_structure/OmVector.h"
#include "data_structure/OmHash.h"

/*
** Constructor
*/
OmHashS *OmHash_new(void);
OmHashS *OmHash_from_capacity(size_t capacity);
OmHashS *OmHash_clone(OmHashS *origin);
OmHashS *OmHash_merge(OmHashS *this, OmHashS *other);

/*
** Destructor
*/
void OmHash_clear(OmHashS *this, bool free_values);
void OmHash_drop(OmHashS *this);

/*
** Property access
*/
OmVectorS *OmHash_keys(OmHashS *this);
OmVectorS *OmHash_values(OmHashS *this);
size_t OmHash_size(OmHashS *this);

/*
** Value access
*/
void *OmHash_get(OmHashS *this, char *key);
bool OmHash_set(OmHashS *this, char *key, void *value);
void *OmHash_remove(OmHashS *this, char *key);
bool OmHash_reserve(OmHashS *this, size_t capacity);
void OmHash_shrink_to_fit(OmHashS *this);

/*
** Iteration
*/
void OmHash_for_each(OmHashS *this,
        void (*callback)(void *context, char *key, void *element),
        void *context);

_OmHash const OmHash = {
    OmHash_new,
    OmHash_from_capacity,
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