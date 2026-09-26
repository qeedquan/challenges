/*

Print all natural numbers from a to b without using loops or generators.

Input
You are given two natural numbers a and b (1≤a≤b≤1000), provided on a single line.

Output
Output all numbers from a to b, separated by a single space. Do not print an extra space at the end of the line.

Examples
Input #1
2 5

Answer #1
2 3 4 5

*/

#include <stdio.h>

void
recurse(int a, int b)
{
	if (a > b)
		return;

	printf("%d ", a);
	recurse(a + 1, b);
}

void
solve(int a, int b)
{
	recurse(a, b);
	printf("\n");
}

int
main()
{
	solve(2, 5);
	solve(1, 1000);

	return 0;
}
