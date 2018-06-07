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

	#define WIN_WIDTH (1280) 	/* Always of multiple of S_V*/
	#define WIN_HEIGHT (768)	/* Always of multiple of S_V*/
	#define S_V (64)
	#define TEX_NB (5)
	#define MOV(a) (sfKeyboard_isKeyPressed(a))
	#define LERP(a, b, w) (a * (1 - w) + b * w)
	#define SCURVE(x) ((-2 * x * x * x) + (3 * x * x))
	#define SMOOTH(a, b, w) (LERP(a, b, w * w * (3 - 2 * w)))

typedef struct window_info {
	int sq_x;
	int sq_y;
	int sq_i;
	sfRenderWindow *w;
} win_t;

typedef struct texture {
	sfTexture *t;
} t_t;

typedef struct map_struct {
	int w_x;
	int w_y;
	sfVector2f *v_map;
	sfRectangleShape **c_map;
	double *d_map;
	t_t *tex;
} map_t;

sfVector2f *generate_vector(win_t *);
sfRectangleShape **generate_convex(win_t *, sfVector2f *);
void display_convex(map_t *display, win_t *);
void update_shape(map_t *display);
double *generator(int, int, int, int);
int check_world_position(win_t *, p_t *, map_t *);
sfVector2f get_map_position(win_t *, p_t *, map_t *);
t_t *create_texture(void);
void update_shape_texture(win_t *, map_t *, t_t *);
void camera_bind_to_player(win_t *, map_t *display, p_t *player, t_t *tex);
void camera_separeted_player(win_t *, map_t *, p_t *, t_t *);
void simple_movement(sfRenderWindow *window, map_t *display, p_t *player, t_t *tex);
double perlin(int octaves, double freq, double pers, double x, double y);
p_t init_player(win_t *);


#endif /* !ENGINE_H_ */
