/*

Print all odd integers from the interval [a,b] in ascending order.

Input
Two integers a and b (a<b).

Output
Print all odd integers from the interval [a,b] in ascending order on a single line.

Examples
Input #1
2 7

Answer #1
3 5 7

*/

#include <stdio.h>

void
solve(int a, int b)
{
	int i;

	for (i = a + !(a & 1); i <= b; i += 2)
		printf("%d ", i);
	printf("\n");
}

int
main()
{
	solve(2, 7);
	return 0;
}
