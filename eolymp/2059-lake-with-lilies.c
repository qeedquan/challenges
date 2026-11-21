/*

In the forest lake, lilies have started to bloom. On the first day, a single lily bloomed, and every subsequent day the number of blooming lilies doubled.
On the n-th day, the entire lake surface was covered with blooming lilies. On which day was half of the lake's surface covered with blooming lilies?

Input
The number n (1<n≤200), the day on which the whole lake surface was covered with blooming lilies.

Output
Print the number of the day when half of the lake surface was covered with blooming lilies.

Examples
Input #1
3

Answer #1
2

*/

#include <assert.h>

int
solve(int n)
{
	if (n < 1)
		return 0;
	return n - 1;
}

int
main()
{
	assert(solve(3) == 2);

	return 0;
}
