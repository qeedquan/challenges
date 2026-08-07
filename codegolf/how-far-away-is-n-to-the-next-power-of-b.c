/*

Let n and b be positive integers larger than 1.

Output the distance from n to the next power of b.

For n=5 and b=3, the next power of 3 from 5 is 9 (3^2 = 9), so the output is 9 - 5 = 4.

For n=8 and b=2, the next power of 2 from 8 is 16 (2^4 = 16), so the output is 16 - 8 = 8. Note that n is a power of 2 in this example.

Testcases:

  n b output
212 2 44
563 5 62
491 5 134
424 3 305
469 8 43
343 7 2058
592 7 1809
289 5 336
694 3 35
324 5 301
  2 5 3

This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
nextpowb(uvlong n, uvlong b)
{
	uvlong p;

	p = 1;
	while (p <= n)
		p *= b;
	return p;
}

uvlong
farness(uvlong n, uvlong b)
{
	return nextpowb(n, b) - n;
}

int
main(void)
{
	assert(farness(212, 2) == 44);
	assert(farness(563, 5) == 62);
	assert(farness(491, 5) == 134);
	assert(farness(424, 3) == 305);
	assert(farness(469, 8) == 43);
	assert(farness(343, 7) == 2058);
	assert(farness(592, 7) == 1809);
	assert(farness(289, 5) == 336);
	assert(farness(694, 3) == 35);
	assert(farness(324, 5) == 301);
	assert(farness(2, 5) == 3);

	return 0;
}
