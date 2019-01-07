/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** base_engine_func
*/

#include "utility/hashmap.h"
#include "OmEngine.h"

OmWindowS OmEngine_Init(void)
{
    OmWindowS new_window;

    new_window.window = sfRenderWindow_create((sfVideoMode){500, 500, 32}, "Name", sfClose, NULL);
    new_window.clock = sfClock_create();
    new_window.window_size = (sfVector2u){500, 500};
    new_window.window_style = sfClose;
    new_window.renderer = 0;
    new_window.renderer_frequency = 16.0;
    return (new_window);
}

void OmEngine_InitData(OmWindowS *w, OmHashS *hash)
{
    OmHash.set(hash, "1", (void *)0);
}