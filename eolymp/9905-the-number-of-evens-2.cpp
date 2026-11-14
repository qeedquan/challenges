/*

Your program is given a natural number n. It must print the number of even natural numbers smaller than n.

Input
A natural number n, does not exceed 10^18.

Output
The answer to the problem.

Examples

Input #1
7

Answer #1
3

Input #2
6

Answer #2
2

*/

#include <cassert>

int solve(int n)
{
	if (n < 0)
		return 0;
	return (n - !(n & 1)) >> 1;
}

int main()
{
	assert(solve(7) == 3);
	assert(solve(6) == 2);

	return 0;
}
