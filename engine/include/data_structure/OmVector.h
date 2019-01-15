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

typedef struct OmVectorS OmVectorS;

struct OmVectorS {
    size_t capacity;
    size_t size;
    void **arr;
};

typedef struct {
    OmVectorS *(* const new)(void);
    OmVectorS *(* const from_capacity)(size_t capacity);
    OmVectorS *(* const clone)(OmVectorS *vector);
    void (* const clear)(OmVectorS *this, bool free_items);
    void (* const drop)(OmVectorS *this);
    bool (* const set)(OmVectorS *this, size_t idx, void *item);
    void *(* const back)(OmVectorS *this);
    void *(* const front)(OmVectorS *this);
    void *(* const at)(OmVectorS *this, size_t idx);
    size_t (* const size)(OmVectorS *this);
    size_t (* const capacity)(OmVectorS *this);
    ssize_t (* const push_back)(OmVectorS *this, size_t nb_args, ...);
    ssize_t (* const push_front)(OmVectorS *this, size_t nb_args, ...);
    void *(* const pop_back)(OmVectorS *this);
    void *(* const pop_front)(OmVectorS *this);
    bool (* const insert)(OmVectorS *this, size_t idx, void *element);
    void *(* const remove)(OmVectorS *this, size_t idx);
    OmVectorS *(* const reverse)(OmVectorS *this);
    OmVectorS *(* const concat)(OmVectorS *this, OmVectorS *other);
    bool (* const reserve)(OmVectorS *this, size_t capacity);
    void (* const shrink_to_fit)(OmVectorS *this);
    ssize_t (* const index_of)(OmVectorS *this, void *element);
    ssize_t (* const last_index_of)(OmVectorS *this, void *element);
    ssize_t (* const find_index)(OmVectorS *this,
            bool (*predicate)(void *context, void *element, size_t idx),
            void *context);
    ssize_t (* const find_last_index)(OmVectorS *this,
            bool (*predicate)(void *context, void *element, size_t idx),
            void *context);
    void *(* const find)(OmVectorS *this,
            bool (*predicate)(void *context, void *element, size_t idx),
            void *context);
    void *(* const find_last)(OmVectorS *this,
            bool (*predicate)(void *context, void *element, size_t idx),
            void *context);
    void (* const map)(OmVectorS *this,
            void *(*func)(void *context, void *elem, size_t idx),
            void *context);
    OmVectorS *(* const filter)(OmVectorS *this,
            void *(*predicate)(void *context, void *elem, size_t idx),
            void *context);
    OmVectorS *(* const OmVec_sort)(OmVectorS *this,
            int (*predicate)(void *a, size_t idx1, void *b, size_t idx));
    void (* const for_each)(OmVectorS *this,
            int (*func)(void *context, void *elem, size_t idx), void *context);
    void *(* const reduce)(OmVectorS *this,
            void *(*func)(void *context, void *acc, void *elem, size_t idx),
            void *context, void *acc);
} _OmVector;

extern _OmVector const OmVector;