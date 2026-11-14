/*

Given positive integer n. Find and print the square of difference between the maximum and minimum numbers, composed from the digits of number n.

For example, if given number is 30605, the maximum number, composed from its digits, is 65300,
and minimum number is 356 (the minimum is 00356, but leading zeros are not counted).
The required square of difference is (65300−356)∗(65300−356)=4217723136.

Input
One positive integer n (1≤n≤10^9).

Output
Print the required square of difference.

Examples

Input #1
30605

Answer #1
4217723136

*/

#include <cassert>
#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long uvlong;

uvlong solve(uvlong x)
{
	auto s = to_string(x);
	auto n = s.size();
	sort(s.begin(), s.end());

	uvlong a = 0;
	uvlong b = 0;
	for (size_t i = 0; i < n; i++)
	{
		a = (a * 10) + (s[i] - '0');
		b = (b * 10) + (s[n - i - 1] - '0');
	}
	return (b - a) * (b - a);
}

int main()
{
	assert(solve(30605) == 4217723136);

	return 0;
}
