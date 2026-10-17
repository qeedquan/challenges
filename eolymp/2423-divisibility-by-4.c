/*

Let us consider an infinite sequence of numbers constructed as follows:

A0 = 1
A1 = 12
A9 = 12345678910
A10 = 1234567891011
...


That is, each next term in the sequence is obtained by appending to the previous term the decimal representation
of the number that is one greater than the index of the current term.

You need to determine the total number of elements in the sequence within the index range [m,n] (0≤m≤n≤10^18) that are divisible by 4 without a remainder.

Input
The only line of input contains two non-negative integers m and n.

Output
Print a single integer — the answer to the problem.

Examples

Input #1
0 0

Answer #1
0

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uvlong;

// https://oeis.org/A002265 (related)
uvlong
solve(uvlong m, uvlong n)
{
	uvlong i, j;

	j = 0;
	for (i = m + 1; i <= n + 1; i++) {
		if ((!(i % 4) && i != 4 && i != 8) || i == 2 || i == 6)
			j++;

		if (j == 1)
			break;
	}

	if (j == 0)
		return 0;
	return (n + 1 - i) / 4 + 1;
}

int
main()
{
	assert(solve(0, 0) == 0);

	return 0;
}
