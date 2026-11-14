/*

Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long long uvlong;

int
concat(uvlong a, uvlong b, uvlong *r)
{
	char s[sizeof(a) * CHAR_BIT];
	int n;

	if (a != 0)
		n = snprintf(s, sizeof(s), "%llu%llu", a, b);
	else
		n = snprintf(s, sizeof(s), "%llu", b);
	*r = strtoull(s, NULL, 10);
	return n;
}

int
pandigital(uvlong n)
{
	uvlong m, b;

	m = 0;
	do {
		b = 1 << (n % 10);
		if (m & b)
			return 0;
		m |= b;
		n /= 10;
	} while (n > 0);

	return m == 0x3fe;
}

uvlong
solve(void)
{
	uvlong i, j;
	uvlong r, x;
	int n;

	r = 0;
	for (i = 2; i < 10000; i++) {
		x = i;
		n = 0;
		for (j = 2; n < 9; j++)
			n = concat(x, i * j, &x);

		if (n == 9 && pandigital(x))
			r = max(r, x);
	}
	return r;
}

int
main(void)
{
	printf("%llu\n", solve());
	return 0;
}
