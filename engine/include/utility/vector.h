/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** A simple implementation of a C++ like vector array
*/

#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

typedef struct OmVector OmVector;

struct OmVector {
    size_t capacity;
    size_t size;
    void **arr;
};

/*
** Constructors
*/
OmVector *OmVec_new(void);
OmVector *OmVec_from_capacity(size_t capacity);
OmVector *OmVec_clone(OmVector *vector);

/*
** Destructors
*/
void OmVec_clear(OmVector *this, bool free_items);
void OmVec_drop(OmVector *this);

/*
** Set/Get
*/
bool OmVec_set(OmVector *this, size_t idx, void *item);
void *OmVec_back(OmVector *this);
void *OmVec_front(OmVector *this);
void *OmVec_at(OmVector *this, size_t idx);

/*
** Property access
*/
size_t OmVec_size(OmVector *this);
size_t OmVec_capacity(OmVector *this);

/*
** Data Mutation
*/
ssize_t OmVec_push_back(OmVector *this, size_t nb_args, ...);
ssize_t OmVec_push_front(OmVector *this, size_t nb_args, ...);
void *OmVec_pop_back(OmVector *this);
void *OmVec_pop_front(OmVector *this);
bool OmVec_insert(OmVector *this, size_t idx, void *element);
void *OmVec_remove(OmVector *this, size_t idx);
OmVector *OmVec_reverse(OmVector *this);
OmVector *OmVec_concat(OmVector *this, OmVector *other);
bool OmVec_reserve(OmVector *this, size_t capacity);
void OmVec_shrink_to_fit(OmVector *this);

/*
** Find item
*/
ssize_t OmVec_index_of(OmVector *this, void *element);
ssize_t OmVec_last_index_of(OmVector *this, void *element);
ssize_t OmVec_find_index(OmVector *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);
ssize_t OmVec_find_last_index(OmVector *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);
void *OmVec_find(OmVector *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);
void *OmVec_find_last(OmVector *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);

/*
** Iterate over items
*/
void OmVec_map(OmVector *this,
        void *(*func)(void *context, void *elem, size_t idx),
        void *context);
OmVector *OmVec_filter(OmVector *this,
        void *(*predicate)(void *context, void *elem, size_t idx),
        void *context);
OmVector *OmVec_sort(OmVector *this,
        int (*predicate)(void *a, size_t idx1, void *b, size_t idx));
void OmVec_for_each(OmVector *this,
        int (*func)(void *context, void *elem, size_t idx), void *context);
void *OmVec_reduce(OmVector *this,
        void *(*func)(void *context, void *acc, void *elem, size_t idx),
        void *context, void *acc);