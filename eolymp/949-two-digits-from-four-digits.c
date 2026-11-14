/*

You are given a four-digit positive integer n. Form a two-digit number consisting of the middle digits of n.

Input
One four-digit positive integer n.

Output
Print the resulting two-digit number. Do not print leading zeros.

Examples

Input #1
4765

Answer #1
76

Input #2
1010

Answer #2
1

*/

#include <assert.h>
#include <stdio.h>

int
solve(int n)
{
	int a, b;

	a = (n / 10) % 10;
	b = ((n / 100) % 10) * 10;
	return a + b;
}

int
main()
{
	assert(solve(4765) == 76);
	assert(solve(1010) == 1);

	return 0;
}
