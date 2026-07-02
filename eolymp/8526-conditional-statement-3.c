/*

Find the value of y according to the following condition:

y = x + 5     x < -4
    x^2 - 3x  -4 <= x <= 7
    x^3 + 2x  x > 7

Input
One integer x (−100≤x≤100).

Output
Print the value of y according to the conditional statement above.

Examples

Input #1
3

Answer #1
0

Input #2
-8

Answer #2
-3

*/

#include <assert.h>

int
solve(int x)
{
	if (x < -4)
		return x + 5;
	if (-4 <= x && x <= 7)
		return (x * x) - (3 * x);
	return (x * x * x) + (2 * x);
}

int
main()
{
	assert(solve(3) == 0);
	assert(solve(-8) == -3);

	return 0;
}
