/*

Description

Given positive integers B and N, find an integer A such that AN is as close as possible to B. (The result A is an approximation to the Nth root of B.) Note that AN may be less than, equal to, or greater than B.

Input

The input consists of one or more pairs of values for B and N. Each pair appears on a single line, delimited by a single space. A line specifying the value zero for both B and N marks the end of the input. The value of B will be in the range 1 to 1,000,000 (inclusive), and the value of N will be in the range 1 to 9 (inclusive).

Output

For each pair B and N in the input, output A as defined above on a line by itself.

Sample Input

4 3
5 3
27 3
750 5
1000 5
2000 5
3000 5
1000000 5
0 0

Sample Output

1
2
3
4
4
4
5
16

Source

Mid-Central USA 2006

*/

#include <assert.h>
#include <math.h>

long
closest(long b, long n)
{
	long a, d1, d2;

	a = floor(pow(b, 1.0 / n));
	d1 = b - pow(a, n);
	d2 = pow(a + 1, n) - b;
	if (d1 >= d2)
		a += 1;
	return a;
}

int
main(void)
{
	assert(closest(4, 3) == 1);
	assert(closest(5, 3) == 2);
	assert(closest(27, 3) == 3);
	assert(closest(750, 5) == 4);
	assert(closest(1000, 5) == 4);
	assert(closest(2000, 5) == 4);
	assert(closest(3000, 5) == 5);
	assert(closest(1000000L, 5) == 16);

	return 0;
}
