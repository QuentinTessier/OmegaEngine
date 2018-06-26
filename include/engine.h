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

typedef struct sprite_component {
	sfSprite *s;
	sfTexture *t;
	sfVector2f p;
} spr_t;

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

void sf_render(wc_t *, size_t elements, ...);
sfBool check_inside_window(sfRectangleShape *window, sfFloatRect object);

void Call_sfRectShape(wc_t *win_info, sfRectangleShape *object, sfRenderStates *state);
void Call_sfCircleShape(wc_t *win_info, sfCircleShape *object, sfRenderStates *state);
void Call_sfConvexShape(wc_t *win_info, sfConvexShape *object, sfRenderStates *state);
void Call_sfShape(wc_t *win_info, sfShape *object, sfRenderStates *state);
void Call_sfText(wc_t *win_info, const sfText *object, sfRenderStates *state);
void Call_sfSprite(wc_t *win_info, sfSprite *object, sfRenderStates *state);


void move_rectSprite(sfSprite *s, sfIntRect new_rect);
spr_t new_sprite(char *path, sfIntRect size, sfVector2f pos);


#endif /* !ENGINE_H_ */