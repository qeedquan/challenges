/*

We have N integers. What is the maximum product that can be achieved by using exactly three of these numbers?

Input
The first line contains a non-negative integer N (3≤N≤10^6). The second line lists N integers, each with an absolute value no greater than 10^5.

Output
Output the maximum product obtainable from any three of these integers.

Examples

Input #1
9
3 5 -9 7 4 0 9 -3 5

Answer #1
315

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> &&x)
{
	auto n = x.size();
	if (n < 3)
		return 0;

	sort(x.begin(), x.end());

	auto r = x[n - 1] * x[n - 2] * x[n - 3];
	r = max(r, x[0] * x[1] * x[n - 1]);
	return r;
}

int main()
{
	assert(solve({ 3, 5, -9, 7, 4, 0, 9, -3, 5 }) == 315);
	assert(solve({ -10, -11, 1, 2, 12 }) == 1320);

	return 0;
}
