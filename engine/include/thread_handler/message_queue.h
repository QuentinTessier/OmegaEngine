/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** message
*/

#pragma once

#include <SFML/System/Thread.h>

/*
**  Temporary message queue for threads
*/

typedef enum OmThreadID {
    OmConsole,
    OmMainThread,
    OmRenderThread
} OmThreadID;

typedef enum OmMainMessage {
    OmMain_ActivateWindow,
    OmMain_DeactivateWindow
} OmMainMessage;

typedef struct OmMessage {
    char *data_name;
    int receiverID;
    int data_use;
    void *to_use;
    struct OmMessage *next;
} OmMessage;

struct OmQueueS {
    OmMessage *head;
    OmMessage *tail;
    sfMutex *mutex;
};

typedef struct OmQueueS OmQueueS;

typedef struct {
    OmQueueS *(* const create)();
    void (* const destroy)(OmQueueS *handle);
    void (* const push)(OmQueueS *handle, OmMessage *elem);
    OmMessage *(* const pop)(OmQueueS *handle);
    int (* const is_valid)(OmQueueS *handle, int ReceiverID);
} _OmQueue;

OmQueueS *MainQueue;

extern _OmQueue const OmQueue;

OmMessage *create_message(const char *data_name, int use, void *to_use, int ReceiverID);
void delete_message(OmMessage *message);