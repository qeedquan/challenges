/*

Petya has n square cards. He wants to assemble a large square (without holes) using these cards. How many cards will he have left over?

Input
One positive integer n (1≤n≤10^9).

Output
Print the number of cards that Petya will have left over.

Examples

Input #1
1

Answer #1
0

Input #2
27

Answer #2
2

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

long
solve(long n)
{
	long s;

	if (n < 0)
		return 0;

	s = sqrt(n);
	return n - (s * s);
}

int
main()
{
	assert(solve(1) == 0);
	assert(solve(27) == 2);

	return 0;
}
