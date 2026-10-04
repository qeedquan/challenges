#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

vlong
HBF(vlong n)
{
	vlong i, r;

	r = 0;
	for (i = 1; i <= n; i++)
		r += n / i;
	return r;
}

// https://oeis.org/A006218
vlong
H(vlong n)
{
	vlong i, s, r;

	if (n < 0)
		return 0;

	s = floor(sqrt(n));
	r = 0;
	for (i = 1; i <= s; i++)
		r += n / i;
	return (2 * r) - (s * s);
}

int
main()
{
	static const vlong tab[] = {
		0, 1, 3, 5, 8, 10, 14, 16, 20, 23, 27, 29, 35, 37, 41, 45, 50, 52, 58,
		60, 66, 70, 74, 76, 84, 87, 91, 95, 101, 103, 111, 113, 119, 123, 127,
		131, 140, 142, 146, 150, 158, 160, 168, 170, 176, 182, 186, 188, 198,
		201, 207, 211, 217, 219, 227, 231, 239, 243, 247, 249
	};

	size_t i;

	assert(H(5) == 10);
	assert(H(10) == 27);

	for (i = 0; i < nelem(tab); i++)
		assert(H(i) == tab[i]);

	for (i = 0; i <= 10000; i++)
		assert(H(i) == HBF(i));

	return 0;
}
