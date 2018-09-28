/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Object
*/

#pragma once

typedef struct object object_t;

typedef enum Ob_bool {
	Ob_true = 1,
	Ob_false = !Ob_true
};

typedef enum Ob_Types {
	Ob_Notype = -1,
	Ob_sprite,
	Ob_circle,
	Ob_rectangle,
	Ob_shape,
	Ob_convex
} Ob_Types;

typedef void (*o_Render_t)(object_t *self);
typedef void (*o_Destroy_t)(object_t *self);

struct object {
	Ob_Types type;
	Ob_bool render;
	void *data;

	o_Render_t Bool_Render;
	o_Destroy_t Destroy;
};