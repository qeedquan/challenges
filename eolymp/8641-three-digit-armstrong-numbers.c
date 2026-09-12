/*

Three digit number is called Armstrong number if the sum of cubes of its digits equals to the number.
For example, 153 = 1^3 + 5^3 + 3^3 is an Armstrong number.
Print all Armstrong numbers from a to b.

Input
Two integers a and b (100≤a≤b≤999).

Output
Print in one line all Armstrong numbers from a to b.

Examples
Input #1
100 400

Answer #1
153 370 371

*/

#include <stdio.h>

int
cube(int x)
{
	return x * x * x;
}

int
digsumcube(int n)
{
	int r;

	for (r = 0; n > 0; n /= 10)
		r += cube(n % 10);
	return r;
}

void
solve(int a, int b)
{
	int i;

	for (i = a; i <= b; i++) {
		if (digsumcube(i) == i)
			printf("%d ", i);
	}
	printf("\n");
}

int
main()
{
	solve(100, 400);

	return 0;
}
