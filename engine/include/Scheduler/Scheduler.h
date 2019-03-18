/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Scheduler
*/

#pragma once

#include "Component.h"

enum OmSchedulerReadManner {
    Read_First,
    Read_Last
};

typedef struct OmScheduler {
    OmComponent Comp[1];

    OmVector *stack;
    int ReadManner;
} OmScheduler;

struct _OmScheduler {
    OmScheduler *(* const Create)(void);
    void (* const Destroy)(OmScheduler *item);
    OmScheduler *(* const Init)(OmScheduler *item, int ReadManner);
    bool (* const Add)(OmScheduler *item, void *data);
    void *(* const Pop)(OmScheduler *item);
    void *(* const Read)(OmScheduler *item,
            void (* func)(void *context, void *elem, size_t idx),
            void *context);
};

extern _OmScheduler OmShedulerS[1];