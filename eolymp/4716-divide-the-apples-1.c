/*

n students divide k apples equally. The remainder, if any, stays in the basket. Determine how many apples each student will receive.

Input
Two positive integers n and k, each not exceeding 1500. It's rare to have more students in a school, and eating too many apples isn't healthy either.

Output
Print the number of apples each student will receive.

Examples

Input #1
3
14

Answer #1
4

Input #2
10
100

Answer #2
10

*/

#include <assert.h>

int
solve(int n, int k)
{
	if (n == 0)
		return 0;
	return k / n;
}

int
main()
{
	assert(solve(3, 14) == 4);
	assert(solve(10, 100) == 10);

	return 0;
}
