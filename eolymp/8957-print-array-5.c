/*

Array of n integers is given. Print all its even elements, reversing their original order.

Input
First line contains number n (1≤n≤100). Second line contains n integers, each no more than 100 by absolute value.

Output
In the first line print the number of even elements in array. In the second line print the even elements in the reverse order. If there are no even elements in the array, print "NO".

Examples
Input #1
7
-2 5 4 -3 7 -1 0

Answer #1
3
0 4 -2

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
solve(int *a, size_t n)
{
	size_t c, i;

	c = 0;
	for (i = n; i > 0; i--)
		c += !(a[i - 1] & 1);

	if (c == 0) {
		printf("NO\n");
		return;
	}

	printf("%zu\n", c);
	for (i = n; i > 0; i--) {
		if (!(a[i - 1] & 1)) {
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

	solve(a1, nelem(a1));

	return 0;
}
