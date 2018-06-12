/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** engine
*/

#ifndef ENGINE_H_
	#define ENGINE_H_

#include <sys/types.h>
#include <SFML/Graphics.h>
#include "render.h"

typedef struct win_component {
	sfRenderWindow *w;
	sfVideoMode v;
	sfRectangleShape *r;
} wc_t;

void sf_render(sfRenderWindow *window, size_t elements, ...);
sfBool check_inside_window(sfRectangleShape *window, sfFloatRect object);

#endif /* !ENGINE_H_ */
