/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** load
*/

#ifndef LOAD_H_
	#define LOAD_H_


#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

	#define NB_SPR_BACKGROUND (3)
	#define HERO_SPR_PATH ("./assets/tile_rock.png")

/* Array of background textures */
static const char backarray[1][30] = {{"Selection_005.png"}};

#define BACKARRAY(a) (backarray[a])

static const sfVector2f backvarray[1] = {{0, 0}};

/* Array of background textures */
static const char middlearray[1][30] = {{"prone_0.png"}};

#define MIDARRAY(a) (middlearray[a])

static const sfVector2f middlevarray[1] = {{64, 64}};

/* Array of background textures */
static const char forearray[3][30] = {{"tile_dirt.png\0"}, {"tile_rock.png\0"}, {"tile_grass.png\0"}};

#define FOREARRAY(a) (forearray[a])

static const sfVector2f forevarray[3] = {{-65, -65}, {64, 0}, {0, 64}};

/* Rectangle for the sprites */
static const sfIntRect hero_rect = {0, 0, 64, 64};
static const sfIntRect all_img = {0, 0, 0, 0}; // Load the all img

// Create your custom rectangle here for animated sprite

/* Position Vector for the sprites */
static const sfVector2f hero_pos = {0, 0};

// Change the base position of a object here


#endif /* !LOAD_H_ */
