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
    OmComponentS->Init(item->Comp, Parent);
    item->Matrix = sfTransform_Identity;
}

sfTransform OmDrawData_CreateFrameMatrix(OmDrawData *item, float DeltaTime)
{
    sfVector2f move = {0.f, 0.f};
    sfTransform translation = sfTransform_Identity;
    sfTransform rotation = sfTransform_Identity;

    move.x = DeltaTime * item->Velocity.x;
    move.y = DeltaTime * item->Velocity.y;
    sfTransform_translate(&translation, move.x, move.y);
    if (item->Angle)
        sfTransform_rotate(&rotation, item->Angle);
    sfTransform_combine(&translation, &rotation);
    return (translation);
}

_OmDrawData OmDrawDataS[1] =
{
    {
        OmDrawData_Create,
        OmDrawData_Init
    }
};