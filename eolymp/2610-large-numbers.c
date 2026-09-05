/*

At the i-th position in the sequence is the largest integer with i digits, where every pair of adjacent digits is different.

Input
A natural number k (1≤k≤100000).

Output
Output the k-th number in the sequence.

Examples

Input #1
2

Answer #1
98

*/

#include <stdio.h>

typedef long long vlong;

void
solve(vlong n)
{
	vlong i;

	for (i = 0; i < n; i++)
		putchar('9' - (i & 1));
	putchar('\n');
}

int
main()
{
	solve(2);

	return 0;
}
