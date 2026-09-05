/*

Find the value of y according to the following condition:

y = x^3 + 5x     x >= 10
    x^2 -2x + 4  x < 10

Input
One integer x (−10^4≤x≤10^4).

Output
Print the value of y according to the given condition.

Examples

Input #1
2
Answer #1
4

Input #2
20
Answer #2
8100

*/

#include <assert.h>

int
solve(int x)
{
	if (x >= 10)
		return (x * x * x) + (5 * x);
	return (x * x) - (2 * x) + 4;
}

int
main()
{
	assert(solve(2) == 4);
	assert(solve(20) == 8100);

	return 0;
}
