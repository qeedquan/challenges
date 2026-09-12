/*

Find all odd divisors of the natural number n.

Input
A single natural number n such that n≤10^5.

Output
Print all odd divisors of n. Print each divisor on a separate line.

Examples
Input #1
12

Answer #1
1
3

*/

#include <stdio.h>
#include <math.h>

void
solve(int n)
{
	int i;

	if (n < 0)
		return;

	printf("n=%d\n", n);
	for (i = 1; i <= n; i += 2) {
		if (!(n % i))
			printf("%d\n", i);
	}
	printf("\n");
}

int
main()
{
	solve(12);

	return 0;
}
