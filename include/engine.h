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
#include "load.h"

	#define W_WIDTH 	(1280)
	#define W_HEIGHT 	(720)
	#define W_NAME		("ENGINE")

typedef struct win_component {
	sfRenderWindow *w;
	sfVideoMode v;
	sfRectangleShape *r;
	//sfTexture *t;	If you us the framebuffer (Not in the engine yet)
	//sfSprite *s;	If you us the framebuffer (Not in the engine yet)
} wc_t;

typedef struct spr_component {
	char *filepath;
	sfSprite *s;
	sfTexture *t;
	sfIntRect r;
	sfVector2f p;
} spr_t;

spr_t load_hero_sprite();
void update_sprite(spr_t *sprite, sfIntRect new_rect);
spr_t *load_tab_sprite(size_t nb, char *path, const sfVector2f *varray);
void render_tab_struct(size_t length, wc_t *, spr_t *sprite);
int check_window_sprite(sfRectangleShape *win_r, sfSprite *s);

#endif /* !ENGINE_H_ */
