/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Application
*/

#pragma once

#include "Window.h"

typedef struct OmApp {
    OmWindow AppWindow[1];

    void (* Destroy)(struct OmApp *);
    void (* Run)(struct OmApp *);
    void (* CreateWindow)(struct OmApp *);
} OmApp;

OmApp OmApp_new(void);