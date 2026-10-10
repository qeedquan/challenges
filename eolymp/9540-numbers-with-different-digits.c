/*

The program takes a natural number n as input.
It should output the count of n-digit natural numbers where all the digits are distinct.

Input
A natural number n (n≤10).

Output
The number of n-digit natural numbers with unique digits.

Examples
Input #1
1

Answer #1
9

*/

#include <assert.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long ulong;

// https://oeis.org/A073531
ulong
solve(ulong n)
{
	static const ulong tab[] = {
		0,
		9,
		81,
		648,
		4536,
		27216,
		136080,
		544320,
		1632960,
		3265920,
		3265920,
	};

	if (n < nelem(tab))
		return tab[n];
	return 0;
}

int
main()
{
	assert(solve(1) == 9);

	return 0;
}
