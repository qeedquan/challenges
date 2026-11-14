/*

The input for the program is a natural number n where n is greater than 9.
Your task is to swap the digits in the tens and units places of the number n.

Input
A natural number n such that n is greater than 9.

Output
The result after swapping the tens and units digits of n.

Examples

Input #1
512

Answer #1
521

*/

#include <assert.h>

typedef unsigned int uint;

uint
solve(uint n)
{
	uint m;

	m = (n % 10) * 10;
	m += (n / 10) % 10;
	n /= 100;
	n *= 100;
	return n + m;
}

int
main()
{
	assert(solve(512) == 521);
	assert(solve(23) == 32);

	return 0;
}
