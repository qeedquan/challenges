/*

Problem
Given positive integers a and b, we want to write a function that calculates the number of possible sets (x, y, z) of positive integers `x ≤ y ≤ z such that:

x + y + z = a
x * y * z = b

Note that each set (x, y, z) is unique up to permutation. (E.g. if x = y, then (x, y, z) and (y, x, z) count as one and the same solution)

Examples
If a = 19 and b = 144, then the solutions are (2, 8, 9) and (3, 4, 12), because:

2 + 8 + 9 = 3 + 4 + 12 = 19
2 * 8 * 9 = 3 * 4 * 12 = 144

If a = 39 and b = 1200, then the solutions are (4, 15, 20), (5, 10, 24) and (6, 8, 25), because:

4 + 15 + 20 = 5 + 10 + 24 = 6 + 8 + 25 = 39
4 * 15 * 20 = 5 * 10 * 24 = 6 * 8 * 25 = 1200

Therefore, we want a function that:

number_of_sets(19, 144) = 2 #(2, 8, 9) and (3, 4, 12)
number_of_sets(39, 1200) = 3 #(4, 15, 20), (5, 10, 24) and (6, 8, 25)

*/

#include <assert.h>
#include <math.h>

typedef long long vlong;

vlong
min(vlong a, vlong b)
{
	return (a < b) ? a : b;
}

vlong
sets(vlong a, vlong b)
{
	vlong x, y, z;
	vlong m, n;
	vlong r;

	r = 0;
	for (x = 1; x <= a / 3; x++) {
		if (b % x)
			continue;

		m = b / x;
		n = min((a - x) / 2, sqrt(m));
		for (y = x; y <= n; y++) {
			if (m % y)
				continue;

			z = m / y;
			if (x + y + z == a && y <= z)
				r += 1;
		}
	}
	return r;
}

int
main()
{
	assert(sets(19, 144) == 2);
	assert(sets(39, 1200) == 3);
	return 0;
}
