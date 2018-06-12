/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** render
*/

#ifndef RENDER_H_
	#define RENDER_H_

typedef enum types {
	SF_SPRI,
	SF_SHAP,
	SF_CISH,
	SF_COSH,
	SF_RESH,
	SF_VERA,
	SF_PRIM,
	SF_TEXT

} TYPE;

void sf_render(sfRenderWindow *window, size_t elements, ...);

#endif /* !RENDER_H_ */
