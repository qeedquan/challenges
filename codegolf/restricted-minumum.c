/*

You need to find the sum of minimum values of two list (same size) of small numbers. In a C like language, that could be expressed as:

v = min(a[0],b[0]) + min(a[1],b[1])+ min(a[2],b[2]) ...

The range of values is 0..7 and the 2 list can have up to 7 values. If you like, all the values in each list can be stored as a single 32 bit number.

My goal is avoiding branches in code, so the rules are

Single line expression,
No function calls or method calls (except for basic operations like sum, if your language mandate this),
No if statements, including things that compile to if statements such as ternary operators or "greater than" operators
Edit 1 To clarify, what I want is 'no branches in code'. So, no if, no calls (function of methods). Loops with fixed ranges (0..7) could be OK because can be unrolled. Sorry if was not crystal clear about this.

All what your language can do inline is OK. So if a functional language has a strange syntax that resembles a function call but is inlined, that's OK.

Shortest code wins.

As a side note: this challenge is related to a quasi-real problem: a fast scoring function in mastermind game.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
minsum(int *a, int *b, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += min(a[i], b[i]);
	return r;
}

int
main(void)
{
	int a1[] = {1, 7, 3, 4, 5, 0, 3};
	int b1[] = {3, 1, 4, 1, 5, 2, 6};

	int a2[] = {1, 2, 3, 4, 5, 6, 7};
	int b2[] = {9, 0, 5, 7, 1, 2, 7};

	assert(minsum(a1, b1, nelem(a2)) == 14);
	assert(minsum(a2, b2, nelem(a2)) == 18);

	return 0;
}
