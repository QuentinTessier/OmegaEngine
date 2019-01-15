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

static const char JSON_ID[5][10] = {
    "Texture", "Shaders", "Primitive", "Offset", "Vertices"
};

int jsoneq(const char *json, jsmntok_t *tok, const char *s)
{
    if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
            strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
        return (0);
    }
    return (-1);
}

char *readFile(const char *path)
{
	int fd = open(path, O_RDONLY);
	char *contents = 0;
	char buffer[2048] = {0};
	ssize_t bytes = 1;

	if (fd == -1)
		return (0);
	contents = strdup("");
	bytes = read(fd, buffer, 2048);
	while (bytes > 0) {
		buffer[bytes] = 0;
		contents = (char *)realloc(contents,
					sizeof(char) *
						strlen(contents) + strlen(buffer) + 1);
		strcat(contents, buffer);
		bytes = read(fd, buffer, 2048);
	}
	if (bytes == -1) {
		free(contents);
		contents = 0;
	}
	return (contents);
}

int search_object(jsmntok_t *t, const char *object_name, const char *json, ssize_t r_size)
{
    for (int i = 1; i < r_size; i++) {
        if (jsoneq(json, &t[i], object_name) == 0) {
            return (i);
        }
    }
    return (-1);
}

void parser_vertices(OmDrawableS *object, const char *json, jsmntok_t *t, ssize_t r_size, int i)
{
    unsigned int curr_vertex = 0;

    if (object->count == 0)
        return;
    object->vertices = malloc(sizeof(sfVertex) * object->count);
    for (int j = i; j < r_size; j++) {
        if (curr_vertex == object->count)
            break;
        if (jsoneq(json, &t[j], "PositionX") == 0)
            object->vertices[curr_vertex].position.x = atof(json + t[j + 1].start);
        else if (jsoneq(json, &t[j], "PositionY") == 0)
            object->vertices[curr_vertex].position.y = atof(json + t[j + 1].start);
        else if (jsoneq(json, &t[j], "ColorR") == 0)
            object->vertices[curr_vertex].color.r = atoi(json + t[j + 1].start);
        else if (jsoneq(json, &t[j], "ColorG") == 0)
            object->vertices[curr_vertex].color.g = atoi(json + t[j + 1].start);
        else if (jsoneq(json, &t[j], "ColorB") == 0)
            object->vertices[curr_vertex].color.b = atoi(json + t[j + 1].start);
        else if (jsoneq(json, &t[j], "ColorA") == 0)
            object->vertices[curr_vertex].color.a = atoi(json + t[j + 1].start);
        else if (jsoneq(json, &t[j], "TexCoordsX") == 0)
            object->vertices[curr_vertex].texCoords.x = atof(json + t[j + 1].start);
        else if (jsoneq(json, &t[j], "TexCoordsY") == 0) {
            object->vertices[curr_vertex].texCoords.y = atof(json + t[j + 1].start);
            curr_vertex++;
        }
    }
}

void parser(OmDrawableS *object, const char *json, jsmntok_t *t, ssize_t r_size, int i)
{
    for (int j = i; j < r_size; j++) {
        if (jsoneq(json, &t[j], JSON_ID[0]) == 0) {
            memset(object->parser_infos->path, 0, 256);
            strncpy(object->parser_infos->path, json + t[j + 1].start, t[j + 1].end - t[j + 1].start);
            j++;
        }
        if (jsoneq(json, &t[j], JSON_ID[1]) == 0) {
            memset(object->parser_infos->shaders_paths[0], 0, 256);
            strncpy(object->parser_infos->shaders_paths[0], json + t[j + 2].start, t[j + 2].end - t[j + 2].start);
            memset(object->parser_infos->shaders_paths[1], 0, 256);
            strncpy(object->parser_infos->shaders_paths[1], json + t[j + 3].start, t[j + 3].end - t[j + 3].start);
            memset(object->parser_infos->shaders_paths[2], 0, 256);
            strncpy(object->parser_infos->shaders_paths[2], json + t[j + 4].start, t[j + 4].end - t[j + 4].start);
            j += t[j + 1].size + 1;
        }
        if (jsoneq(json, &t[j], JSON_ID[2]) == 0) {
            object->type = atoi(json + t[j + 1].start);
        }
        if (jsoneq(json, &t[j], JSON_ID[3]) == 0)
            object->offset = atoi(json + t[j + 1].start);
        if (jsoneq(json, &t[j], JSON_ID[4]) == 0) {
            object->count = t[j + 1].size;
            parser_vertices(object, json, t, r_size, j);
            break;
        }
    }
}

void load_shaders_texture(OmDrawableS *object)
{
    char *vert = 0;
    char *frag = 0;
    char *geom = 0;

    if (object->parser_infos->shaders_paths[0][0] != 0)
        vert = object->parser_infos->shaders_paths[0];
    if (object->parser_infos->shaders_paths[1][0] != 0)
        geom = object->parser_infos->shaders_paths[1];
    if (object->parser_infos->shaders_paths[2][0] != 0)
        frag = object->parser_infos->shaders_paths[2];
    object->parser_infos->shaders = sfShader_createFromFile(vert, geom, frag);
    object->states.shader = object->parser_infos->shaders;
    if (object->parser_infos->path[0] != 0) {
        object->parser_infos->texture = sfTexture_createFromFile(object->parser_infos->path, NULL);
        object->states.texture = object->parser_infos->texture;
    }
}

OmDrawableS OmDrawable_ImportFromFile(const char *path, const char *object_name, OmHashS *textures)
{
    char *json = readFile(path);
    jsmntok_t t[4096];
    ssize_t r_size = 0;
    jsmn_parser p;
    OmDrawableS object = OmDrawable.new(sfTriangles);
    int i = 0;

    (void)textures;
    if (json == 0)
        return (object);
    jsmn_init(&p);
    r_size = jsmn_parse(&p, json, strlen(json), t, sizeof(t)/sizeof(t[0]));
    if (r_size < 0) {
        dprintf(2, "Failed to parser JSON\n");
        return (object);
    }
    i = search_object(t, object_name, json, r_size);
    object.parser_infos = malloc(sizeof(OmObParserS));
    parser(&object, json, t, r_size, i);
    load_shaders_texture(&object);
    return (object);
}