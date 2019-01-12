/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include "data_structure/OmHash.h"
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
    OmDrawableS item = OmDrawable.ImportFromFile("./assets/object.json", "Player");
    OmRendererS *r = OmRenderer.create(10);
    float t = 1;

    while (sfRenderWindow_isOpen(main_window->window)) {
        OmEvent_Process(main_window, events);
        sfRenderWindow_clear(main_window->window, sfBlack);
        if (sfTime_asSeconds(sfClock_getElapsedTime(main_window->clock)) >= t) {
            OmDrawable.move(&item, (sfVector2f){100, 0});
            t += 1;
        }
        OmRenderer.push(r, item);
        OmRenderer.draw(r, main_window->window);
        sfRenderWindow_display(main_window->window);
    }
}

int main(int ac, char **av)
{
    OmWindowS main_window = OmEngine_Init();
    struct OmEvent_Storage events = OmEngine_InitEvent();

    game_loop(&main_window, &events);
    return (0);
}