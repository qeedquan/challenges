/*

Calculate the sum of the first n terms in the sequence: 2+5+10+17+26+…

Input
A natural number n, where 1≤n≤100.

Output
A single number representing the sum of the first n terms of the sequence.

Examples
Input #1
7

Answer #1
147

*/

#include <assert.h>
#include <stdio.h>

int
solve(int n)
{
	return n * ((2 * n * n) + (3 * n) + 7) / 6;
}

int
main()
{
	assert(solve(7) == 147);

	return 0;
}
