/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Window
*/

#pragma once

#include <SFML/Graphics.h>

typedef struct OmWindow {
    sfRenderWindow *Window;

    sfClock *Time;
} OmWindow;