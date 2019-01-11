/*
** EPITECH PROJECT, 2018
** CSFML_2D_RENDERER
** File description:
** state_machine
*/

#include <stdlib.h>
#include "data_structure/OmStateMachine.h"

OmStateMachineS *OmStateMachine_create(size_t stack_size)
{
    OmStateMachineS *new = malloc(sizeof(OmStateMachineS));

    if (!new)
        return (0);
    new->max = stack_size;
    new->top = -1;
    new->data = malloc(sizeof(int) * stack_size);
    if (!new->data) {
        free(new);
        return (0);
    }
    return (new);
}

void OmStateMachine_destroy(OmStateMachineS *handle)
{
    free(handle->data);
    free(handle);
    handle = NULL;
}

void OmStateMachine_push(OmStateMachineS *handle, int state)
{
    if ((size_t)handle->top == handle->max - 1)
        return;
    handle->data[++handle->top] = state;
}

int OmStateMachine_pop(OmStateMachineS *handle)
{
    if (handle->top == -1)
        return (-1);
    return (handle->data[handle->top--]);
}

int OmStateMachine_fetch_top(OmStateMachineS *handle)
{
    if (handle->top == -1)
        return (-1);
    return (handle->data[handle->top]);
}