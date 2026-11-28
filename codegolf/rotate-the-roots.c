/*

Given a nonzero polynomial with integer coefficients and roots that are on the imaginary and on the real line such that if a is a root then so is -a, return another polynomial with the roots rotated by 90 degrees.

Details
The polynomial can be given in any reasonable format, e.g. as a list of coefficients. The symmetry condition that a is a root if and only if -a is a root too enforces the rotated polynomial to have real integer coefficients as well.

Examples
In the following the polynomials are given as a list of coefficient of the monomials in descending degree. (i.e. the constant comes last) The polynomial x^2-1 has roots {1,-1}. Rotating them by 90° means multiplying by i (the imaginary unit), so the output polynomial should have the roots {i,-i}, which is x^2 + 1.

Input / Output
[1 0 10 0 -127 0 -460 0 576]  [1 0 -10 0 -127 0 460 0 576]
[1 0 -4 0] [1 0 4 0]
[1] [1]

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@Leaky Nun

How it works
Multiplies the first element by 1, the third element by -1, etc.

Proof of algorithm
Let the polynomial be f(x).

Since we are guaranteed that if x is a root then so is -x, so f must be even, meaning that its coefficient for the odd powers must be 0.

Now, rotating the roots by 90° is essentially f(ix).

Expanding then comparing coefficients proves the algorithm.

*/

void
rotate(int *a, size_t n, int *r)
{
	size_t i;
	int s;

	s = 1;
	for (i = 0; i < n; i++) {
		r[i] = a[i];
		if (!(i & 1)) {
			r[i] *= s;
			s = -s;
		}
	}
}

void
test(int *a, size_t n, int *r)
{
	int p[128];

	rotate(a, n, p);
	assert(!memcmp(p, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 0, 10, 0, -127, 0, -460, 0, 576};
	int r1[] = {1, 0, -10, 0, -127, 0, 460, 0, 576};

	int a2[] = {1, 0, -4, 0};
	int r2[] = {1, 0, 4, 0};

	int a3[] = {1};
	int r3[] = {1};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);

	return 0;
}
