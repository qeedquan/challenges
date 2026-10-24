/*

Given a sequence of nonnegative integers ending with number 0.
After reading zero, the program must terminate its work and output the count of numbers read, not including the final zero.
It is not necessary to read the numbers following 0.

Input
Sequence of non-negative integers, each written in a separate line.

Output
Print the amount of numbers in the sequence before the first zero.

Examples

Input #1
1
7
9
0
5

Answer #1
3

*/

#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
solve(FILE *fp)
{
	uvlong n;
	int x;

	n = 0;
	while (fscanf(fp, "%d", &x) == 1) {
		if (x == 0)
			break;
		n += 1;
	}
	return n;
}

int
main()
{
	printf("%llu\n", solve(stdin));

	return 0;
}
