/*

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

int
abundant(uvlong n)
{
	uvlong i, r;

	r = 0;
	for (i = 1; i < n && r <= n; i++) {
		if ((n % i) == 0)
			r += i;
	}
	return r > n;
}

size_t
gen(uvlong n, uvlong *a, int (*f)(uvlong))
{
	uvlong i;
	size_t j;

	for (i = j = 0; i < n; i++) {
		if (f(i))
			a[j++] = i;
	}
	return j;
}

void
mark(uvlong *a, size_t n, char *s, size_t m)
{
	size_t i, j;
	uvlong v;

	memset(s, 0, m);
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			v = a[i] + a[j];
			if (v < m)
				s[v] = 1;
		}
	}
}

uvlong
sum(char *s, size_t n)
{
	uvlong r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++) {
		if (!s[i])
			r += i;
	}
	return r;
}

uvlong
solve(void)
{
	static const uvlong limit = 28123ULL;

	uvlong a[8192];
	char s[32768];
	size_t n;

	n = gen(limit, a, abundant);
	mark(a, n, s, nelem(s));
	return sum(s, nelem(s));
}

int
main(void)
{
	printf("%llu\n", solve());
	return 0;
}
