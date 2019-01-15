/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmTexture
*/

#include "core/renderer/OmTexture.h"

bool OmTexture_set(OmHashS *this, char *path)
{
    sfTexture *tmp;

    if (OmHash.get(this, path) != 0) {
        return (false);
    }
    tmp = sfTexture_createFromFile(path, NULL);
    if (tmp == 0)
        return (false);
    OmHash.set(this, path, tmp);
    return (true);
}

sfTexture *OmTexture_get(OmHashS *this, char *key)
{
    sfTexture *ret = OmHash.get(this, key);

    return (ret);
}

sfTexture *OmTexture_remove(OmHashS * this, char *key)
{
    sfTexture *ret = OmHash.remove(this, key);

    return (ret);
}

_OmTexture const OmTexture = {
    OmTexture_set,
    OmTexture_get,
    OmTexture_remove
};