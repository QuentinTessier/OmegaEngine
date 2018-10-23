/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** error
*/

#pragma once

typedef enum error_id {
    NO_ERROR,
    ERROR_MALLOC,
    ERROR_CSFML
} error_id_t;

static int error_stack[100];
static int error_top = -1;

#define PRINT_ERROR 0

void error_report();

#define POP_ERROR(x)                        \
        if (error_top > -1)                 \
            x = error_stack[error_top--];   \
        else                                \
            x = NO_ERROR;

#define PUSH_ERROR(x)                       \
        if (error_top < 100)                \
            error_stack[++error_top] = x;

#define PTR_CALL(x)                         \
        if ((x) == 0)                       \
            PUSH_ERROR(ERROR_MALLOC);       \
        if (PRINT_ERROR)                    \
            error_report()

#define SF_CALL(x)                          \
        if ((x) == 0)                       \
            PUSH_ERROR(ERROR_CSFML);        \
        if (PRINT_ERROR)                    \
            error_report()