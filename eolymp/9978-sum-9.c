/*

Calculate the sum of the first n terms of the sequence shown in the image below.

1/1 + 2/3 + 3/5 + 4/7 + 5/9 + ...


Input
A natural number n is given, where 1≤n≤100.

Output
Output a single number — the sum of the first n terms of the sequence, rounded to three decimal places.

Examples

Input #1
3

Answer #1
2.267

*/

#include <stdio.h>

double
solve(int n)
{
	double j, r;
	int i;

	r = 0;
	j = 1;
	for (i = 1; i <= n; i++) {
		r += i / j;
		j += 2;
	}
	return r;
}

int
main()
{
	printf("%.3f\n", solve(3));

	return 0;
}
