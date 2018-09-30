/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Object
*/

#pragma once

#include "Root.h"

typedef struct object object_t;


object_t *Object_error;

#define OB_ERROR(x)			\
	Object_error = x;		\
	if (Object_error == 0)		\
		exit (84);		\
	Object_error
	
void ob_report_error(int type, int depth);

#define OB_INIT_ERROR(x, y, z)		\
	if ((x) == 0) {			\
		ob_report_error(y, z);	\
	}

typedef enum Ob_bool {
	OB_TRUE = 1,
	OB_FALSE = !OB_TRUE
} Ob_bool;

typedef enum Ob_Types {
	Ob_Notype = -1,
	OB_SPRITE,
	Ob_circle,
	Ob_rectangle,
	Ob_shape,
	Ob_convex,
	OB_TEXTURE
} Ob_Types;

typedef void (*o_Init_as_Texture_t)(object_t **self, const char *path, sfIntRect *rect);
typedef void (*o_Init_as_Sprite_t)(object_t *self, char *path);

struct object {
	int depth;
	Ob_bool lock;
	Ob_Types type;
	Ob_bool render;
	void *data;
	object_t *next;

	// Constructor
	o_Init_as_Texture_t AsTexture;
	o_Init_as_Sprite_t AsSprite;
};

void o_Init_as_Texture(object_t **self, const char *f_path, sfIntRect *rect);