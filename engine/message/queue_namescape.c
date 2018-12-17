/*
** EPITECH PROJECT, 2018
** CSFML_2D_RENDERER
** File description:
** queue_namescape
*/

#include "thread_handler/message_queue.h"

OmQHeader *create();
void destroy(OmQHeader *header);
void push(OmQHeader *header, OmMessage *message);
OmMessage *pop(OmQHeader *header);

_OmQueue const OmQueue = {
    create,
    destroy,
    push,
    pop
};