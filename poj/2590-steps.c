/*

Description

One steps through integer points of the straight line. The length of a step must be nonnegative and can be by one bigger than, equal to, or by one smaller than the length of the previous step.
What is the minimum number of steps in order to get from x to y? The length of the first and the last step must be 1.

Input

Input consists of a line containing n, the number of test cases.

Output

For each test case, a line follows with two integers: 0 <= x <= y < 2^31. For each test case, print a line giving the minimum number of steps to get from x to y.
Sample Input

3
45 48
45 49
45 50
Sample Output

3
3
4
Source

Waterloo local 2000.01.29

*/

#include <assert.h>
#include <math.h>

int
steps(int x, int y)
{
	int d, k;

	d = y - x;
	if (d <= 0)
		return 0;

	k = sqrt(d);
	if (k * k >= d)
		return (2 * k) - 1;
	if (k * (k + 1) >= d)
		return 2 * k;
	return (2 * k) + 1;
}

int
main(void)
{
	assert(steps(45, 48) == 3);
	assert(steps(45, 49) == 3);
	assert(steps(45, 50) == 4);

	return 0;
}
