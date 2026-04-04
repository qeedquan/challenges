/*

Context
In Dungeons and Dragons, a tabletop roleplaying game, movement is limited in combat. Characters can only move a set amount of distance per turn, meaning the distance you travel is very important.

In the 5th edition of the rulebook, the board is commonly organized into a grid, but for ease of counting, movement is non-euclidian. Each square is 5 ft, and moving diagonally counts the same as moving in a cardinal direction.

+------------------------+
| 10 | 10 | 10 | 10 | 10 |
+------------------------+
| 10 |  5 |  5 |  5 | 10 |
+------------------------+
| 10 |  5 | :) |  5 | 10 |
+------------------------+
| 10 |  5 |  5 |  5 | 10 |
+------------------------+
| 10 | 10 | 10 | 10 | 10 |
+------------------------+

Distance of each grid cell from the player, in feet

Your task
Create an algorithm to calculate the distance of a movement path. You will be provided with the path as a series of absolute grid points (x, y, z). Take in to account both horizontal (x, y) as well as vertical (z) movement. Vertical movement is governed by the same rules, for the sake of simplicity.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	int x, y, z;
} Vec3;

Vec3
vecabs(Vec3 vec)
{
	vec.x = abs(vec.x);
	vec.y = abs(vec.y);
	vec.z = abs(vec.z);
	return vec;
}

Vec3
vecsub(Vec3 vec0, Vec3 vec1)
{
	return (Vec3){
		vec0.x - vec1.x,
		vec0.y - vec1.y,
		vec0.z - vec1.z,
	};
}

int
vecmaxcomp(Vec3 vec)
{
	return max(vec.x, max(vec.y, vec.z));
}

int
distance(Vec3 *path, size_t pathlen)
{
	size_t i;
	Vec3 delta;
	int total;

	total = 0;
	for (i = 1; i < pathlen; i++) {
		delta = vecsub(path[i], path[i - 1]);
		delta = vecabs(delta);
		total += vecmaxcomp(delta) * 5;
	}
	return total;
}

int
main()
{
	Vec3 path_1[] = { { 2, 2, 0 }, { 1, 2, 0 } };
	Vec3 path_2[] = { { 2, 2, 0 }, { 0, 2, 0 } };

	Vec3 path_3[] = { { 0, 0, 0 }, { 0, 0, 3 } };
	Vec3 path_4[] = { { 0, 0, 0 }, { 1, 4, 5 } };

	Vec3 path_5[] = { { 0, 0, 0 }, { -2, -1, 0 } };
	Vec3 path_6[] = { { 0, 0, 0 }, { -3, -4, -2 } };

	Vec3 path_7[] = { { 0, 0, 0 }, { 4, 0, 0 }, { 0, 2, 0 }, { 0, 0, 0 } };

	assert(distance(path_1, nelem(path_1)) == 5);
	assert(distance(path_2, nelem(path_2)) == 10);

	assert(distance(path_3, nelem(path_3)) == 15);
	assert(distance(path_4, nelem(path_4)) == 25);

	assert(distance(path_5, nelem(path_5)) == 10);
	assert(distance(path_6, nelem(path_6)) == 20);

	assert(distance(path_7, nelem(path_7)) == 50);

	return 0;
}
