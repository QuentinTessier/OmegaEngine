/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** error
*/

#include <unistd.h>
#include "error.h"

static const char *messages[] = {
    "No Error\n",
    "Error : malloc failed\n",
    "Error : CSFML failed to create element\n"
};

void error_report()
{
    int error = 0;
    int sizes[3] = {9, 22, 39};
    int i = 0;

    do {
        POP_ERROR(error);
        write(2, messages[error], sizes[error]);
        i++;
    } while (error != NO_ERROR);
}