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
    OmVector *(* const Create)(void);
    OmVector *(* const With_Capacity)(size_t capacity);
    OmVector *(* const Clone)(OmVector *v);

    /*
    ** Destruction
    */
    void (* const Clear)(OmVector *this, bool free_items);
    void (* const Drop)(OmVector *this);

    /*
    ** Property access
    */
    size_t (* const Size)(OmVector *this);
    size_t (* const Capacity)(OmVector *this);

    /*
    ** Item access
    */
    void *(* const At)(OmVector *this, size_t idx);
    bool (* const Set)(OmVector *this, size_t idx, void *item);
    bool (* const Includes)(OmVector *this, void *elem);
    void *(* const Front)(OmVector *this);
    void *(* const Back)(OmVector *this);
    void ** (* const Data)(OmVector *this);


    /*
    ** Item mutation
    */
    ssize_t (* const Push_back)(OmVector *this, size_t nb_args, ...);
    ssize_t (* const Push_front)(OmVector *this, size_t nb_args, ...);
    void *(* const Pop_back)(OmVector *this);
    void *(* const Pop_front)(OmVector *this);
    bool (* const Insert)(OmVector *this, size_t idx, void *elem);
    void *(* const Remove)(OmVector *this, size_t idx);
    OmVector *(* const Reverse)(OmVector *this);
    OmVector *(* const Concat)(OmVector *this, OmVector *other);
    bool (* const Reserve)(OmVector *this, size_t capacity);
    void (* const Shrink_to_fit)(OmVector *this);

    /*
    ** Find item
    */
    ssize_t (* const Index_of)(OmVector *this, void *elem);
    ssize_t (* const Last_index_of)(OmVector *this, void *elem);
    ssize_t (* const Find_index)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    ssize_t (* const Find_last_index)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    void *(* const Find)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    void *(* const Find_last)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);

    /*
    ** Iterate over items
    */
    void (* const Map)(OmVector *this,
        void *(*func)(void *context, void *elem, size_t idx), void *context);
    OmVector *(* const Filter)(OmVector *this,
        bool (*predicate)(void *context, void *elem, size_t idx),
        void *context);
    OmVector *(* const Sort)(OmVector *this,
        int (*predicate)(void *a, size_t idx1, void *b, size_t idx2));
    void (* const ForEach)(OmVector *this,
        void (*func)(void *context, void *elem, size_t idx), void *context);
    void *(* const Reduce)(OmVector *this,
        void *(*func)(void *context, void *acc, void *elem, size_t idx),
        void *context, void *acc);
} _OmVector;

extern _OmVector OmVectorS[1];