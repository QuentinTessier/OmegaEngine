/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <time.h>
#include "data_structure/OmHash.h"
#include "core/renderer/OmTexture.h"
#include "OmEngine.h"

void OmEvent_Process(OmWindowS *main_window, struct OmEvent_Storage *events)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(main_window->window, &event)) {
        OmEvent_Processor(main_window, event, events);
    }
}

void game_loop(OmWindowS *main_window, struct OmEvent_Storage *events)
{
    OmDrawableS trunk = OmDrawable.ImportFromFile("./assets/tree.json", "Trunk", NULL);
    OmDrawableS foliage = OmDrawable.ImportFromFile("./assets/tree.json", "Foliage", NULL);
    OmRendererS *r = OmRenderer.create(10);
    float move = 1.0f;
    float update_time = 0.f;

    while (sfRenderWindow_isOpen(main_window->window)) {
        OmEvent_Process(main_window, events);
        sfRenderWindow_clear(main_window->window, sfBlack);
        sfShader_setFloatUniform(foliage.parser_infos->shaders, "Time", sfTime_asSeconds(sfClock_getElapsedTime(main_window->clock)));
        OmRenderer.push(r, trunk);
        OmRenderer.push(r, foliage);
        OmRenderer.draw(r, main_window->window);
        sfRenderWindow_display(main_window->window);
    }
}

int main(int ac, char **av)
{
    OmWindowS main_window = OmEngine_Init();
    struct OmEvent_Storage events = OmEngine_InitEvent();

    srand(time(NULL));
    game_loop(&main_window, &events);
    return (0);
}