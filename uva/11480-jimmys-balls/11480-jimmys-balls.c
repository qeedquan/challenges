#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A211540
vlong
solve(vlong n)
{
	vlong a, b, c, r;

	r = 0;
	for (a = n / 3; a >= 1; a--) {
		b = a + 1;
		c = b + 1;
		if (a + b + c <= n) {
			c -= 1;
			r += (n - a - b - c + 1) / 2;
		}
	}
	return r;
}

int
main()
{
	static const vlong tab[] = {
		0, 0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 7, 8, 10, 12, 14, 16, 19, 21, 24, 27,
		30, 33, 37, 40, 44, 48, 52, 56, 61, 65, 70, 75, 80, 85, 91, 96, 102,
		108, 114, 120, 127, 133, 140, 147, 154, 161, 169, 176, 184, 192, 200,
		208, 217, 225, 234, 243, 252, 261, 271, 280, 290
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	assert(solve(6) == 1);
	assert(solve(10) == 4);

	return 0;
}
