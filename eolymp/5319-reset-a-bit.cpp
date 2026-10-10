/*

Given two integers a and k. Find the number that is obtained from a by resetting the value of the k-th bit to 0.
The least significant bit has number 0.

Input
Two numbers a and k (0≤a≤10^9).

Output
Print the number with the k-th bit reset.

Examples

Input #1
5 1

Answer #1
5

*/

#include <cassert>

typedef unsigned long long uvlong;

uvlong solve(uvlong a, uvlong k)
{
	return a & ~(1ULL << k);
}

int main()
{
	assert(solve(5, 1) == 5);
	return 0;
}
