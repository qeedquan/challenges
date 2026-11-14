/*

You are given two positive integers n and a. Calculate the value of the sum:

Sum[i=1, n] i*a^i

Input
Two positive integers n and a.

Output
Print the value of the sum. It is known that it does not exceed 10^18.

Examples

Input #1
3 3

Answer #1
102

Input #2
4 4

Answer #2
1252

*/

#include <cassert>

typedef long long vlong;

vlong solve(vlong n, vlong a)
{
	vlong r = 0;
	vlong p = a;
	for (vlong i = 1; i <= n; i++)
	{
		r += i * a;
		a *= p;
	}
	return r;
}

int main()
{
	assert(solve(3, 3) == 102);
	assert(solve(4, 4) == 1252);

	return 0;
}
