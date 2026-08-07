/*

When making a Dungeons & Dragons character, an alternative to rolling ability scores is to assign them within a power budget called point buy. Higher ability scores cost more points, especially towards the upper end: a score of 8 is free, and raising a score by 1 costs 1 point, except raising to 15 or 16 costs 2 points, and raising to 17 or 18 costs 3 points.

+-------+------+
| Score | Cost |
+-------+------+
|     8 |    0 |
|     9 |    1 |
|    10 |    2 |
|    11 |    3 |
|    12 |    4 |
|    13 |    5 |
|    14 |    6 |
|    15 |    8 |
|    16 |   10 |
|    17 |   13 |
|    18 |   16 |
+-------+------+
In list form:

[(8, 0), (9, 1), (10, 2), (11, 3), (12, 4), (13, 5), (14, 6), (15, 8), (16, 10), (17, 13), (18, 16)]
The point buy cost is summed for all six ability scores.

Ability scores: 16   17   8  13   8  12
Point buy cost: 10 + 13 + 0 + 5 + 0 + 4  = 32
Given six ability scores, each 8 through 18, output the total point buy cost. Fewest bytes wins.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
buycost(int *a, size_t n)
{
	static const int tab[] = {0, 1, 2, 3, 4, 5, 6, 8, 10, 13, 16};

	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		if (8 <= a[i] && a[i] <= 18)
			r += tab[a[i] - 8];
	}
	return r;
}

int
main(void)
{
	int a1[] = {16, 17, 8, 13, 8, 12};

	assert(buycost(a1, nelem(a1)) == 32);

	return 0;
}
