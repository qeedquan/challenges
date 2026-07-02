#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A034968
vlong
solve(vlong n)
{
	vlong k, r;

	k = 2;
	r = 0;
	while (n > 0) {
		r += n % k;
		n /= k;
		k += 1;
	}
	return r;
}

int
main()
{
	static const vlong tab[] = {
		0, 1, 1, 2, 2, 3, 1, 2, 2, 3, 3, 4, 2, 3, 3, 4, 4, 5,
		3, 4, 4, 5, 5, 6, 1, 2, 2, 3, 3, 4, 2, 3, 3, 4, 4, 5,
		3, 4, 4, 5, 5, 6, 4, 5, 5, 6, 6, 7, 2, 3, 3, 4, 4, 5,
		3, 4, 4, 5, 5, 6, 4, 5, 5, 6, 6, 7, 5, 6, 6, 7, 7, 8,
		3, 4, 4, 5, 5, 6, 4, 5, 5, 6, 6, 7, 5, 6, 6, 7, 7, 8,
		6, 7, 7, 8, 8, 9, 4, 5, 5, 6, 6, 7, 5, 6, 6, 7
	};

	size_t i;

	assert(solve(10) == 3);
	assert(solve(25) == 2);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i) == tab[i]);

	return 0;
}
