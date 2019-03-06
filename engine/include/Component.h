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

enum OmActionID {

};

typedef struct OmComponent {
    struct OmComponent *Parent;
    OmVector *Child;

    void (* Action)(struct OmComponent, enum OmActionID ID, void *ActionData);
    void (* Update)(struct OmComponent *item, float deltaSeconds);
    void (* UpdateChild)(struct OmComponent *item, float deltaSeconds);
    void (* OnEvent)(struct OmComponent *item, sfEvent event, int Stop);
} OmComponent;

struct _OmComponent {
    OmComponent *(* const Create)(void);
    void (* const Destroy)(OmComponent *item, bool free_child);
    OmComponent *(* const Init)(OmComponent *item, OmComponent *Parent, size_t Child_Capacity);
    OmComponent *(* const Add_Child)(OmComponent *item, OmComponent *Child);
    OmComponent *(* const Remove_Child)(OmComponent *item, size_t index);
    OmComponent *(* const Get_Child)(OmComponent *item, size_t index);
};

extern struct _OmComponent OmComponentS[1];