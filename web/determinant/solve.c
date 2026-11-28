/*

The determinant of a 2x2 matrix of

|p q|
|r s|

is p*s - q*r

To maximize the determinant:

p*s is as largest as possible
q*r is as small as possible

Select (p, s) from the largest primes
Select (q, r) from the smallest primes

p = 19
s = 17
q = 2
r = 3

This leads to the determinant of
19*17 - 2*3 = 317

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
solve()
{
	static const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19 };

	size_t i, j, k, l, n;
	int p, q, s, r, m;

	n = nelem(primes);
	m = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				for (l = 0; l < n; l++) {
					if (i == j || i == k || i == l || j == k || j == l || k == l)
						continue;

					p = primes[i];
					q = primes[j];
					s = primes[k];
					r = primes[l];
					m = max(m, (p * s) - (q * r));
				}
			}
		}
	}
	return m;
}

int
main()
{
	printf("%d\n", solve());
	return 0;
}
