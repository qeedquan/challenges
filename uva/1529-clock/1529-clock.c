#include <assert.h>

int
solve(int h1, int m1, int h2, int m2)
{
	double A[60];
	int v1, v2;
	int i, r;

	A[0] = 0;
	for (i = 1; i < 60; i++)
		A[i] = A[i - 1] + (720.0 / 11.0);

	v1 = (h1 * 60) + m1;
	v2 = (h2 * 60) + m2;
	if (v1 > v2)
		v2 += 720;

	r = 0;
	for (i = 0; i < 60; i++) {
		if (A[i] >= v1 && A[i] <= v2)
			r++;
	}
	return r;
}

int
main()
{
	assert(solve(12, 50, 1, 2) == 0);
	assert(solve(3, 8, 3, 20) == 1);
	assert(solve(2, 45, 11, 0) == 8);
	assert(solve(11, 0, 3, 20) == 4);
	assert(solve(1, 2, 12, 50) == 11);
	assert(solve(3, 20, 3, 8) == 10);

	return 0;
}
