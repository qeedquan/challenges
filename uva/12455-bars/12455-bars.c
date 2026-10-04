#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define bit(x) (1ULL << (x))

bool
solve(int *a, size_t n, int t)
{
	size_t i, j;
	int s;

	for (i = 0; i < bit(n); i++) {
		s = 0;
		for (j = 0; j < n; j++) {
			if (i & bit(j))
				s += a[j];
		}
		if (s == t)
			return true;
	}
	return false;
}

int
main()
{
	int a1[] = { 10, 12, 5, 7 };
	int a2[] = { 45, 15, 120, 500, 235, 58, 6, 12, 175, 70 };
	int a3[] = { 25, 25, 25, 25, 25 };
	int a4[] = { 13, 567 };

	assert(solve(a1, nelem(a1), 25) == false);
	assert(solve(a2, nelem(a2), 925) == true);
	assert(solve(a3, nelem(a3), 120) == false);
	assert(solve(a4, nelem(a4), 0) == true);

	return 0;
}
