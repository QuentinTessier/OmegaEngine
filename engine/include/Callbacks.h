/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Callbacks
*/

#pragma once

#include "Application.h"

extern void (* OmApp_CreateWindow)(struct OmApp *App);
extern int (* OmApp_CreateHierarchy)(struct OmApp *App);
extern int (* OmApp_DestroyHierarchy)(struct OmComponent *Comp);