/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** engine
*/

#ifndef ENGINE_H_
	#define ENGINE_H_

#include <SFML/Graphics.h>
#include "player.h"

	#define WIN_WIDTH (1920)
	#define WIN_HEIGHT (1080)
	#define X_V (30)
	#define Y_V (16)

typedef struct texture {
	sfTexture *t;
} t_t;

typedef struct display {
	int x;
	int y;
	sfVector2f *vector_map;
	sfRectangleShape **convex_map;
	double *generated;
} dis_t;

sfVector2f *generate_point();
sfRectangleShape **generate_convex(dis_t *display);
void display_convex(dis_t *display, sfRenderWindow *window);
void update_shape(dis_t *display);
double *generator(int, int, int, int);
int check_world_position(p_t *player, dis_t *display);
int get_map_position(p_t *player, dis_t *display);
t_t *create_texture(void);
void update_shape_texture(dis_t *display, t_t *tex);

#endif /* !ENGINE_H_ */
