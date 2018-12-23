/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** queue
*/

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <SFML/System/Mutex.h>
#include "thread_handler/message_queue.h"

static char *my_strdup(const char *s)
{
    int size = strlen(s);
    char *new = malloc(sizeof(char) * size + 1);

    if (!new)
        return (NULL);
    for (int i = 0; s[i]; i++)
        new[i] = s[i];
    new[size] = 0;
    return (new);
}

OmMessage *create_message(const char *data_name, int use, void *to_use, int ReceiverID)
{
    OmMessage *new = malloc(sizeof(OmMessage));

    new->data_name = my_strdup(data_name);
    new->data_use = use;
    new->to_use = to_use;
    new->receiverID = ReceiverID;
    new->next = 0;
    return (new);
}

void delete_message(OmMessage *message)
{
    if (message == NULL)
        return;
    free(message->data_name);
    free(message);
    message = 0;
}

OmQueueS *create()
{
    OmQueueS *handle = malloc(sizeof(*handle));

    handle->head = NULL;
    handle->tail = NULL;
    handle->mutex = sfMutex_create();
    return (handle);
}

void destroy(OmQueueS *handle)
{
    free(handle->mutex);
    free(handle);
    handle = NULL;
}

void push(OmQueueS *handle, OmMessage *message)
{
    if (message == NULL || handle == NULL)
        return;
    sfMutex_lock(handle->mutex);
    if (!handle->head) {
        handle->head = message;
        handle->tail = message;
        printf("Send : %s\n", message->data_name);
    } else {
        OmMessage *old_message = handle->tail;
        old_message->next = message;
        handle->tail = message;
        printf("Send : %s\n", message->data_name);
    }
    sfMutex_unlock(handle->mutex);
}

OmMessage *pop(OmQueueS *handle, int ReceiverID)
{
    sfMutex_lock(handle->mutex);
    OmMessage *head = handle->head;

    if (head == NULL || head->receiverID != ReceiverID) {
        sfMutex_unlock(handle->mutex);
        return (NULL);
    } else {
        handle->head = head->next;
        head->next = NULL;
        printf("Recieve : %s\n", head->data_name);
        sfMutex_unlock(handle->mutex);
        return (head);
    }
}

sfBool OmQueueS_is_valid(OmQueueS *handle, int ReceiverID)
{
    sfMutex_lock(handle->mutex);
    sfBool ret = sfFalse;

    if (handle->head == NULL) {
        sfMutex_unlock(handle->mutex);
        return (ret);
    } else {
        if (handle->head->receiverID == ReceiverID)
            ret = sfTrue;
    }
    sfMutex_unlock(handle->mutex);
    return (ret);
}