/*

In an arithmetic expression, you may use the number 1, the operations addition, multiplication, and parentheses.
What is the minimal number of ones required to obtain a given positive integer n?

Input
The input contains one integer n (1≤n≤5000).

Output
Output the minimal number of ones required.

Examples

Input #1
7

Answer #1
6

Input #17
119

Answer #17
15

*/

#include <cassert>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

// https://oeis.org/A005245
int solve(int n)
{
	if (n < 0)
		return 0;

	vector<int> lut(n + 3);
	lut[0] = 0;
	lut[1] = 1;
	lut[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		int cur = INT_MAX;
		for (int j = 1; j <= (i / 2) + 1; j++)
			cur = min(cur, lut[j] + lut[i - j]);

		int lim = sqrt(i) + 1;
		for (int j = 2; j <= lim; j++)
		{
			if (!(i % j))
				cur = min(cur, lut[j] + lut[i / j]);
		}

		lut[i] = cur;
	}
	return lut[n];
}

int main()
{
	static const int terms[] = {
		1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8, 7, 8, 8, 8, 8, 9, 8, 9, 9, 9, 10, 11,
		9, 10, 10, 9, 10, 11, 10, 11, 10, 11, 11, 11, 10, 11, 11, 11, 11, 12,
		11, 12, 12, 11, 12, 13, 11, 12, 12, 12, 12, 13, 11, 12, 12, 12, 13, 14,
		12, 13, 13, 12, 12, 13, 13, 14, 13, 14, 13, 14, 12, 13, 13, 13, 13, 14,
		13, 14
	};

	for (size_t i = 0; i < size(terms); i++)
		assert(solve(i + 1) == terms[i]);

	return 0;
}
