#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
solve(vlong w, vlong p[][2], size_t n)
{
	size_t i;
	vlong s;

	if (w == 0)
		return 0;

	s = 0;
	for (i = 0; i < n; i++)
		s += p[i][0] * p[i][1];
	return s / w;
}

int
main()
{
	vlong p1[][2] = {
		{ 2, 3 },
		{ 1, 4 },
		{ 1, 2 },
		{ 1, 2 },
		{ 2, 2 },
		{ 2, 2 },
		{ 2, 1 },
	};

	assert(solve(4, p1, nelem(p1)) == 6);

	return 0;
}
