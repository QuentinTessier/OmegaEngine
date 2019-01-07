/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include "utility/hashmap.h"
#include "OmEngine.h"

int main(int ac, char **av)
{
    OmWindowS main_window = OmEngine_Init();
    OmHashS *main_data = OmHash.with_capicity(BASE_HASH_SIZE);

    OmEngine_InitData(&main_window, main_data);
    return (0);
}