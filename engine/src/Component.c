/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Component
*/

#include <stdlib.h>
#include "Component.h"

OmComponent *OmComponent_Create(void)
{
    return ((OmComponent *)malloc(sizeof(OmComponent)));
}

void OmComponent_Destroy(OmComponent *item, bool free_child)
{
    OmComponent *tmp = 0;

    item->Parent = 0;
    if (free_child && item->Child->size > 0) {
        while (item->Child->size > 0) {
            tmp = OmVectorS->remove(item->Child, 0);
            OmComponent_Destroy(tmp, free_child);
        }
    }
    OmVectorS->drop(item->Child);
}

OmComponent *OmComponent_Init(OmComponent *item, OmComponent *Parent, size_t Child_Capacity)
{
    item->Parent = Parent;
    item->Child = OmVectorS->with_capacity(Child_Capacity);
    return (item);
}

OmComponent *OmComponent_Add_Childs(OmComponent *item, OmComponent *Child)
{
    if (!Child)
        return (0);
    OmVectorS->push_back(item->Child, 1, Child);
    return (Child);
}

OmComponent *OmComponent_Remove_Child(OmComponent *item, size_t index)
{
    OmComponent *tmp = OmVectorS->remove(item->Child, index);

    return ((tmp) ? tmp : 0);
}

OmComponent *OmComponent_Get_Child(OmComponent *item, size_t index)
{
    OmComponent *tmp = OmVectorS->at(item->Child, index);

    return ((tmp) ? tmp : 0);
}

struct _OmComponent OmComponentS[1] =
{
    {
        OmComponent_Create,
        OmComponent_Destroy,
        OmComponent_Init,
        OmComponent_Add_Childs,
        OmComponent_Remove_Child,
        OmComponent_Get_Child
    }
};