#include <assert.h>
#include <stdio.h>
#include <math.h>

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
	vlong i;

	assert(H(5) == 10);
	assert(H(10) == 27);

	for (i = 0; i <= 10000; i++)
		assert(H(i) == HBF(i));

	return 0;
}
