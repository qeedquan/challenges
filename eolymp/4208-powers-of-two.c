/*

It is well known that for any non-negative integer n, the number 2^n has a very simple representation in binary:
a single one in the highest bit followed by n zeros.
In the decimal system, these numbers are not so uniform; however, among them, there are some that begin with the digit one.

Print the number of such numbers in the given range.

Input
Two integers n1 and n2 (0≤n1<n2≤10^9), separated by a space.

Output
Print the number of powers of two in the interval [2n^1;2^n2] whose decimal representation begins with the digit 1.

Examples
Input #1
0 10

Answer #1
4

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
solve(int a, int b)
{
	a = ((a - 1) * log10(2)) + 1;
	b = (b * log10(2)) + 1;
	return b - a;
}

int
main()
{
	assert(solve(0, 10) == 4);

	return 0;
}
