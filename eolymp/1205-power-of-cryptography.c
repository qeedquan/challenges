/*

Given two integers n≥1 and p≥1, determine the positive n-th root of p.
That is, find an integer k such that k^n=p.

Input
Two integers n and p are given (1≤n≤300, 1≤p≤10^100).
It is guaranteed that there always exists an integer k (1≤k≤10^9) such that k^n=p.

Output
Print the value k such that k^n=p.

Examples

Input #1
2 16

Answer #1
4

Input #2
3 27

Answer #2
3

Input #3
7 4357186184021382204544

Answer #3
1234

*/

#include <stdio.h>
#include <math.h>

long double
solve(long double n, long double p)
{
	return expl(logl(p) / n);
}

int
main()
{
	printf("%.0Lf\n", solve(2, 16));
	printf("%.0Lf\n", solve(3, 27));
	printf("%.0Lf\n", solve(7, 4357186184021382204544.0));
	return 0;
}
