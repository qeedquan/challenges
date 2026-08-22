/*

Given nonnegative integers a and b (a≤b) and positive integer x. How many numbers are there between a and b inclusively, divisible by x?

Input
Three numbers a,b and x (0≤a≤b≤10^18,1≤x≤10^18).

Output
Print the answer to the problem.

Examples

Input #1
5 10 3

Answer #1
2

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong a, vlong b, vlong x)
{
	vlong l, r;

	l = (a / x) * x;
	if (l != a)
		l += x;
	r = (b / x) * x;

	if (l > r)
		return 0;
	return ((r - l) / x) + 1;
}

int
main()
{
	assert(solve(5, 10, 3) == 2);

	return 0;
}
