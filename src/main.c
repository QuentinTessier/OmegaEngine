/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sysinfo.h>
#include "Root.h"
#include "Scene.h"

int main(void)
{
	root_t game;
	sfVector2u game_size = {1290, 720};
	create_root(&game, game_size, "NAME", sfClose | sfResize);
	game.CreateSceneGraph(&game, 2);

	Create_scene(&game.s_graph[0], 10);
	Create_scene(&game.s_graph[1], 20);
	game.WindowLoop(&game);

	return (0);
}