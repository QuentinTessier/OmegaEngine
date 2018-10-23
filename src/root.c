/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** root
*/

#include <stdlib.h>
#include <unistd.h>
#include "root.h"
#include "error.h"

static const root_t root_ptr_init = {
    NULL, {0, 0}, NULL, 0, 0, NULL, &root_launch_loop,
    &root_create_scene_array, &root_add_scene_at_index
};

root_t create_root(root_t self, sfVector2u size, char *name, sfUint32 style)
{
    self = root_ptr_init;

    SF_CALL(self.w_win = sfRenderWindow_create((sfVideoMode){size.x, size.y, 32},
            name, style, NULL));
    self.w_name = name;
    self.w_size = size;
    self.s_graph = NULL;
    return (self);
}

root_t *root_create_scene_array(root_t *self, int nb, int focus_scene)
{
    int error;

    if (self->s_graph == NULL) {
        self->s_max = nb;
        PTR_CALL(self->s_graph = malloc(sizeof(scene_t *) * nb));
        POP_ERROR(error);
        if (error != NO_ERROR)
            exit (84);
        self->s_current = focus_scene;
        for (int i = 0; i < nb; i++)
            self->s_graph[i] = NULL;
        return (self);
    }
    write(2, "Warning, scene array already initializied\n", 42);
    return (self);
}

root_t *root_add_scene_at_index(root_t *self, int index, scene_t *new)
{
    if (self->s_graph[index] != NULL) {
        write(2, "Warning : You overided a scene.\n", 32);
        free(self->s_graph[index]);
    }
    self->s_graph[index] = new;
    return (self);
}

void root_event(root_t *self)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(self->w_win, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(self->w_win);
        }
    }
}

void root_launch_loop(root_t *self)
{
    while (sfRenderWindow_isOpen(self->w_win)) {
        root_event(self);
        sfRenderWindow_clear(self->w_win, sfBlack);
        //self->s_graph[self->s_current]->draw(self->s_graph[self->s_current], self);
        sfRenderWindow_display(self->w_win);
    }
}