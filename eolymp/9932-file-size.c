/*

A video file has a size of m megabytes. What is the minimum number of gigabytes required on a computer's hard drive to store this file?
(Assume that one gigabyte is 1024 megabytes, and the amount of required gigabytes should be rounded up to the nearest integer if necessary.)

Input
The input consists of a single natural number m (1≤m≤10^12) — the size of the file in megabytes.

Output
Print a single integer — the minimum number of gigabytes needed to store the file.

Examples

Input #1
1234

Answer #1
2

*/

#include <assert.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	return ceil(n / 1024.0);
}

int
main()
{
	assert(solve(1234) == 2);

	return 0;
}
