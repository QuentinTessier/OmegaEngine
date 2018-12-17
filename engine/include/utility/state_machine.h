/*
** EPITECH PROJECT, 2018
** CSFML_2D_RENDERER
** File description:
** state_machine
*/

#pragma once

#include <sys/types.h>

typedef struct OmStateMachineS {
    size_t max;
    ssize_t top;
    int *data;
} OmStateMachineS;

typedef struct OmStateMachine {
    OmStateMachineS *(* const create)(size_t stack_size);
    void (* const destroy)(OmStateMachineS *handle);
    void (* const push)(OmStateMachineS *handle, int state);
    int (* const pop)(OmStateMachineS *handle);
    int (* const fetch_top)(OmStateMachineS *handle);
} _OmStateMachine;

extern _OmStateMachine const OmStateMachine;