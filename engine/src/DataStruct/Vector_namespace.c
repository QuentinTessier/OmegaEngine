/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Vector_namespace
*/

#include "DataStruct/Vector.h"

/*
** Construction
*/
OmVector *OmVector_create(void);
OmVector *OmVector_with_capacity(size_t capacity);
OmVector *OmVector_clone(OmVector *src);

/*
** Destruction
*/
void OmVector_clear(OmVector *this, bool free_items);
void OmVector_drop(OmVector *this);

/*
** Property access
*/
size_t OmVector_size(OmVector *this);
size_t OmVector_capacity(OmVector *this);

/*
** Item access
*/
void *OmVector_at(OmVector *this, size_t idx);
bool OmVector_set(OmVector *this, size_t idx, void *item);
bool OmVector_includes(OmVector *this, void *elem);
void *OmVector_front(OmVector *this);
void *OmVector_back(OmVector *this);
void **OmVector_data(OmVector *this);

/*
** Item mutation
*/
ssize_t OmVector_push_back(OmVector *this, size_t nb_args, ...);
ssize_t OmVector_push_front(OmVector *this, size_t nb_args, ...);
void *OmVector_pop_back(OmVector *this);
void *OmVector_pop_front(OmVector *this);
bool OmVector_insert(OmVector *this, size_t idx, void *elem);
void *OmVector_remove(OmVector *this, size_t idx);
OmVector *OmVector_reverse(OmVector *this);
OmVector *OmVector_concat(OmVector *this, OmVector *other);
bool OmVector_reserve(OmVector *this, size_t capacity);
void OmVector_shrink_to_fit(OmVector *this);

/*
** Find item
*/
ssize_t OmVector_index_of(OmVector *this, void *elem);
ssize_t OmVector_last_index_of(OmVector *this, void *elem);
ssize_t OmVector_find_index(OmVector *this,
	bool (*predicate)(void *context, void *elem, size_t idx),
	void *context);
ssize_t OmVector_find_last_index(OmVector *this,
	bool (*predicate)(void *context, void *elem, size_t idx),
	void *context);
void *OmVector_find(OmVector *this,
	bool (*predicate)(void *context, void *elem, size_t idx),
	void *context);
void *OmVector_find_last(OmVector *this,
	bool (*predicate)(void *context, void *elem, size_t idx),
	void *context);

/*
** Iterate over items
*/
void OmVector_map(OmVector *this,
	void *(*func)(void *context, void *elem, size_t idx), void *context);
OmVector *OmVector_filter(OmVector *this,
	bool (*predicate)(void *context, void *elem, size_t idx),
	void *context);
OmVector *OmVector_sort(OmVector *this,
	int (*predicate)(void *a, size_t idx1, void *b, size_t idx2));
void OmVector_for_each(OmVector *this,
	void (*func)(void *context, void *elem, size_t idx), void *context);
void *OmVector_reduce(OmVector *this,
	void *(*func)(void *context, void *acc, void *elem, size_t idx),
	void *context, void *acc);

_OmVector OmVectorS[1] =
{
	{
		OmVector_create,
		OmVector_with_capacity,
		OmVector_clone,
		OmVector_clear,
		OmVector_drop,
		OmVector_size,
		OmVector_capacity,
		OmVector_at,
		OmVector_set,
		OmVector_includes,
		OmVector_front,
		OmVector_back,
		OmVector_data,
		OmVector_push_back,
		OmVector_push_front,
		OmVector_pop_back,
		OmVector_pop_front,
		OmVector_insert,
		OmVector_remove,
		OmVector_reverse,
		OmVector_concat,
		OmVector_reserve,
		OmVector_shrink_to_fit,
		OmVector_index_of,
		OmVector_last_index_of,
		OmVector_find_index,
		OmVector_find_last_index,
		OmVector_find,
		OmVector_find_last,
		OmVector_map,
		OmVector_filter,
		OmVector_sort,
		OmVector_for_each,
		OmVector_reduce
	}
};