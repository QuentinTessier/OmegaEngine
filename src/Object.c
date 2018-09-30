/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** Object
*/

#include <unistd.h>
#include "Object.h"

void o_Init_as_Texture(object_t **self, const char *f_path, sfIntRect *rect)
{
	(*self)->data = sfTexture_createFromFile(f_path, rect);
	OB_INIT_ERROR((*self)->data, (*self)->type, (*self)->depth);
	(*self)->type = OB_TEXTURE;
	(*self)->render = OB_FALSE;
}