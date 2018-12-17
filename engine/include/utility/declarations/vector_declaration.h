/*
** EPITECH PROJECT, 2018
** CSFML_2D_RENDERER
** File description:
** vector_declaration
*/

#pragma once

#include "../vector.h"

/*
** Constructors
*/
OmVectorS *OmVec_new(void);
OmVectorS *OmVec_from_capacity(size_t capacity);
OmVectorS *OmVec_clone(OmVectorS *vector);

/*
** Destructors
*/
void OmVec_clear(OmVectorS *this, bool free_items);
void OmVec_drop(OmVectorS *this);

/*
** Set/Get
*/
bool OmVec_set(OmVectorS *this, size_t idx, void *item);
void *OmVec_back(OmVectorS *this);
void *OmVec_front(OmVectorS *this);
void *OmVec_at(OmVectorS *this, size_t idx);

/*
** Property access
*/
size_t OmVec_size(OmVectorS *this);
size_t OmVec_capacity(OmVectorS *this);

/*
** Data Mutation
*/
ssize_t OmVec_push_back(OmVectorS *this, size_t nb_args, ...);
ssize_t OmVec_push_front(OmVectorS *this, size_t nb_args, ...);
void *OmVec_pop_back(OmVectorS *this);
void *OmVec_pop_front(OmVectorS *this);
bool OmVec_insert(OmVectorS *this, size_t idx, void *element);
void *OmVec_remove(OmVectorS *this, size_t idx);
OmVectorS *OmVec_reverse(OmVectorS *this);
OmVectorS *OmVec_concat(OmVectorS *this, OmVectorS *other);
bool OmVec_reserve(OmVectorS *this, size_t capacity);
void OmVec_shrink_to_fit(OmVectorS *this);

/*
** Find item
*/
ssize_t OmVec_index_of(OmVectorS *this, void *element);
ssize_t OmVec_last_index_of(OmVectorS *this, void *element);
ssize_t OmVec_find_index(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);
ssize_t OmVec_find_last_index(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);
void *OmVec_find(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);
void *OmVec_find_last(OmVectorS *this,
        bool (*predicate)(void *context, void *element, size_t idx),
        void *context);

/*
** Iterate over items
*/
void OmVec_map(OmVectorS *this,
        void *(*func)(void *context, void *elem, size_t idx),
        void *context);
OmVectorS *OmVec_filter(OmVectorS *this,
        void *(*predicate)(void *context, void *elem, size_t idx),
        void *context);
OmVectorS *OmVec_sort(OmVectorS *this,
        int (*predicate)(void *a, size_t idx1, void *b, size_t idx));
void OmVec_for_each(OmVectorS *this,
        int (*func)(void *context, void *elem, size_t idx), void *context);
void *OmVec_reduce(OmVectorS *this,
        void *(*func)(void *context, void *acc, void *elem, size_t idx),
        void *context, void *acc);
