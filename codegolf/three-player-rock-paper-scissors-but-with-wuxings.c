/*

Objective
Given a list of three Wuxings, compare them in rock-paper-scissors fashion, and output which Wuxing is the winner.

Wuxings
Wuxings(五行) are the five "elements" in Chinese philosophy. They are Fire(火), Water(水), Wood(木), Metal(金), and Soil(土).

Positive actions
A positively acted Wuxing gains 1 point.

Fire fertilizes Soil.
Soil incubates Metal.
Metal is a container for Water.
Water nourishes Wood.
Wood fuels Fire.
Negative actions
A negatively acted Wuxing loses 1 point.

Fire melts Metal.
Metal chops Wood.
Wood penetrates Soil.
Soil blocks Water.
Water extinguishes Fire.
I/O format
You can encode the Wuxings freely, but you must represent each Wuxing consistently in the input and the output.

The inputted list is not assumed to be sorted.

Otherwise Flexible.

Examples
Input, Score, Winner

[Fire, Water, Wood], [0, 0, +1], Wood
[Fire, Water, Metal], [-1, +1, -1], Water
[Fire, Fire, Water], [-1, -1, 0], Water
[Fire, Water, Water], [-2, 0, 0], Water
[Fire, Fire, Wood], [+1, +1, 0], Fire
[Fire, Wood, Wood], [+2, 0, 0], Fire
[Fire, Fire, Fire], [0, 0, 0], Fire

Note that this exhausts all possibilities up to symmetry, and every case admits a unique winner.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long vlong;

enum {
	FIRE = 0,
	SOIL,
	METAL,
	WATER,
	WOOD
};

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

/*

@Arnauld

Mapping: 0, 1, 2, 3, 4 → Fire, Soil, Metal, Water, Wood.

Method
Once the input array is sorted in ascending order, there are only 35 possible cases that can be identified with the concatenation of the values:

000, 001, ..., 333, 334, 344, 444
It turns out that it's quite efficient to use a modulo chain on this identifier, combined with a bitmask encoding the position of the answer in the sorted array.

It's worth noting that we may have several possibilities for the position (e.g. for 000 all positions are correct).
This potentially allows us to optimize the collisions in the lookup data.
But in practice, taking the first matching position is apparently just as good.

*/

int
score(int x[3])
{
	vlong i;

	qsort(x, 3, sizeof(*x), cmp);
	i = x[2] + (x[1] * 10) + (x[0] * 100);
	i = (88614024 >> (((i % 37) % 14)) * 2) & 3;
	return x[i];
}

int
main()
{
	int x1[] = { FIRE, WATER, WOOD };
	int x2[] = { FIRE, WATER, METAL };
	int x3[] = { FIRE, FIRE, WATER };
	int x4[] = { FIRE, WATER, WATER };
	int x5[] = { FIRE, FIRE, WOOD };
	int x6[] = { FIRE, WOOD, WOOD };
	int x7[] = { FIRE, FIRE, FIRE };
	int x8[] = { WATER, WATER, WATER };
	int x9[] = { SOIL, SOIL, SOIL };
	int x10[] = { WOOD, WOOD, WOOD };

	assert(score(x1) == WOOD);
	assert(score(x2) == WATER);
	assert(score(x3) == WATER);
	assert(score(x4) == WATER);
	assert(score(x5) == FIRE);
	assert(score(x6) == FIRE);
	assert(score(x7) == FIRE);
	assert(score(x8) == WATER);
	assert(score(x9) == SOIL);
	assert(score(x10) == WOOD);

	return 0;
}
