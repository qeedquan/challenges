#include <stdio.h>

typedef unsigned long long uvlong;

int
solvable(uvlong n, uvlong *x, uvlong *y)
{
	uvlong a, b;

	*x = *y = 0;
	for (a = 0; a < n; a++) {
		for (b = a; b < n; b++) {
			if (((b * b * b) - (a * a * a)) == n) {
				*x = b;
				*y = a;
				return 1;
			}
		}
	}
	return 0;
}

void
test(uvlong n)
{
	uvlong x, y;
	int r;

	r = solvable(n, &x, &y);
	printf("%d %llu %llu\n", r, x, y);
}

int
main(void)
{
	test(7);
	test(37);
	test(12);

	return 0;
}
