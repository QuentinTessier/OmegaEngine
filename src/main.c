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
#include "Object.h"

int main(void)
{
	root_t game;
	sfVector2u game_size = {1280, 720};
	create_root(&game, game_size, "NAME", sfClose);
	game.CreateSceneGraph(&game, 1);
	Create_scene(&game.s_graph[0], 3);
	scene_t *s = game.s_graph[0];
	object_t *test = OB_ERROR(s->AddSortedObject(&s->l_ob[0], 10))->AsTexture(&test, "assets/cube.png", NULL);
	//game.WindowLoop(&game);

	return (0);
}

/*

simple linked list order on rendering depth

0 --------------------------- 5000 >|_|

AddSortedObject(Headref **, Node *);

Renderer goes down the linked list

object_t *test = OB_ERROR(s->AddSortedObject(&s->l_ob[0], 10))->Bool_Render(&test);

*/