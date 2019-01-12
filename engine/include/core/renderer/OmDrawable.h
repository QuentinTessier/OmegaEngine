/*
** EPITECH PROJECT, 2018
** OmegaEngine
** File description:
** base_object
*/

#pragma once

#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexBuffer.h>
#include <SFML/Graphics/Shader.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Texture.h>

/*
**  Contain drawable data for the renderer
*/

typedef struct OmObParserS {
    char *path;
    char shaders_paths[3][256];
    sfTexture *texture;
    sfShader *shaders;
} OmObParserS;

typedef struct OmDrawableS {
    sfVertex *vertices;
    unsigned int count;
    unsigned int offset;
    sfPrimitiveType type;
    sfRenderStates states;
    OmObParserS *parser_infos;
} OmDrawableS;

/*
**  This struct contain every functions needed by a OmDrawableS item
*/

typedef struct OmDrawable {
    OmDrawableS (* const new)(sfPrimitiveType type);
    void (* const update_vertices)(OmDrawableS *handle, unsigned int vertices_count, const sfVertex *array, unsigned int offset);
    void (* const update_states)(OmDrawableS *handle, sfShader *shaders, sfTransform matrix, sfTexture *texture);
    OmDrawableS (* const ImportFromFile)(const char *path, const char *object_name);
    void ( * const move)(OmDrawableS *handle, sfVector2f offset);
} _OmDrawable;

extern _OmDrawable const OmDrawable;