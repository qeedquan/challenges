/*

The program takes a natural number n as input. Your task is to find the largest perfect cube that is less than n.

Input
A natural number n.

Output
The largest perfect cube less than n.

Examples
Input #1
11

Answer #1
8

*/

#include <assert.h>
#include <math.h>

typedef long long vlong;

vlong
solve(vlong n)
{
	vlong x;

	if (n < 1)
		return 0;

	x = cbrt(n - 1);
	return x * x * x;
}

int
main()
{
	assert(solve(11) == 8);

	return 0;
}
