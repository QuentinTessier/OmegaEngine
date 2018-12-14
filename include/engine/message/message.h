/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** message
*/

#pragma once

typedef struct OmMessage {
    char *data_name;
    int data_use;
    void *to_use;
    struct OmMessage *next;
} OmMessage;

struct OmQHeader {
    OmMessage *head;
    OmMessage *tail;
    sfMutex *mutex;
};

typedef struct OmQHeader OmQHeader;

typedef struct {
    OmQHeader *(* const create)();
    void (* const destroy)(OmQHeader *handle);
    void (* const push)(OmQHeader *handle, OmMessage *elem);
    OmMessage *(* const pop)(OmQHeader *handle);
} _OmQueue;

extern _OmQueue const OmQueue;

OmMessage *create_message(const char *data_name, int use, void *to_use);
void delete_message(OmMessage *message);