/*

Print all even integers from the interval [a,b] in decreasing order.

Input
Two integers a and b (a<b).

Output
Print in one line all even integers from the interval [a,b] in decreasing order.

Examples

Input #1
2 7

Answer #1
6 4 2

*/

#include <stdio.h>

void
solve(int a, int b)
{
	int i;

	for (i = b - (b & 1); i >= a; i -= 2)
		printf("%d ", i);
	printf("\n");
}

int
main()
{
	solve(2, 7);
	return 0;
}
