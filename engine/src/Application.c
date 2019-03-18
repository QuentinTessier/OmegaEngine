/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Application
*/

#include <SFML/Window/VideoMode.h>
#include "Window.h"
#include "Application.h"

#include "DataStruct/Vector.h"
#include "Callbacks.h"

void OmApp_destroy(struct OmApp *App)
{
    sfRenderWindow_destroy(App->AppWindow->Window);
    sfClock_destroy(App->AppWindow->Time);
    OmComponentS->Destroy(App->Comp, true);
    return;
}

int OmApp_run(struct OmApp *App)
{
    App->CreateHierarchy(App);
    return (OmApp_GameLoop(App));
}

OmApp OmApp_new(void)
{
    OmApp new;

    new.Comp->Child = 0;
    new.Destroy = OmApp_destroy;
    new.Run = OmApp_run;
    new.CreateWindow = OmApp_CreateWindow;
    new.CreateHierarchy = OmApp_CreateHierarchy;
    return (new);
}

double OmApp_GetTime(OmApp *App, int TimeUnit)
{
    sfTime tmp = sfClock_getElapsedTime(App->AppWindow->Time);

    if (TimeUnit == As_Seconds)
        return (sfTime_asSeconds(tmp));
    else if (TimeUnit == As_MilliSeconds)
        return (sfTime_asMilliseconds(tmp));
    else
        return (sfTime_asMicroseconds(tmp));
}

_OmApp OmAppS[1] = {
    {
        OmApp_GetTime
    }
};