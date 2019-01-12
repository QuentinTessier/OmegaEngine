/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmTexture
*/

#include "core/renderer/OmTexture.h"

bool OmTexture_set(OmHashS *this, char *key, const char *path)
{
    if (OmHash.get(this, key) != 0)
        return (false);
    OmHash.set(this, key, sfTexture_createFromFile(path, NULL));
    return (true);
}

sfTexture *OmTexture_get(OmHashS *this, const char *key)
{
    sfTexture *ret = OmHash.get(this, key);

    return (ret);
}

sfTexture *OmTexture_remove(OmHashS * this, const char *key)
{
    sfTexture *ret = OmHash.remove(this, key);

    return (ret);
}

_OmTexture const OmTexture = {
    OmTexture_set,
    OmTexture_get,
    OmTexture_remove
};