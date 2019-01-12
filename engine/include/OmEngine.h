/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmEngine
*/

#pragma once

#ifndef BASE_HASH_SIZE
    #define BASE_HASH_SIZE 256
#endif

#include <stdio.h>

#include "core/event/OmEvent.h"
#include "core/OmWindow.h"

typedef struct OmHashS OmHashS;

OmWindowS OmEngine_Init(void);
void OmEngine_InitData(OmWindowS *main_window, OmHashS *hash);
struct OmEvent_Storage OmEngine_InitEvent(void);

/* To delete */
void Update_object(OmDrawableS object);
