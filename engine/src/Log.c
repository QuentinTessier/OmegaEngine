/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** Log
*/

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "Log.h"

static void OmLog_Tag(FILE *fd, int Tag)
{
    if (Tag == LTAG_ERROR) {
        fprintf(fd, "%s", LOG_ERROR);
    } else if (Tag == LTAG_WARNING) {
        fprintf(fd, "%s", LOG_WARNING);
    } else if (Tag == LTAG_INFO) {
        fprintf(fd, "%s", LOG_INFO);
    } else {
        fprintf(fd, "%s", LOG_SUCCESS);
    }
}

static char *OmLog_GenerateFile(int PID)
{
    char *tmp = calloc(sizeof(char), 64);
    char *nb = calloc(sizeof(char), 32);

    sprintf(nb, "%d", PID);
    strcpy(tmp, LOG_FILE);
    strcat(tmp, "log.");
    strcat(tmp, nb);
    free(nb);
    return (tmp);
}

void OmLog_Log(int Tag, const char *Format, ...)
{
    char *path = 0;
    static FILE *fd = 0;
    va_list List;
    va_list List2;

    va_start(List, Format);
    va_copy(List2, List);
    if (LOG_TO_CONSOLE) {
        OmLog_Tag(stderr, Tag);
        vfprintf(stderr, Format, List);
    }
    if (LOG_TO_FILE) {
        if (fd == 0) {
            path = OmLog_GenerateFile(getpid());
            fd = fopen(path, "a+");
            free(path);
        }
        if (fd == 0) {
            dprintf(2, "%sCouldn't open or create log file\n", LOG_INFO);
            return;
        }
        OmLog_Tag(fd, Tag);
        vfprintf(fd, Format, List2);
    }
    va_end(List);
    va_end(List2);
}