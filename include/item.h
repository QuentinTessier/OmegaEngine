/*
** EPITECH PROJECT, 2018
** new
** File description:
** item
*/

#ifndef ITEM_H_
	#define ITEM_H_

typedef struct stats {
	int attack;
	int defense;
	int health;
} sta_t;

typedef struct item {
	char *name;
	sta_t *stats;
} it_t;
#endif /* !ITEM_H_ */
