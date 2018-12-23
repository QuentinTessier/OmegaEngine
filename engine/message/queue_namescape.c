/*
** EPITECH PROJECT, 2018
** CSFML_2D_RENDERER
** File description:
** queue_namescape
*/

#include "thread_handler/message_queue.h"

OmQueueS *create();
void destroy(OmQueueS *header);
void push(OmQueueS *header, OmMessage *message);
OmMessage *pop(OmQueueS *header);
sfBool OmQueueS_is_valid(OmQueueS *handle, int ReceiverID);

_OmQueue const OmQueue = {
    create,
    destroy,
    push,
    pop,
    OmQueueS_is_valid
};