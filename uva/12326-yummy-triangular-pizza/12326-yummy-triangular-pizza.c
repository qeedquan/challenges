#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A006534
uvlong
solve(uvlong n)
{
	static const uvlong tab[] = {
		1, 1, 1, 4, 6, 19, 43, 120, 307, 866, 2336, 6588,
		18373, 52119, 147700, 422016, 1207477, 3471067, 9999135,
		28893560, 83665729, 242826187, 706074369, 2056870697,
		6001555275, 17538335077, 51323792789, 150390053432,
		441210664337, 1295886453860, 3810208448847, 11214076720061,
		33035788241735

	};

	if (n == 0)
		return 0;

	n -= 1;
	if (n < nelem(tab))
		return tab[n];
	return 0;
}

int
main()
{
	assert(solve(2) == 1);
	assert(solve(4) == 4);
	assert(solve(10) == 866);

	return 0;
}
