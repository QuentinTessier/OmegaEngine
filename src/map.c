/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** map
*/

#include <stdlib.h>
#include "engine.h"

map_t init_map(win_t *win_info)
{
	map_t map;
	
	map.v_map = generate_vector(win_info);
	map.w_x = 0;
	map.w_y = 0;
	map.d_map = generator(win_info->sq_x, win_info->sq_y, 0, 0);
	map.c_map = generate_convex(win_info, map.v_map);
	map.tex = init_texture();
	return (map);
}