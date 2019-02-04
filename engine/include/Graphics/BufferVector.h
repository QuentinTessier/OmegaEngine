/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** BufferVector
*/

#pragma once

#include <sys/types.h>
#include <stdbool.h>
#include <SFML/Graphics/Vertex.h>

#define VERTEX_BASIC ((sfVertex){(sfVector2f){0.f, 0.f}, (sfColor){255, 255, 255, 255}, (sfVector2f){0.f, 0.f}})

typedef struct OmBufferVector {
    size_t size;
    size_t capacity;
    sfVertex *data;
} OmBufferVector;

typedef struct {
    /*
    ** Construction
    */
    OmBufferVector *(* const create)(void);
    void (* const init)(OmBufferVector *this, size_t capacity);
    OmBufferVector *(* const with_capacity)(size_t capacity);
    OmBufferVector *(* const clone)(OmBufferVector *v);

    /*
    ** Destruction
    */
    void (* const clear)(OmBufferVector *this, bool free_items);
    void (* const drop)(OmBufferVector *this);

    /*
    ** Property access
    */
    size_t (* const size)(OmBufferVector *this);
    size_t (* const capacity)(OmBufferVector *this);

    /*
    ** Item access
    */
    void *(* const at)(OmBufferVector *this, size_t idx);
    bool (* const set)(OmBufferVector *this, size_t idx, sfVertex item);
    bool (* const includes)(OmBufferVector *this, sfVertex elem);
    sfVertex (* const front)(OmBufferVector *this);
    sfVertex (* const back)(OmBufferVector *this);
    sfVertex *(* const data)(OmBufferVector *this);


    /*
    ** Item mutation
    */
    ssize_t (* const push_back)(OmBufferVector *this, size_t nb_args, ...);
    ssize_t (* const push_front)(OmBufferVector *this, size_t nb_args, ...);
    sfVertex (* const pop_back)(OmBufferVector *this);
    sfVertex (* const pop_front)(OmBufferVector *this);
    bool (* const insert)(OmBufferVector *this, size_t idx, sfVertex elem);
    sfVertex (* const remove)(OmBufferVector *this, size_t idx);
    OmBufferVector *(* const reverse)(OmBufferVector *this);
    OmBufferVector *(* const concat)(OmBufferVector *this, OmBufferVector *other);
    bool (* const reserve)(OmBufferVector *this, size_t capacity);
    void (* const shrink_to_fit)(OmBufferVector *this);

    /*
    ** Find item
    */
    ssize_t (* const index_of)(OmBufferVector *this, sfVertex elem);
    ssize_t (* const last_index_of)(OmBufferVector *this, sfVertex elem);
    ssize_t (* const find_index)(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context);
    ssize_t (* const find_last_index)(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context);
    sfVertex (* const find)(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context);
    sfVertex (* const find_last)(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context);

    /*
    ** Iterate over items
    */
    void (* const map)(OmBufferVector *this,
        void *(*func)(void *context, sfVertex elem, size_t idx), void *context);
    OmBufferVector *(* const filter)(OmBufferVector *this,
        bool (*predicate)(void *context, sfVertex elem, size_t idx),
        void *context);
    OmBufferVector *(* const sort)(OmBufferVector *this,
        int (*predicate)(sfVertex a, size_t idx1, sfVertex b, size_t idx2));
    void (* const for_each)(OmBufferVector *this,
        void (*func)(void *context, sfVertex elem, size_t idx), void *context);
    void *(* const reduce)(OmBufferVector *this,
        void *(*func)(void *context, void *acc, sfVertex elem, size_t idx),
        void *context, void *acc);
} _OmBufferVector;

extern _OmBufferVector OmBufferVectorS[1];