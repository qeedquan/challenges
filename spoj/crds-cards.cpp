/*

Maricruz have a lot of cards, she always uses her cards to build pyramids as shown in the following image:

A pyramid card of 3 levels. She always wonder how many cards does she need to make a pyramid card of N levels. Your task is to answer that question.

Input
The first line of the input contains an integer 1 ≤ T ≤ 1,000. Each of the following T lines will have an integer 1 ≤ N ≤ 1,000,000.

Output
For each case, output a single line consisting of the number of cards needed to build a pyramid card of level N modulo 1,000,007.

Example
Input Example
2
3
7

Output Example
15
77

*/

#include <cassert>

typedef long long vlong;

// https://oeis.org/A005449
vlong solve(vlong n)
{
	static const vlong mod = 1000007;

	vlong r;

	if (n < 1)
		return 0;

	r = ((3 * n * n) + n) / 2;
	return r % mod;
}

int main()
{
	assert(solve(3) == 15);
	assert(solve(7) == 77);

	return 0;
}
