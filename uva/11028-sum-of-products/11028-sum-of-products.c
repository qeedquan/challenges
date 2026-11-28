#include <assert.h>
#include <stdio.h>

typedef unsigned uint;

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define cube(x) ((x) * (x) * (x))

// https://oeis.org/A007773
uint
solve(uint n)
{
	static const uint tab[] = { 1, 1, 1, 3, 8, 21, 43 };

	uint s;

	if (n == 0)
		return 0;

	if (n <= nelem(tab))
		return tab[n - 1];

	s = (n & 1) ? 27 : 30;
	return (cube(n) - (16 * n) + s) / 6;
}

int
main()
{
	static const uint tab[] = {
		1, 1, 1, 3, 8, 21, 43, 69, 102, 145, 197, 261, 336, 425, 527, 645, 778,
		929, 1097, 1285, 1492, 1721, 1971, 2245, 2542, 2865, 3213, 3589, 3992,
		4425, 4887, 5381, 5906, 6465, 7057, 7685, 8348, 9049, 9787, 10565,
		11382, 12241, 13141, 14085, 15072, 16105
	};

	uint i;

	assert(solve(3) == 1);
	assert(solve(4) == 3);
	assert(solve(6) == 21);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
