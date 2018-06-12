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

void sf_render(sfRenderWindow *window, size_t elements, ...)
{
	va_list list;
	size_t i = 0;

	va_start(list, elements);
	while (i < elements) {
		TYPE a = va_arg(list, TYPE);
		switch (a) {
			case SF_RESH :
				sfRenderWindow_drawRectangleShape(window, va_arg(list, sfRectangleShape *), NULL);
				break;
			case SF_SPRI :
				sfRenderWindow_drawSprite(window, va_arg(list, sfSprite *), NULL);
				break;
			case SF_CISH :
				sfRenderWindow_drawCircleShape(window, va_arg(list, sfCircleShape *), NULL);
				break;
			case SF_COSH :
				sfRenderWindow_drawConvexShape(window, va_arg(list, sfConvexShape *), NULL);
				break;
			case SF_SHAP :
				sfRenderWindow_drawShape(window, va_arg(list, sfShape *), NULL);
				break;
			case SF_VERA :
				sfRenderWindow_drawVertexArray(window, va_arg(list, sfVertexArray *), NULL);
				break;
			case SF_TEXT :
				sfRenderWindow_drawText(window, va_arg(list, const sfText *), NULL);
				break;
			/*case SF_PRIM :
				sfRenderWindow_drawPrimitives(window, va_arg(list, sfPrimitiveType *), NULL);
				break;*/
			default :
				va_arg(list, void *);
				printf("Unreconized type\n");
				break;
		}
		i++;
	}
}