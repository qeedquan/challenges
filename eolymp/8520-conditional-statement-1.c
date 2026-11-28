/*

Find the value of y according to the following condition:

y = x^2 - 3x + 4  x < 5
    x + 7         x >= 5

Input
One integer x (−1000≤x≤1000).

Output
Print the value of y according to the given condition.

Examples

Input #1
2
Answer #1
2

Input #2
10
Answer #2
17

*/

#include <assert.h>

int
solve(int x)
{
	if (x < 5)
		return (x * x) - (3 * x) + 4;
	return x + 7;
}

int
main()
{
	assert(solve(2) == 2);
	assert(solve(10) == 17);

	return 0;
}
