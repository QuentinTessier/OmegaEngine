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
#include <fcntl.h>
#include <unistd.h>
#include "libs/jsmn.h"
#include "errno.h"
#include "core/renderer/OmDrawable.h"
#include "core/renderer/OmTexture.h"

static char buffer[4096];
static int h = 0;

static int jsoneq(const char *json, jsmntok_t *tok, const char *s)
{
    if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
                    strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
        return (0);
    }
    return (-1);
}

char *get_string(const char *buffer, int start, int end)
{
    char *tmp = malloc(sizeof(char) * end - start + 1);

    memset(tmp, 0, end - start + 1);
    strncpy(tmp, buffer + start, end - start);
    return (tmp);
}

void import_shaders(OmDrawableS *object)
{
    char *vertex = 0;
    char *geometry = 0;
    char *fragment = 0;

    if (object->parser_infos->shaders_paths[0][0] != 0)
        vertex = object->parser_infos->shaders_paths[0];
    if (object->parser_infos->shaders_paths[1][0] != 0)
        geometry = object->parser_infos->shaders_paths[1];
    if (object->parser_infos->shaders_paths[2][0] != 0)
        fragment = object->parser_infos->shaders_paths[2];
    object->parser_infos->shaders = sfShader_createFromFile(vertex, geometry, fragment);
    object->states.shader = object->parser_infos->shaders;
}

void import_texture(OmDrawableS *object, OmHashS *textures)
{
    if (strlen(object->parser_infos->path) != 0) {
        OmTexture.set(textures, object->parser_infos->path, object->parser_infos->path);
        object->states.texture = OmTexture.get(textures, object->parser_infos->path);
    }
}

OmDrawableS OmDrawable_ImportFromFile(const char *path, const char *object_name, OmHashS *textures)
{
    int r;
    jsmn_parser p;
    jsmntok_t t[128];
    jsmntok_t *g;
    OmDrawableS object = OmDrawable.new(sfTriangles);
    int fd = 0;
    size_t r_size = 0;
    int inside = 1;
    int curr_vert = 0;

    jsmn_init(&p);
    fd = open(path, O_RDONLY);
    r_size = read(fd, buffer, 4096);
    r = jsmn_parse(&p, buffer, r_size, t, sizeof(t)/sizeof(t[0]));
    if (r < 0) {
        printf("Failed to parse JSON : %d\n", r);
        return (object);
    }
    object.parser_infos = malloc(sizeof(OmObParserS));
    for (int i = 0; i < r; i++) {
        if (jsoneq(buffer, &t[i], object_name) == 0)
            inside = 0;
        else if (inside)
            continue;
        if (jsoneq(buffer, &t[i], "Texture") == 0) {
            object.parser_infos->path = get_string(buffer, t[i + 1].start, t[i + 1].end);
        }
        if (jsoneq(buffer, &t[i], "Shaders") == 0) {
            for (int j = 0; j < t[i + 1].size; j++) {
                g = &t[i + j + 2];
                memset(object.parser_infos->shaders_paths[j], 0, 256);
                strncpy(object.parser_infos->shaders_paths[j], buffer + g->start, g->end - g->start);
            }
            i += t[i + 1].size + 1;
        }
        if (jsoneq(buffer, &t[i], "Primitive") == 0) {
            object.type = atoi(buffer + t[i + 1].start);
            i++;
        }
        if (jsoneq(buffer, &t[i], "Offset") == 0) {
            object.offset = atoi(buffer + t[i + 1].start);
            i++;
        }
        if (jsoneq(buffer, &t[i], "Count") == 0) {
            object.count = atoi(buffer + t[i + 1].start);
            object.vertices = malloc(sizeof(sfVertex) * object.count);
            i++;
        }
        if (jsoneq(buffer, &t[i], "Vertices") == 0) {
            for (int j = 0; j < t[i + 1].size; j++) {
                h++;
                object.vertices[curr_vert].position.x = atof(buffer + t[i + j + h + 3].start);
                h += 2;
                object.vertices[curr_vert].position.y = atof(buffer + t[i + j + h + 3].start);
                h += 2;
                object.vertices[curr_vert].color.r = atoi(buffer + t[i + j + h + 3].start);
                h += 2;
                object.vertices[curr_vert].color.g = atoi(buffer + t[i + j + h + 3].start);
                h += 2;
                object.vertices[curr_vert].color.b = atoi(buffer + t[i + j + h + 3].start);
                h += 2;
                object.vertices[curr_vert].color.a = atoi(buffer + t[i + j + h + 3].start);
                h += 2;
                object.vertices[curr_vert].texCoords.x = atof(buffer + t[i + j + h + 3].start);
                h += 2;
                object.vertices[curr_vert].texCoords.y = atof(buffer + t[i + j + h + 3].start);
                curr_vert++;
                h++;
            }
        }
    }
    import_texture(&object, textures);
    import_shaders(&object);
    return (object);
}