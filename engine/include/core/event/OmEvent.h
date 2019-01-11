/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmEvent
*/

#pragma once

#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include "core/OmWindow.h"

typedef struct OmEventS {
    void *data;
    void (* callback)(OmWindowS *window, sfEvent event, void *data);
} OmEventS;

struct OmEvent_Storage {
    OmEventS data[sfEvtCount][sfKeyCount];
};

void OmEvent_Closed(OmWindowS *, sfEvent, struct OmEvent_Storage *);
void OmEvent_Resized(OmWindowS *, sfEvent, struct OmEvent_Storage *);
void OmEvent_LostFocus(OmWindowS *, sfEvent, struct OmEvent_Storage *);
void OmEvent_GainFocus(OmWindowS *, sfEvent, struct OmEvent_Storage *);
void OmEvent_TextEntered(OmWindowS *, sfEvent, struct OmEvent_Storage *);
void OmEvent_KeyPressed(OmWindowS *, sfEvent, struct OmEvent_Storage *);
void OmEvent_KeyReleased(OmWindowS *, sfEvent, struct OmEvent_Storage *);
void OmEvent_MouseMove(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events);

void OmEvent_Processor(OmWindowS *main_window, sfEvent event, struct OmEvent_Storage *events);