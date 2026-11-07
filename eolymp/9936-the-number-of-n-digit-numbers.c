/*

Given two natural numbers n and m, determine how many natural numbers with exactly n digits are less than m.

Input
Two natural numbers n and m provided on a single line, separated by a space (1≤n≤12, 1≤m≤10^12).

Output
Output the number of n-digit natural numbers that are less than m.

Examples
Input #1
2 37
Answer #1
27

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef long long vlong;

vlong
solve(vlong n, vlong m)
{
	if (n < 0 || m < 0)
		return 0;
	return fmax(m - pow(10, n - 1), 0);
}

int
main()
{
	assert(solve(2, 37) == 27);
	return 0;
}
