/*

Write a program that reads a two-digit integer and outputs both digits separated by a space.

Input
A single integer n where 10≤n≤99.

Output
Output the two digits of the number, separated by a space.

Examples

Input #1
24

Answer #1
2 4

*/

#include <stdio.h>

void
solve(int n)
{
	printf("%d %d\n", (n / 10) % 10, n % 10);
}

int
main()
{
	solve(24);
	return 0;
}
