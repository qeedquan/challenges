/*

Given a three-digit natural number n, your task is to create a new number by replacing each digit of n with its complement to 9.
For instance, if n=105, the resulting number will be 894.

Input
The input consists of a single line containing the number n, where 100≤n≤999.

Output
Print the newly formed number on a single line.

Examples

Input #0
105

Answer #0
894

*/

#include <assert.h>

typedef unsigned int uint;

uint
solve(uint n)
{
	uint p, r;

	r = 0;
	p = 1;
	do {
		r += p * (9 - (n % 10));
		p *= 10;
		n /= 10;
	} while (n);

	return r;
}

int
main()
{
	assert(solve(105) == 894);

	return 0;
}
