/*

The prime HP reached starting from a number , concatenating its prime factors, and repeating until a prime is reached. If you have doubts, refer the article here

write a function to calculate the HP of a given number.

Also write a function to compute the Euclid-Mullin sequence.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long vlong;

bool
isprime(vlong n)
{
	vlong l, x;

	if (n < 2)
		return false;

	l = sqrt(n);
	for (x = 2; x <= l; x++) {
		if (!(n % x))
			return false;
	}
	return true;
}

vlong
firstfactor(vlong n)
{
	vlong x;

	if (n < 2)
		return -1;

	for (x = 2; x < n; x++) {
		if (!(n % x) && isprime(x))
			break;
	}
	return x;
}

// https://oeis.org/A037274
vlong
homeprime(vlong n)
{
	vlong a, b, r;

	r = n;
	while (!isprime(r)) {
		a = firstfactor(r);
		b = r / a;
		while (b > 0) {
			a = (a * 10) + (b % 10);
			b = b / 10;
		}
		r = a;
	}
	return r;
}

// https://oeis.org/A000945
void
euclidmullin(vlong n)
{
	vlong *r, x, y;

	printf("EM(%lld):\n", n);
	if (n < 1)
		return;

	r = calloc(n, sizeof(*r));
	if (!r)
		return;

	r[0] = 2;

	printf("%lld\n", r[0]);
	for (x = 1; x < n; x++) {
		r[x] = 1;
		for (y = 0; y < x; y++)
			r[x] = r[x] * r[y];
		r[x] += 1;
		r[x] = firstfactor(r[x]);
		printf("%lld\n", r[x]);
	}

	free(r);
}

int
main()
{
	printf("HP(9): %lld\n", homeprime(9));
	euclidmullin(8);
	return 0;
}
