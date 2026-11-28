/*

Find all three digit numbers with sum of digits equal to n.

Input
One integer n (0≤n≤28).

Output
Print in the first line the number of found three digit numbers. In the next lines print these numbers in increasing order.

Examples
Input #1
3

Answer #1
6
102
111
120
201
210
300

*/

#include <stdio.h>

int
digsum(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

void
solve(int n)
{
	int c, i;

	c = 0;
	for (i = 100; i <= 999; i++)
		c += (digsum(i) == n);
	printf("%d\n", c);

	for (i = 100; i <= 999; i++) {
		if (digsum(i) == n)
			printf("%d\n", i);
	}

	printf("\n");
}

int
main()
{
	solve(3);
	solve(18);
	solve(28);

	return 0;
}
