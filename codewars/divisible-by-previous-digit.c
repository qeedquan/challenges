/*

Take a number and check each digit if it is divisible by the digit on its left checked and return an array of booleans.

The booleans should always start with false becase there is no digit before the first one.

Examples
73312        => [false, false, true, false, true]
2026         => [false, true, false, true]
635          => [false, false, false]

*** Remember 0 is evenly divisible by all integers but not the other way around ***

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

void
rev(bool *a, size_t n)
{
	size_t i;
	bool t;

	for (i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}

size_t
divlast(uvlong n, bool *r)
{
	uvlong x, y;
	size_t i;

	for (i = 0; n > 0; n /= 10) {
		x = n % 10;
		y = (n / 10) % 10;
		r[i++] = (y && !(x % y));
	}
	rev(r, i);
	return i;
}

void
test(uvlong n, bool *r, size_t nr)
{
	bool p[32];
	size_t np;

	np = divlast(n, p);
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main()
{
	bool r1[] = { false, false, true, false, true };
	bool r2[] = { false, true, false, true };
	bool r3[] = { false, false, false };

	test(73312, r1, nelem(r1));
	test(2026, r2, nelem(r2));
	test(635, r3, nelem(r3));

	return 0;
}
