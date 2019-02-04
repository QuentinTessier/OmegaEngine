/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Application
*/

#include <SFML/Window/VideoMode.h>
#include "Window.h"
#include "Application.h"
#include "Graphics/BufferPool.h"

#include "DataStruct/Vector.h"

#define MS_PER_UPDATE 16.0f

void OmApp_destroy(struct OmApp *App)
{
    sfRenderWindow_destroy(App->AppWindow->Window);
    sfClock_destroy(App->AppWindow->Time);
    return;
}

void update_vertexbuffer(sfVertexBuffer *buffer, OmVector *vector)
{

}

void OmApp_run(struct OmApp *App)
{
    sfEvent event;
    float lag = 0;
    float previous = sfTime_asMilliseconds(sfClock_getElapsedTime(App->AppWindow->Time));
    float current = 0;
    float elapsed = 0;

    while (sfRenderWindow_isOpen(App->AppWindow->Window)) {
        current = sfTime_asMilliseconds(sfClock_getElapsedTime(App->AppWindow->Time));
        elapsed = current - previous;
        previous = current;
        lag += elapsed;
        while (sfRenderWindow_pollEvent(App->AppWindow->Window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(App->AppWindow->Window);
        }
        while (lag >= MS_PER_UPDATE) {
            lag -= MS_PER_UPDATE;
        }
        sfRenderWindow_clear(App->AppWindow->Window, sfBlack);
        sfRenderWindow_display(App->AppWindow->Window);
    }
    return;
}

void OmApp_create_window(struct OmApp *App)
{
    App->AppWindow->Window = sfRenderWindow_create((sfVideoMode){1280, 768, 32}, "NAME", sfClose, 0);
    App->AppWindow->Time = sfClock_create();
}

OmApp OmApp_new(void)
{
    OmApp new;

    new.Destroy = OmApp_destroy;
    new.Run = OmApp_run;
    new.CreateWindow = OmApp_create_window;
    return (new);
}