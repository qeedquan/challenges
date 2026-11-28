/*

Determine and output the number of integers within the interval [a,b].

Input
Two integers, a and b, separated by a space, each not exceeding 10^18.

Output
The solution to the problem.

Examples

Input #1
-7 9

Answer #1
17

*/

#include <cassert>

int solve(int a, int b)
{
	return b - a + 1;
}

int main()
{
	assert(solve(-7, 9) == 17);

	return 0;
}
