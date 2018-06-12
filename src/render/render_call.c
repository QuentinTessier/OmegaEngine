/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** render_call
*/

#include "engine.h"

void Call_sfRectShape(wc_t *win_info, sfRectangleShape *object, sfRenderStates *state)
{
	if (check_inside_window(win_info->r, 
			sfRectangleShape_getGlobalBounds(object)) == sfTrue)
		sfRenderWindow_drawRectangleShape(win_info->w, object, state);
}

void Call_sfCircleShape(wc_t *win_info, sfCircleShape *object, sfRenderStates *state)
{
	if (check_inside_window(win_info->r, 
			sfCircleShape_getGlobalBounds(object)) == sfTrue)
		sfRenderWindow_drawCircleShape(win_info->w, object, state);
}

void Call_sfConvexShape(wc_t *win_info, sfConvexShape *object, sfRenderStates *state)
{
	if (check_inside_window(win_info->r, 
			sfConvexShape_getGlobalBounds(object)) == sfTrue)
		sfRenderWindow_drawConvexShape(win_info->w, object, state);
}

void Call_sfShape(wc_t *win_info, sfShape *object, sfRenderStates *state)
{
	if (check_inside_window(win_info->r, 
			sfShape_getGlobalBounds(object)) == sfTrue)
		sfRenderWindow_drawShape(win_info->w, object, state);
}

void Call_sfText(wc_t *win_info, const sfText *object, sfRenderStates *state)
{
	if (check_inside_window(win_info->r, 
			sfText_getGlobalBounds(object)) == sfTrue)
		sfRenderWindow_drawText(win_info->w, object, state);
}

void Call_sfSprite(wc_t *win_info, sfSprite *object, sfRenderStates *state)
{
	if (check_inside_window(win_info->r, 
			sfSprite_getGlobalBounds(object)) == sfTrue)
		sfRenderWindow_drawSprite(win_info->w, object, state);
}