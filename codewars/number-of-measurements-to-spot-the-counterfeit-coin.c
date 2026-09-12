/*

I found this interesting interview question just today:

8 coins are given where all the coins have equal weight, except one. The odd one weights less than the others, not being of pure gold. In the worst case, how many iterations are actually needed to find the odd one out on a two plates scale.

I am asking you then to tell me what is the minimum amount of weighings it will take to measure n coins in every possible occurrence (including worst case scenario, ie: without relying on luck at all).

n is guaranteed to be a positive integer.

Tip: being able to think recursively might help here :p

Note: albeit this is more clearly a logical than a coding problem, do not underestimate (or under-rank) the kata for requiring not necessarily wizard-class coding skills: a good coder is a master of pattern recognition and subsequent optimization ;)

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A080342
int
solve(int n)
{
	if (n < 1)
		return 0;
	return ceil(log(n) / log(3));
}

int
main()
{
	static const int tab[] = {
		0, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	assert(solve(1) == 0);
	assert(solve(2) == 1);
	assert(solve(3) == 1);
	assert(solve(8) == 2);
	assert(solve(100) == 5);

	return 0;
}
