/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** DrawData
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "Graphics/DrawData.h"

OmDrawData *OmDrawData_Create(void)
{
    return (calloc(sizeof(OmDrawData), 1));
}

void OmDrawData_Init(OmDrawData *item, OmComponent *Parent)
{
    OmComponentS->Init(item->Comp, Parent, 0);
    item->Matrix = sfTransform_Identity;
}

_OmDrawData OmDrawDataS[1] =
{
    {
        OmDrawData_Create,
        OmDrawData_Init
    }
};