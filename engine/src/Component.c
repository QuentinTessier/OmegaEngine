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
    if (item->Child == 0)
        return;
    if (free_child && item->Child->size > 0) {
        while (item->Child->size > 0) {
            tmp = OmVectorS->Remove(item->Child, 0);
            OmComponent_Destroy(tmp, free_child);
        }
    }
    OmVectorS->Drop(item->Child);
}


void OmComponent_OnEvent(OmComponent *item, sfEvent event)
{
    for (size_t i = 0; i < item->Child->size; i++) {
        ((OmComponent *)(item->Child->data[i]))->OnEvent(item->Child->data[i], event);
    }
}

OmComponent *OmComponent_Init(OmComponent *item, OmComponent *Parent, int Order)
{
    item->Parent = Parent;
    item->Child = OmVectorS->With_Capacity(1);
    item->OnEvent = OmComponent_OnEvent;
    item->Order = Order;
    return (item);
}

OmComponent *OmComponent_Append_Child(OmComponent *item, OmComponent *Child)
{
    if (!Child)
        return (0);
    OmVectorS->Push_back(item->Child, 1, Child);
    return (Child);
}

OmComponent *OmComponent_Add_Child(OmComponent *item, OmComponent *Child, size_t order)
{
    if (!Child)
        return (0);
    if (OmVectorS->Set(item->Child, order, Child))
        return (Child);
    else
        return (0);
}

OmComponent *OmComponent_Remove_Child(OmComponent *item, size_t index)
{
    OmComponent *tmp = OmVectorS->Remove(item->Child, index);

    return ((tmp) ? tmp : 0);
}

OmComponent *OmComponent_Get_Child(OmComponent *item, size_t index)
{
    OmComponent *tmp = OmVectorS->At(item->Child, index);

    return ((tmp) ? tmp : 0);
}

int OmComponent_Sorter(void *a, size_t idx1, void *b, size_t idx2)
{
    OmComponent *a1 = a;
    OmComponent *b1 = b;

    (void)idx1;
    (void)idx2;
    if (a1->Order < b1->Order)
        return (1);
    else
        return (0);
}

OmComponent *OmComponent_Order_Child(OmComponent *item,
        int (* const predicate)(void *a, size_t idx1, void *b, size_t idx2))
{
    if (predicate == 0) {
        OmVectorS->Sort(item->Child, OmComponent_Sorter);
    } else {
        OmVectorS->Sort(item->Child, predicate);
    }
    return (item);
}

struct _OmComponent OmComponentS[1] =
{
    {
        OmComponent_Create,
        OmComponent_Destroy,
        OmComponent_Init,
        OmComponent_Append_Child,
        OmComponent_Add_Child,
        OmComponent_Remove_Child,
        OmComponent_Get_Child,
        OmComponent_Order_Child
    }
};