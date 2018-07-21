/*
** EPITECH PROJECT, 2018
** Maths
** File description:
** MObject
*/

#ifndef MOBJECT_H_
	#define MOBJECT_H_

#include "MBool.h"
#include "MVector.h"

typedef struct M_Object {
	MBool Apply_Gravity;
	MVector top_left;
	MVector bottom_right;
	unsigned int width;
	unsigned int length;
} MObject;

#endif /* !MOBJECT_H_ */
