/*
** EPITECH PROJECT, 2018
** OmegaEngine
** File description:
** pool_declaration
*/

#pragma once

#include "../pool.h"

OmPoolS *OmPool_create(size_t pool_size);
void OmPool_destroy(OmPoolS *handle);
void OmPool_push(OmPoolS *handle, void *data_ptr);
void *OmPool_pop(OmPoolS *handle, size_t index);
void OmPool_clear(OmPoolS *handle);
void OmPool_insert(OmPoolS *handle, size_t idx, void *data_ptr);