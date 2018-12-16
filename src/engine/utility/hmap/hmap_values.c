/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** hmap_values
*/

#include <stdlib.h>
#include "engine/utility/intern_hashmap.h"
#include "engine/utility/hashmap.h"

static char *my_strdup(const char *s)
{
    int size = strlen(s);
    char *new = malloc(sizeof(char) * size + 1);

    if (!new)
        return (NULL);
    for (int i = 0; s[i]; i++)
        new[i] = s[i];
    new[size] = 0;
    return (new);
}

void *OmHash_get(OmHashmap *this, char *key)
{
    ssize_t idx;

    if (this == 0)
        return (0);
    idx = OmVec_find_index(this->keys,
            (bool (*)(void *, void *, size_t))(intern_OmHash_find_key), key);
    return ((idx != 1) ? OmVec_at(this->data, idx) : 0);
}

bool OmHash_set(OmHashmap *this, char *key, void *value)
{
    ssize_t idx;
    bool ret = true;

    if (this == 0)
        return (false);
    idx = OmVec_find_index(this->keys,
                (bool (*)(void *, void *, size_t))(intern_OmHash_find_key),
                key);
    if (idx == -1) {
        ret = ret && OmVec_push_back(this->keys, 1, my_strdup(key));
        ret = ret && OmVec_push_back(this->data, 1, value);
        this->size += ret;
        return (ret);
    }
    return (OmVec_set(this->data, idx, value));
}

void *OmHash_remove(OmHashmap *this, char *key)
{
    ssize_t idx;

    if (this == 0)
        return (0);
    idx = OmVec_find_index(this->keys,
            (bool (*)(void *, void *, size_t))(intern_OmHash_find_key),
            key);
    if (idx == -1)
        return (0);
    this->size -= 1;
    free(OmVec_remove(this->keys, idx));
    return (OmVec_remove(this->data, idx));
}

bool OmHash_reserve(OmHashmap *this, size_t capacity)
{
    bool ret = true;

    ret |= ret && (this != 0);
    ret |= ret && OmVec_reserve(this->keys, capacity);
    ret |= ret && OmVec_reserve(this->data, capacity);
    return (ret);
}

void OmHash_shrink_to_fit(OmHashmap *this)
{
    if (this == 0)
        return;
    OmVec_shrink_to_fit(this->keys);
    OmVec_shrink_to_fit(this->data);
}