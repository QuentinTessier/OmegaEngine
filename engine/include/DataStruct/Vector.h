/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector
*/

#pragma once

#include <stdbool.h>
#include <sys/types.h>

typedef struct OmVector {
    size_t size;
    size_t capacity;
    void **data;
} OmVector;

typedef struct {
    /*
    ** Construction
    */
    OmVector *(* const create)(void);
    OmVector *(* const with_capacity)(size_t capacity);
    OmVector *(* const clone)(OmVector *v);

    /*
    ** Destruction
    */
    void (* const clear)(OmVector *this, bool free_items);
    void (* const drop)(OmVector *this);

    /*
    ** Property access
    */
    size_t (* const size)(OmVector *this);
    size_t (* const capacity)(OmVector *this);

    /*
    ** Item access
    */
    void *(* const at)(OmVector *this, size_t idx);
    bool (* const set)(OmVector *this, size_t idx, void *item);
    bool (* const includes)(OmVector *this, void *elem);
    void *(* const front)(OmVector *this);
    void *(* const back)(OmVector *this);
    void ** (* const data)(OmVector *this);


    /*
    ** Item mutation
    */
    ssize_t (* const push_back)(OmVector *this, size_t nb_args, ...);
    ssize_t (* const push_front)(OmVector *this, size_t nb_args, ...);
    void *(* const pop_back)(OmVector *this);
    void *(* const pop_front)(OmVector *this);
    bool (* const insert)(OmVector *this, size_t idx, void *elem);
    void *(* const remove)(OmVector *this, size_t idx);
    OmVector *(* const reverse)(OmVector *this);
    OmVector *(* const concat)(OmVector *this, OmVector *other);
    bool (* const reserve)(OmVector *this, size_t capacity);
    void (* const shrink_to_fit)(OmVector *this);

    /*
    ** Find item
    */
    ssize_t (* const index_of)(OmVector *this, void *elem);
    ssize_t (* const last_index_of)(OmVector *this, void *elem);
    ssize_t (* const find_index)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    ssize_t (* const find_last_index)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    void *(* const find)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    void *(* const find_last)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);

    /*
    ** Iterate over items
    */
    void (* const map)(OmVector *this,
        void *(*func)(void *context, void *elem, size_t idx), void *context);
    OmVector *(* const filter)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    OmVector *(* const sort)(OmVector *this,
        int (*predicate)(void *a, size_t idx1, void *b, size_t idx2));
    void (* const for_each)(OmVector *this,
        void (*func)(void *context, void *elem, size_t idx), void *context);
    void *(* const reduce)(OmVector *this,
        void *(*func)(void *context, void *acc, void *elem, size_t idx),
        void *context, void *acc);
} _OmVector;

extern _OmVector OmVectorS[1];