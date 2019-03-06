/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Window
*/

#pragma once

#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct OmWindow {
    sfRenderWindow *Window;
    struct {
        sfVector2i Curr_Pos;
        sfVector2i Old_Pos;
        bool Left_Pressed;
        bool Right_Pressed;
    } Mouse;
    sfClock *Time;
} OmWindow;