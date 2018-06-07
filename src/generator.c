/*
** EPITECH PROJECT, 2018
** Infinite_World
** File description:
** generator
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "engine.h"

static int seed = 0;

static double IntergerNoise(int n)
{
	int nn;

	n = (n << 015) ^ n;
	nn = ((n * (n * n * 60493 + 19990303) + 1376312589) & 0x7fffffff);
	return (1.0 - ((double)nn / 1073741824.0) * 5);
}

static double noise2d(int x, int y)
{
	int tmp = IntergerNoise(x) * 850000;

	return (IntergerNoise(tmp + y + seed));
}

static double CoherentNoise(double x, double y)
{
	int X = (int)(floor(x));
	int Y = (int)(floor(y));
	double n_a = noise2d(X, Y);
	double n_b = noise2d(X + 1, Y);
	double n_c = noise2d(X, Y + 1);
	double n_d = noise2d(X + 1, Y + 1);
	double weight_a = x - floor(x);
	double weight_b = y - floor(y);
	double noise_a = LERP(n_a, n_b, SCURVE(weight_a));
	double noise_b = LERP(n_c, n_d, SCURVE(weight_a));
	double noise = SMOOTH(noise_a, noise_b, SCURVE(weight_b));

	return (noise);
}

double *generator(int x, int y, int px, int py)
{
	double *map = malloc(sizeof(double) * x * y);
	int count = 0;
	int tmp = px;
	int j = 0;

	if (seed == 0)
		seed = rand() % 3000 + 1;
	for (int i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			map[count + j] = CoherentNoise((double)px, (double)py); 
			px++;
		}
		count += j;
		j = 0;
		px = tmp;
		py++;
	}
	return (map);
}