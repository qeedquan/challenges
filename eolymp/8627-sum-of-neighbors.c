/*

Given a sequence of five integers. Replace these numbers, except the first and last, with the sum of their neighbors. Print the resulting numbers.

Input
Five integers.

Output
Print five numbers after the described replacement.

Examples
Input #1
1 2 3 4 5
Answer #1
1 4 6 8 5

*/

#include <stdio.h>

void
solve(int a, int b, int c, int d, int e)
{
	int r[5];
	int i;

	r[0] = a;
	r[4] = e;
	r[1] = a + c;
	r[2] = b + d;
	r[3] = c + e;

	for (i = 0; i < 5; i++)
		printf("%d ", r[i]);
	printf("\n");
}

int
main()
{
	solve(1, 2, 3, 4, 5);

	return 0;
}
