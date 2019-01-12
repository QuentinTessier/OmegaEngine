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

static char buffer[4096];
static char tmp_float[256];
static int h = 0;

/*static void parse_texture(OmDrawableS *object, const char *str)
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

int Parse_file(FILE *fd, OmDrawableS *object)
{
    char *str = 0;
    size_t len = 0;
    int parsing_error = 0;

    errno = 0;
    while (getline(&str, &len, fd) != -1) {
        if (str[0] == '\n' || str[0] == '#') {
            free(str);
            continue;
        }
        if (parse_info(object, str) == 1) {
            parsing_error = 1;
            break;
        }
        if (parsing_error == 2) {

        }
    }
    if (parsing_error == 1)
        dprintf(2, "A parsing error occured\n");
    if (errno != 0)
        dprintf(2, "Errno reported a error with message :\n%s\n", strerror(errno));
    return (0);
}

OmDrawableS OmDrawable_ImportFromFile(const char *path)
{
    FILE *fd = fopen(path , "r");
    OmDrawableS object = OmDrawable.new(sfTriangles);

    if (fd == 0) {
        dprintf(2, "Failed to open file : %s\n", path);
        return (object);
    }
    object.parser_infos = malloc(sizeof(OmObParserS));
    object.parser_infos = memset(object.parser_infos, 0, sizeof(OmObParserS));
    Parse_file(fd, &object);
}*/

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

OmDrawableS OmDrawable_ImportFromFile(const char *path, const char *object_name)
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
    if (strlen(object.parser_infos->path) != 0) {
        object.parser_infos->texture = sfTexture_createFromFile(object.parser_infos->path, NULL);
        object.states.texture = object.parser_infos->texture;
    }
    import_shaders(&object);
    return (object);
}