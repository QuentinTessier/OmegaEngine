/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Application
*/

#pragma once

#include "Window.h"
#include "Component.h"

enum TimeUnits {
    As_Seconds,
    As_MilliSeconds,
    As_MicroSeconds
};

typedef struct OmApp {
    OmWindow AppWindow[1];
    OmComponent Comp[1];

    void (* Destroy)(struct OmApp *);
    int (* Run)(struct OmApp *);
    void (* CreateWindow)(struct OmApp *);
    int (* CreateHierarchy)(struct OmApp *);
} OmApp;

typedef struct {
    double (* const GetTime)(OmApp *App, int TimeUnit);
} _OmApp;

extern _OmApp OmAppS[1];

OmApp OmApp_new(void);