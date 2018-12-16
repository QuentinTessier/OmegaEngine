/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** main
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <string.h>
#include <assert.h>
#include "engine/message/message.h"
#include "engine/utility/hashmap.h"

void audio_loop(void *data)
{
    sfBool run = sfTrue;
    OmMessage *tmp;

    while (run == sfTrue) {
        tmp = OmQueue.pop((OmQHeader *)data);
        if (!tmp)
            continue;
        if (tmp->data_use == 1) {
            printf("Play/Pause\n");
        }
        if (tmp->data_use == 0) {
            run = sfFalse;
            printf("Terminate\n");
        }
    }
    return;
}

void loop(sfRenderWindow *r, OmQHeader *audio_engine)
{
    sfThread *audio = sfThread_create(audio_loop, audio_engine);

    sfThread_launch(audio);
    while (sfRenderWindow_isOpen(r)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(r, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(r);
            if (event.type == sfEvtKeyPressed) {
                OmQueue.push(audio_engine, create_message("Music", 1, 0));
            }
        }
        sfRenderWindow_clear(r, sfBlack);
        sfRenderWindow_display(r);
    }
    OmQueue.push(audio_engine, create_message("Terminate", 0, 0));
    sfThread_wait(audio);
    sfThread_destroy(audio);
    OmQueue.destroy(audio_engine);
    sfRenderWindow_destroy(r);
    return;
}

int main()
{
    OmQHeader *audio_engine = OmQueue.create();
    sfRenderWindow *r = sfRenderWindow_create((sfVideoMode){100, 100, 32}, "NAME", sfClose, NULL);
    loop(r, audio_engine);
    return (0);
}