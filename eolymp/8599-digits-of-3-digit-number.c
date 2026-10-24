/*

A three-digit natural number is given. Output this number with spaces between its digits.

Input
One three-digit natural number n, 100≤n≤999.

Output
Output the number n with its digits separated by spaces.

Examples
Input #1
123

Answer #1
1 2 3

*/

#include <stdio.h>

void
solve(int n)
{
	int a, b, c;

	a = (n / 100) % 10;
	b = (n / 10) % 10;
	c = n % 10;
	printf("%d %d %d\n", a, b, c);
}

int
main()
{
	solve(123);

	return 0;
}
