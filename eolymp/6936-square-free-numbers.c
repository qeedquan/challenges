/*

The integer is called square-free if it is not divisible by a perfect square, except 1. You have to count them!

Input
First line contains the number of test cases t. Each of the following t lines contains one positive integer n (n≤10^14).

Output
Print t lines, each line contains the number of positive square-free integers not larger than n.

Examples
Input #1
3
1
1000
100000000000000

Answer #1
1
608
60792710185947

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

// https://oeis.org/A008683
vlong *
mugen(vlong n)
{
	vlong i, j, s, *mu;

	if (n < 1)
		return NULL;

	mu = xcalloc(n + 1, sizeof(*mu));
	for (i = 0; i < n; i++)
		mu[i] = 1;

	s = sqrt(n);
	for (i = 2; i <= s; i++) {
		if (mu[i] == 1) {
			for (j = i; j <= n; j += i)
				mu[j] *= -i;
			for (j = i * i; j <= n; j += i * i)
				mu[j] = 0;
		}
	}

	for (i = 2; i <= n; i++) {
		if (mu[i] == i)
			mu[i] = 1;
		else if (mu[i] == -i)
			mu[i] = -1;
		else if (mu[i] < 0)
			mu[i] = 1;
		else if (mu[i] > 0)
			mu[i] = -1;
	}

	return mu;
}

// https://oeis.org/A013928
vlong
solve(vlong *mu, vlong n)
{
	vlong i, s, r;

	if (n < 0)
		return 0;

	r = 0;
	s = sqrt(n);
	for (i = 1; i <= s; i++)
		r += mu[i] * (n / (i * i));
	return r;
}

int
main()
{
	static const vlong A008683[] = {
		1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1,
		1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1,
		-1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0,
		1, -1, -1, 0, 1, -1, -1, 0, -1, 1, 0, 0, 1, -1
	};

	static const vlong A013928[] = {
		0, 1, 2, 3, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 10, 11, 11, 12, 12, 13, 13,
		14, 15, 16, 16, 16, 17, 17, 17, 18, 19, 20, 20, 21, 22, 23, 23, 24,
		25, 26, 26, 27, 28, 29, 29, 29, 30, 31, 31, 31, 31, 32, 32, 33, 33,
		34, 34, 35, 36, 37, 37, 38, 39, 39, 39, 40, 41, 42, 42, 43, 44, 45,
		45, 46, 47, 47, 47, 48, 49, 50, 50, 50, 51
	};

	vlong *mu;
	size_t i;

	mu = mugen(10000000);

	assert(solve(mu, 1) == 1);
	assert(solve(mu, 1000) == 608);
	assert(solve(mu, 100000000000000) == 60792710185947);

	for (i = 0; i < nelem(A008683); i++)
		assert(mu[i + 1] == A008683[i]);

	for (i = 0; i < nelem(A013928); i++)
		assert(solve(mu, i) == A013928[i]);

	free(mu);

	return 0;
}
