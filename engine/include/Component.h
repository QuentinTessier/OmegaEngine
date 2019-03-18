/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmComponent
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "DataStruct/Vector.h"

typedef struct OmComponent {
    struct OmComponent *Parent;
    OmVector *Child;
    int Order;

    void (* Action)(struct OmComponent *item, int ActionID, void *ActionData);
    void (* Update)(struct OmComponent *item, float deltaSeconds, void *UpdateData);
    void (* UpdateChild)(struct OmComponent *item, float deltaSeconds, void *UpdateData);
    void (* OnEvent)(struct OmComponent *item, sfEvent event);
} OmComponent;

struct _OmComponent {
    OmComponent *(* const Create)(void);
    void (* const Destroy)(OmComponent *item, bool free_child);
    OmComponent *(* const Init)(OmComponent *item, OmComponent *Parent, int Order);
    OmComponent *(* const Append_Child)(OmComponent *item, OmComponent *Child);
    OmComponent *(* const Add_Child)(OmComponent *item, OmComponent *Child, size_t order);
    OmComponent *(* const Remove_Child)(OmComponent *item, size_t index);
    OmComponent *(* const Get_Child)(OmComponent *item, size_t index);
    OmComponent *(* const Order_Child)(OmComponent *item,
            int (* const predicate)(void *a, size_t idxa, void *b, size_t idxb));
};

extern struct _OmComponent OmComponentS[1];