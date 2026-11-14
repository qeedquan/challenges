/*

Given two natural numbers, n and m, determine how many odd natural numbers with n digits are greater than m.

Input
Two natural numbers, n and m, provided on a single line separated by a space (1≤n≤12, 1≤m≤10^12).

Output
Output the number of odd n-digit numbers that are greater than m.

Examples

Input #1
2 72

Answer #1
14

*/

#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long vlong;

vlong count(vlong a, vlong b)
{
	if (a > b)
		return 0;

	vlong k = b - a + 1;
	vlong r = k / 2;
	if (k & 1)
	{
		if ((a & 1) && (b & 1))
			r += 1;
	}
	return r;
}

vlong solve(vlong n, vlong m)
{
	vlong a = pow(10, n - 1);
	vlong b = pow(10, n) - 1;
	return count(max(a, m + 1), b);
}

int main()
{
	assert(solve(2, 72) == 14);

	return 0;
}
