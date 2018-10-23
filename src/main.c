/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "root.h"
#include "object.h"
#include "error.h"

int main()
{
    root_t root = create_root(root, (sfVector2u){1280, 720}, "NAME", sfClose);

    root.create_scene_array(&root, 1, 0)->add_scene_index(&root, 0, create_scene());
    root.s_graph[0]->scene_add_object(root.s_graph[0], create_object(1));

    root.launch_loop(&root);
    return (0);
}