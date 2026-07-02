/*

Find the sum of the squares of two integers.

Input
Two integers a and b are given. Each of them does not exceed 10^9 in absolute value.

Output
Print the value of the expression a2+b2.

Examples
Input #1
2 3

Answer #1
13

*/

#include <cassert>

typedef long long vlong;

vlong solve(vlong a, vlong b)
{
	return (a * a) + (b * b);
}

int main()
{
	assert(solve(2, 3) == 13);

	return 0;
}
