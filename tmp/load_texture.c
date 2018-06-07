/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** load_texture
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "engine.h"

int my_strlen(const char *s)
{
	int i = 0;

	while (s && s[i])
		i++;
	return (i);
}

int key_word_check(char *name)
{
	char cmp[5] = "tile_";

	for (int i = 0; i < 5; i++) {
		if (name[i] != cmp[i])
			return (1);
	}
	return (0);
}

char *add_name(char *dirpath, char *name)
{
	char *result = malloc(sizeof(char) * my_strlen(dirpath) + my_strlen(name) + 1);
	int i = 0;
	int j = 0;

	for (i = 0; i < my_strlen(dirpath); i++) {
		result[i] = dirpath[i];
	}
	for (j = 0; j < my_strlen(name); j++) {
		result[i + j] = name[j];
 	}
	result[i + j] = '\0';
	return (result);
}

t_t load_textures(char *dirpath)
{
	DIR *dir = opendir(dirpath);
	t_t tex;
	sfIntRect r = {0, 0, S_V, S_V};
	struct dirent *ent;
	int i = 0;

	tex.t = malloc(sizeof(sfTexture *) * TEX_NB);

	while ((ent = readdir(dir)) != NULL) {
		if (key_word_check(ent->d_name) == 0) {
			tex.t[i] = sfTexture_createFromFile(add_name(dirpath, ent->d_name), &r);
			i++;
		}
	}
	return (tex);
}