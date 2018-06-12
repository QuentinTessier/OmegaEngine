/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** renderer
*/

#include <sys/types.h>
#include <stdarg.h>
#include <stdio.h>
#include "engine.h"

void sf_render(wc_t *win_info, size_t elements, ...)
{
	va_list list;
	size_t i = 0;

	va_start(list, elements);
	while (i < elements) {
		TYPE a = va_arg(list, TYPE);
		switch (a) {
			case SF_RESH :
				Call_sfRectShape(win_info, va_arg(list, sfRectangleShape *), NULL);
				break;
			case SF_SPRI :
				Call_sfSprite(win_info, va_arg(list, sfSprite *), NULL);
				break;
			case SF_CISH :
				Call_sfCircleShape(win_info, va_arg(list, sfCircleShape *), NULL);
				break;
			case SF_COSH :
				Call_sfConvexShape(win_info, va_arg(list, sfConvexShape *), NULL);
				break;
			case SF_SHAP :
				Call_sfShape(win_info, va_arg(list, sfShape *), NULL);
				break;
			case SF_VERA :
				sfRenderWindow_drawVertexArray(win_info->w, va_arg(list, sfVertexArray *), NULL);
				break;
			case SF_TEXT :
				Call_sfText(win_info, va_arg(list, const sfText *), NULL);
				break;
			/*case SF_PRIM :
				sfRenderWindow_drawPrimitives(win_info, va_arg(list, sfPrimitiveType *), NULL);
				break;*/
			default :
				va_arg(list, void *);
				printf("Unreconized type\n");
				break;
		}
		i++;
	}
}