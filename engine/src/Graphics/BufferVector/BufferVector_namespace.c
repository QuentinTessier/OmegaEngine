/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_namespace
*/

#include "Graphics/BufferVector.h"

/*
** Construction
*/
OmBufferVector *OmBufferVector_create(void);
void OmBufferVector_init(OmBufferVector *this, size_t capacity);
OmBufferVector *OmBufferVector_with_capacity(size_t capacity);
OmBufferVector *OmBufferVector_clone(OmBufferVector *v);

/*
** Destruction
*/
void OmBufferVector_clear(OmBufferVector *this, bool free_items);
void OmBufferVector_drop(OmBufferVector *this);

/*
** Property access
*/
size_t OmBufferVector_size(OmBufferVector *this);
size_t OmBufferVector_capacity(OmBufferVector *this);

/*
** Item access
*/
void *OmBufferVector_at(OmBufferVector *this, size_t idx);
bool OmBufferVector_set(OmBufferVector *this, size_t idx, sfVertex item);
bool OmBufferVector_includes(OmBufferVector *this, sfVertex elem);
sfVertex OmBufferVector_front(OmBufferVector *this);
sfVertex OmBufferVector_back(OmBufferVector *this);
sfVertex *OmBufferVector_data(OmBufferVector *this);


/*
** Item mutation
*/
ssize_t OmBufferVector_push_back(OmBufferVector *this, size_t nb_args, ...);
ssize_t OmBufferVector_push_front(OmBufferVector *this, size_t nb_args, ...);
sfVertex OmBufferVector_pop_back(OmBufferVector *this);
sfVertex OmBufferVector_pop_front(OmBufferVector *this);
bool OmBufferVector_insert(OmBufferVector *this, size_t idx, sfVertex elem);
sfVertex OmBufferVector_remove(OmBufferVector *this, size_t idx);
OmBufferVector *OmBufferVector_reverse(OmBufferVector *this);
OmBufferVector *OmBufferVector_concat(OmBufferVector *this, OmBufferVector *other);
bool OmBufferVector_reserve(OmBufferVector *this, size_t capacity);
void OmBufferVector_shrink_to_fit(OmBufferVector *this);

/*
** Find item
*/
ssize_t OmBufferVector_index_of(OmBufferVector *this, sfVertex elem);
ssize_t OmBufferVector_last_index_of(OmBufferVector *this, sfVertex elem);
ssize_t OmBufferVector_find_index(OmBufferVector *this,
		bool (*predicate)(void *context, sfVertex elem, size_t idx),
		void *context);
ssize_t OmBufferVector_find_last_index(OmBufferVector *this,
		bool (*predicate)(void *context, sfVertex elem, size_t idx),
		void *context);
sfVertex OmBufferVector_find(OmBufferVector *this,
		bool (*predicate)(void *context, sfVertex elem, size_t idx),
		void *context);
sfVertex OmBufferVector_find_last(OmBufferVector *this,
		bool (*predicate)(void *context, sfVertex elem, size_t idx),
		void *context);

/*
** Iterate over items
*/
void OmBufferVector_map(OmBufferVector *this,
		void *(*func)(void *context, sfVertex elem, size_t idx), void *context);
OmBufferVector *OmBufferVector_filter(OmBufferVector *this,
		bool (*predicate)(void *context, sfVertex elem, size_t idx),
		void *context);
OmBufferVector *OmBufferVector_sort(OmBufferVector *this,
		int (*predicate)(sfVertex a, size_t idx1, sfVertex b, size_t idx2));
void OmBufferVector_for_each(OmBufferVector *this,
		void (*func)(void *context, sfVertex elem, size_t idx), void *context);
void *OmBufferVector_reduce(OmBufferVector *this,
		void *(*func)(void *context, void *acc, sfVertex elem, size_t idx),
		void *context, void *acc);

_OmBufferVector OmBufferVectorS[1] =
{
	{
		OmBufferVector_create,
		OmBufferVector_init,
		OmBufferVector_with_capacity,
		OmBufferVector_clone,
		OmBufferVector_clear,
		OmBufferVector_drop,
		OmBufferVector_size,
		OmBufferVector_capacity,
		OmBufferVector_at,
		OmBufferVector_set,
		OmBufferVector_includes,
		OmBufferVector_front,
		OmBufferVector_back,
		OmBufferVector_data,
		OmBufferVector_push_back,
		OmBufferVector_push_front,
		OmBufferVector_pop_back,
		OmBufferVector_pop_front,
		OmBufferVector_insert,
		OmBufferVector_remove,
		OmBufferVector_reverse,
		OmBufferVector_concat,
		OmBufferVector_reserve,
		OmBufferVector_shrink_to_fit,
		OmBufferVector_index_of,
		OmBufferVector_last_index_of,
		OmBufferVector_find_index,
		OmBufferVector_find_last_index,
		OmBufferVector_find,
		OmBufferVector_find_last,
		OmBufferVector_map,
		OmBufferVector_filter,
		OmBufferVector_sort,
		OmBufferVector_for_each,
		OmBufferVector_reduce
	}
};