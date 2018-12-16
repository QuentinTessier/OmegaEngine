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
#include "engine/message/message.h"

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

OmMessage *create_message(const char *data_name, int use, void *to_use)
{
    OmMessage *new = malloc(sizeof(OmMessage));

    new->data_name = my_strdup(data_name);
    new->data_use = use;
    new->to_use = to_use;
    new->next = 0;
    return (new);
}

void delete_message(OmMessage *message)
{
    free(message->data_name);
    free(message);
    message = 0;
}

static OmQHeader *create();
static OmQHeader *create()
{
    OmQHeader *handle = malloc(sizeof(*handle));

    handle->head = NULL;
    handle->tail = NULL;
    handle->mutex = sfMutex_create();
    return (handle);
}

static void destroy(OmQHeader *header);
static void destroy(OmQHeader *header)
{
    free(header->mutex);
    free(header);
    header = NULL;
}

static void push(OmQHeader *header, OmMessage *message);
static void push(OmQHeader *header, OmMessage *message)
{
    if (message == NULL || header == NULL)
        return;
    sfMutex_lock(header->mutex);
    if (!header->head) {
        header->head = message;
        header->tail = message;
        printf("Send : %s\n", message->data_name);
    } else {
        OmMessage *old_message = header->tail;
        old_message->next = message;
        header->tail = message;
        printf("Send : %s\n", message->data_name);
    }
    sfMutex_unlock(header->mutex);
}

static OmMessage *pop(OmQHeader *header);
static OmMessage *pop(OmQHeader *header)
{
    sfMutex_lock(header->mutex);
    OmMessage *head = header->head;

    if (head == NULL) {
        sfMutex_unlock(header->mutex);
        return (NULL);
    } else {
        header->head = head->next;
        head->next = NULL;
        printf("Recieve : %s\n", head->data_name);
        sfMutex_unlock(header->mutex);
        return (head);
    }
}

_OmQueue const OmQueue = {
    create,
    destroy,
    push,
    pop
};