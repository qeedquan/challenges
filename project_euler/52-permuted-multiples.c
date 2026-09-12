/*

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

void
hist(uvlong n, uvlong h[10])
{
	memset(h, 0, sizeof(*h) * 10);
	do {
		h[n % 10]++;
		n /= 10;
	} while (n);
}

uvlong
solve(void)
{
	uvlong a[10], b[10];
	uvlong i, x;

	for (i = 1; i < ULLONG_MAX; i++) {
		hist(i, a);
		for (x = 2; x <= 6; x++) {
			hist(i * x, b);
			if (memcmp(a, b, sizeof(b)))
				break;
		}
		if (x > 6)
			return i;
	}
	return 0;
}

int
main(void)
{
	printf("%llu\n", solve());
	return 0;
}
