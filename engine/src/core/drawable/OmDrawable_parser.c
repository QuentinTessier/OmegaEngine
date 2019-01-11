/*
** EPITECH PROJECT, 2019
** OmegaEngine
** File description:
** OmDrawable_parser
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errno.h"
#include "core/renderer/OmDrawable.h"

static void parse_texture(OmDrawableS *object, const char *str)
{
    int i = 0;
    char *path = 0;

    while (str[i])
        i++;
    path = malloc(sizeof(char) * i - 1);
    strncpy(path, str, i - 1);
    path[i - 2] = 0;
    object->parser_infos->texture = sfTexture_createFromFile(path, NULL);
    object->states.texture = object->parser_infos->texture;
}

static void parse_shaders(OmDrawableS *object, const char *str)
{
    int i = 0;
    int h = 0;

    for (int j = 0; j < 3; j++) {
        while (str[h + i] != 34) {
            if (str[h + i] == 0)
                break;
            i++;
        }
        strncpy(object->parser_infos->shaders_paths[j], str + h, i);
        object->parser_infos->shaders_paths[j][i] = 0;
        h += (i + 3);
        i = 0;
    }
}

static int parse_info(OmDrawableS *object, const char *str)
{
    switch (str[0]) {
        case 'T' :
            parse_texture(object, str + 3);
            return 0;
        case 'S' :
            parse_shaders(object, str + 3);
            return 0;
        case 'C' :
            object->count = atoi(str + 2);
            object->vertices = malloc(sizeof(sfVertex) * object->count);
            return 0;
        case 'O':
            object->offset = atoi(str + 2);
            return (0);
        case 'P':
            object->type = atoi(str + 2);
            return (0);
        case 'V' :
            return 2;
        case '#' :
            return 0;
        default :
            return 1;
    }
}

sfVertex get_vertex(char *str)
{
    sfVertex ret;
    int i = 0;

    ret.position.x = atof(str);
    for (i = i; str[i] != ','; i++);
    ret.position.y = atof(str + i + 2);
    for (i = i; str[i] != '{'; i++);
    ret.color.r = atoi(str + i + 1);
    for (i = i; str[i] != ','; i++);
    ret.color.g = atoi(str + i + 2);
    i++;
    for (i = i; str[i] != ','; i++);
    ret.color.b = atoi(str + i + 2);
    i++;
    for (i = i; str[i] != ','; i++);
    ret.color.a = atoi(str + i + 2);
    for (i = i; str[i] != '{'; i++);
    ret.texCoords.x = atof(str + i + 1);
    for (i = i; str[i] != ','; i++);
    ret.texCoords.y = atof(str + i + 2);
    return (ret);
}

void parse_vertices(OmDrawableS *object, FILE *fd, char *str)
{
    size_t len = 0;
    int i = 0;

    object->vertices[i++] = get_vertex(str + 3);
    while (getline(&str, &len, fd) != -1) {
        if (i == object->count)
            break;
        object->vertices[i++] = get_vertex(str + 3);
        free(str);
        len = 0;
    }
}

OmDrawableS OmDrawable_ImportFromFile(const char *path)
{
    FILE *fd = 0;
    OmDrawableS object;
    errno = 0;
    char *str = 0;
    size_t len = 0;
    int ret = 0;

    object.parser_infos = malloc(sizeof(OmObParserS));
    object.parser_infos->path = strdup(path);
    fd = fopen(path, "r");
    if (fd == 0)
        return (object);
    while (getline(&str, &len, fd) != -1) {
        if (str == 0)
            break;
        ret = parse_info(&object, str);
        if (ret == 2) {
            parse_vertices(&object, fd, str);
            fclose(fd);
            return (object);
        }
        if (ret == 1)
            break;
        len = 0;
        free(str);
        str = 0;
    }
    fclose(fd);
    if (errno != 0)
        printf("%s\n", strerror(errno));
    return (object);
}