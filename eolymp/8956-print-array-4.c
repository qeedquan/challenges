/*

Given an array of n integers. Print only its negative elements, reversing their order.

Input
The first line contains the integer n (1≤n≤100). The second line contains n integers, each with an absolute value not exceeding 100.

Output
On the first line, print the number of negative elements in the array. On the second line, print the negative elements in reverse order. If there are no negative elements in the array, print "NO".

Examples

Input #1
7
-2 5 4 -3 7 -1 0

Answer #1
3
-1 -3 -2

Input #2
5
2 1 0 1 5

Answer #2
NO

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(int *a, size_t n)
{
	size_t c, i;

	c = 0;
	for (i = n; i > 0; i--)
		c += (a[i - 1] < 0);

	if (c == 0) {
		printf("NO\n");
		return;
	}

	printf("%zu\n", c);
	for (i = n; i > 0; i--) {
		if (a[i - 1] < 0) {
			printf("%d", a[i - 1]);
			c -= 1;
			if (c)
				printf(" ");
		}
	}
	printf("\n");
}

int
main()
{
	int a1[] = { -2, 5, 4, -3, 7, -1, 0 };
	int a2[] = { 2, 1, 0, 1, 5 };

	solve(a1, nelem(a1));
	solve(a2, nelem(a2));

	return 0;
}
