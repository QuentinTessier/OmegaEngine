/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** main
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <string.h>
#include <pthread.h>
#include "engine/message/message.h"
#include "engine/utility/vector.h"

void audio_engine(void *queue)
{
    OmQHeader *q = queue;
    OmMessage *tmp = 0;
    int run = 1;

    while (run) {
        tmp = OmQueue.pop(q);
        if (tmp == NULL)
            continue;
        if (tmp->data_use == 1)
            printf("Play\n");
        if (tmp->data_use == 0)
            printf("Pause\n");
        if (tmp->data_use == -1) {
            run = 0;
            printf("Terminate\n");
        }
        delete_message(tmp);
    }
    return;
}

void loop(sfRenderWindow *win, OmQHeader *handle)
{
    sfEvent event;
    sfThread *audio = sfThread_create(&audio_engine, handle);

    sfThread_launch(audio);
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(win);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
                OmQueue.push(handle, create_message("MySong", 1, 0));
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ)
                OmQueue.push(handle, create_message("MySong", 0, 0));
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_display(win);
    }
    OmQueue.push(handle, create_message("Terminate", -1, 0));
    sfThread_wait(audio);
    sfThread_destroy(audio);
    sfRenderWindow_destroy(win);
    OmQueue.destroy(handle);
}

int main()
{
    sfRenderWindow *win = sfRenderWindow_create((sfVideoMode){800, 600, 32},
                            "MultiThreadedAudioTest", sfClose, NULL);
    OmQHeader *handle = OmQueue.create();
    loop(win, handle);
    return (0);
}