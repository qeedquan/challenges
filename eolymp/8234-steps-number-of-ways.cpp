/*

In how many ways can you reach the n-th step if you can take a step to the next, skip one, or skip two steps?

Input
A single integer n - representing the step number (n≤60).

Output
Print the number of ways to reach the n-th step.

Examples
Input #1
5

Answer #1
13

*/

#include <cassert>
#include <cstdio>

typedef unsigned long long uvlong;

// https://oeis.org/A000073
uvlong tribonacci(uvlong n)
{
	uvlong a, b, c, d;
	uvlong i;

	a = 0;
	b = 0;
	c = 1;
	for (i = 0; i < n; i++)
	{
		d = a + b + c;
		a = b;
		b = c;
		c = d;
	}
	return a;
}

uvlong solve(uvlong n)
{
	return tribonacci(n + 2);
}

int main()
{
	assert(solve(5) == 13);

	return 0;
}
