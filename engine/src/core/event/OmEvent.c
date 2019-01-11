/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmEvent
*/

#include "core/event/OmEvent.h"

static void (* OmEventReader[sfEvtCount])(OmWindowS *window, sfEvent event, struct OmEvent_Storage *) = {
    OmEvent_Closed, OmEvent_Resized, OmEvent_LostFocus, OmEvent_GainFocus,
    OmEvent_TextEntered, OmEvent_KeyPressed, OmEvent_KeyReleased, NULL, NULL,
    NULL, NULL, OmEvent_MouseMove, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

void OmEvent_Processor(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    if (OmEventReader[event.type] != NULL)
        OmEventReader[event.type](main_window, event, events);
}

void OmEvent_Closed(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    (void)events;
    sfRenderWindow_close(main_window->window);
}

void OmEvent_Resized(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    OmEventS tmp = events->data[sfEvtResized][0];

    main_window->window_size.x = event.size.width;
    main_window->window_size.y = event.size.height;
    //((unsigned int *)tmp.data)[0] = event.size.width;
    //((unsigned int *)tmp.data)[1] = event.size.height;
}

void OmEvent_LostFocus(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    (void)events;
    (void)main_window;
    (void)event;
}

void OmEvent_GainFocus(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    (void)main_window;
    (void)events;
    (void)event;
}

void OmEvent_TextEntered(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    (void)main_window;
    (void)events;
    (void)event;
}

void OmEvent_KeyPressed(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    int EventType = sfEvtKeyPressed;
    OmEventS tmp = events->data[EventType][event.key.code];

    if (tmp.callback != 0)
        tmp.callback(main_window, event, tmp.data);
}

void OmEvent_KeyReleased(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    int EventType = sfEvtKeyReleased;
    OmEventS tmp = events->data[EventType][event.key.code];

    if (tmp.callback != 0)
        tmp.callback(main_window, event, tmp.data);
}

void OmEvent_MouseMove(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events)
{
    (void)events;

    main_window->mouse_position.x = event.mouseMove.x;
    main_window->mouse_position.y = event.mouseMove.y;
    if (events->data[sfEvtMouseMoved][0].callback != 0)
        events->data[sfEvtMouseMoved][0].callback(main_window, event, events);
}