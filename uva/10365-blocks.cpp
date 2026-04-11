/*

Donald wishes to send a gift to his new
nephew, Fooey. Donald is a bit of a traditionalist, so he has chosen to send a set
of N classic baby blocks. Each block is a
cube, 1 inch by 1 inch by 1 inch. Donald
wants to stack the blocks together into a
rectangular solid and wrap them all up
in brown paper for shipping. How much
brown paper does Donald need?

Input
The first line of input contains C, the number of test cases. For each case there is an additional line
containing N, the number of blocks to be shipped. N does not exceed 1000.

Output
Your program should produce one line of output per case, giving the minimal area of paper (in square
inches) needed to wrap the blocks when they are stacked together.

Sample Input
5
9
10
26
27
100

Sample Output
30
34
82
54
130

*/

#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

// https://oeis.org/A075777
int solve(int n)
{
	if (n < 1)
		return 0;

	auto r = INT_MAX;
	auto m = sqrt(n);
	for (auto l = 1; l <= m; l++)
	{
		for (auto h = l; h <= m; h++)
		{
			if (!(n % h) && !((n / h) % l))
			{
				auto w = (n / h) / l;
				r = min(r, (2 * l * w) + (2 * h * w) + (2 * l * h));
			}
		}
	}
	return r;
}

int main()
{
	static const int tab[] = {
		6, 10, 14, 16, 22, 22, 30, 24, 30, 34, 46, 32, 54, 46, 46, 40, 70, 42,
		78, 48, 62, 70, 94, 52, 70, 82, 54, 64, 118, 62, 126, 64, 94, 106, 94,
		66, 150, 118, 110, 76, 166, 82, 174, 96, 78, 142, 190, 80, 126, 90, 142,
		112, 214, 90, 142, 100, 158, 178, 238, 94, 246, 190
	};

	assert(solve(9) == 30);
	assert(solve(10) == 34);
	assert(solve(26) == 82);
	assert(solve(27) == 54);
	assert(solve(100) == 130);

	for (size_t i = 0; i < size(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
