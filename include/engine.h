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

/* Window and squares infos */

	#define WIN_WIDTH (1280) 	// Always of multiple of S_V
	#define WIN_HEIGHT (768)	// Always a multiple of S_V
	#define S_V (64)		// Size of square in pixels (ex : 64x64)
	#define TEX_NB (5)

/* SFML event macro */

	#define MOV(a) (sfKeyboard_isKeyPressed(a))

/* Math macro for the CoherentNoise */

	#define LERP(a, b, w) (a * (1 - w) + b * w) 			// Linear_interpolation
	#define SCURVE(x) ((-2 * x * x * x) + (3 * x * x)) 		// Scurve smoothing curve
	#define SMOOTH(a, b, w) (LERP(a, b, w * w * (3 - 2 * w))) 	// Another smoothing curve

/* Window and Map Structs */

typedef struct window_info {
	int sq_x;		// Number of squares in x
	int sq_y;		// Number of squares in y
	int sq_i;		// Squares max index
	sfRenderWindow *w;	// RenderWindow
} win_t;

typedef struct texture {
	sfTexture **t; 		// Array of struct containing textures
} t_t;

typedef struct map_struct {
	int w_x;			// World Position x
	int w_y;			// World Position y
	sfVector2f *v_map;		// Vector map to place the squares
	sfRectangleShape **c_map;	// The squares
	double *d_map;			// Double map filled with the generator output
	t_t tex;			// Array of texture
} map_t;

sfVector2f *generate_vector(win_t *);
sfRectangleShape **generate_convex(win_t *, sfVector2f *);
void display_convex(map_t *display, win_t *);
void update_shape(map_t *display);
double *generator(int, int, int, int);
int check_world_position(win_t *, p_t *, map_t *);
sfVector2f get_map_position(win_t *, p_t *, map_t *);
void update_shape_texture(win_t *, map_t *);
void camera_bind_to_player(win_t *, map_t *display, p_t *player, t_t tex);
void camera_separeted_player(win_t *, map_t *, p_t *);
void simple_movement(sfRenderWindow *window, map_t *display, p_t *player, t_t *tex);
double perlin(int octaves, double freq, double pers, double x, double y);
p_t init_player(win_t *);
map_t init_map(win_t *);
t_t init_texture(void);
t_t load_textures(char *dirpath);

#endif /* !ENGINE_H_ */
