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
#include "sprite.h"
#include "data_struct.h"

typedef struct win_component {
	sfRenderWindow *w;
	sfVideoMode v;
	sfRectangleShape *r;
} wc_t;

void sprite_create(_sprite_t *sprite, char *path, sfVector2f position);
void sprite_flipbook(_sprite_t *sprite, size_t nb, ...);

void pause_game_for_duration(float duration);
void create_stack(render_stack *stack, size_t size);
void push(render_stack *stack, void *data, data_type type);


#endif /* !ENGINE_H_ */