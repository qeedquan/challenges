/*

Count the number of N-digit positive integers for which the sum of digits in the binary and decimal representations is the same. (N=1..10).

Input
A positive integer N (N=1..10) is given in the input file.

Output
Output a single integer—the answer to the problem.

Examples

Input #1
1

Answer #1
1

*/

#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long ulong;

ulong
solve(ulong n)
{
	static const ulong tab[] = {
		0,
		1,
		2,
		14,
		60,
		406,
		2256,
		13084,
		70978,
		423000,
		2556298,
	};

	if (n >= nelem(tab))
		return 0;
	return tab[n];
}

int
main()
{
	assert(solve(1) == 1);

	return 0;
}
