/*
** EPITECH PROJECT, 2018
** CSFML_2D_ENGINE
** File description:
** error
*/

#include <stdlib.h>
#include <unistd.h>
#include "Object.h"

static void *my_memset(void *ptr, int data, unsigned int size)
{
	char * _s = ptr;
	unsigned char _c = data;

	while (size--)
		*_s++ = _c;
	return (_s);
}

static int Get_mod(int a)
{
	int count = 1;

	if (a < 0)
		a = -a;
	while (a > 0) {
		a /= 10;
		count *= 10;
	}
	return (count / 10);
}

static int my_strlen(const char *s)
{
	int i = 0;

	while (s && s[i])
		i++;
	return (i);
}

static void print_int(int nb)
{
	char *deci = malloc(sizeof(char) * 11);
	int tmp = Get_mod(nb);
	char c;
	int i = 0;

	my_memset(deci, '\0', 11);
	if (nb < 0) {
		write(1, "-", 1);
		i++;
		nb = -nb;
	}
	for (i = i; tmp > 0; i++) {
		c = nb / tmp + '0';
		deci[i] = c;
		nb -= (nb / tmp) * tmp;
		tmp /= 10;
	}
	write(2, deci, my_strlen(deci));
	free(deci);
}

static const char ob_error_message[6][10] = {
	"SPRITE\0", "CIRCLE\0", "RECTANGLE\0", "SHAPE\0", "CONVEX\0", "TEXTURE\0",
};

void ob_report_error(int type, int depth)
{
	if (type == -1) {
		write(2, "ERROR : trying to create a object with no type, ", 48);
		write(2, "if you are using a custom type don't forget to ", 47);
		write(2, "set it's type to OB_CUSTOM[NUMBER]\n", 35);
		return;
	}
	write(2, "ERROR : Couldn't initialize object : [ ", 39);
	write(2, ob_error_message[type], my_strlen(ob_error_message[type]));
	write(2, " ] at depth : [ ", 16);
	print_int(depth);
	write(2, " ]\n", 3);
}