/*

Positive integer n is given. Print the rectangle of size n×3 from symbols '#' as shown in the sample.

Input
One positive integer n (n≤100).

Output
Print the rectangle of size n×3 from symbols '#'.

Examples
Input #1
2

Answer #1
###
###

*/

#include <stdio.h>

void
solve(int n)
{
	int i;

	for (i = 0; i < n; i++)
		puts("###");
}

int
main()
{
	solve(2);

	return 0;
}
