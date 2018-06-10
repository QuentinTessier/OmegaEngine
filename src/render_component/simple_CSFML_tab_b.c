/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** simple_CSFML_tab_b
*/

#include <sys/types.h>
#include <SFML/Graphics.h>

void render_tab_sfShape(size_t length, sfRenderWindow *window, sfShape **shape)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawShape(window, shape[i], NULL);
		i++;
	}
	return;
}

void render_tab_sfText(size_t length, sfRenderWindow *window, sfText **text)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawText(window, text[i], NULL);
		i++;
	}
	return;
}

void render_tab_sfVertexArray(size_t length, sfRenderWindow *window, sfVertexArray **vertex)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawVertexArray(window, vertex[i], NULL);
		i++;
	}
	return;
}

/*void render_tab_sfPrimitive(size_t length, sfRenderWindow *window, sfPrimitiveType **prim)
{
	size_t i = 0;

	while (i < length) {
		sfRenderWindow_drawPrimitives(window, prim[i], NULL);
	}
	return;
}*/