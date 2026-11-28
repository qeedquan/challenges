/*

Two integers a and b are given.

Print the squares and cubes of all integers from a to b inclusive.

Input
Two integers a and b (0≤a≤b≤10000).

Output
Print the squares of all integers from a to b inclusive in ascending order on the first line.

On the second line, print the cubes of all integers from a to b inclusive in descending order.

Examples

Input #1
5 10

Answer #1
25 36 49 64 81 100
1000 729 512 343 216 125

Input #2
120 123

Answer #2
14400 14641 14884 15129
1860867 1815848 1771561 1728000

*/

#include <stdio.h>

typedef long long vlong;

void
solve(vlong a, vlong b)
{
	vlong i;

	for (i = a; i <= b; i++)
		printf("%lld ", i * i);
	printf("\n");

	for (i = b; i >= a; i--)
		printf("%lld ", i * i * i);
	printf("\n");

	printf("\n");
}

int
main()
{
	solve(5, 10);
	solve(120, 123);

	return 0;
}
