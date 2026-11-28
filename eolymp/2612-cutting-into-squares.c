/*

A piece of paper has dimensions A×B. Each time, cut out the largest possible square from the strip until only squares remain.
How many squares will be obtained in total?

Input
The program receives two integers, A and B (1≤A,B≤10^9).

Output
Output the total number of squares obtained.

Examples

Input #1
15 3

Answer #1
5

*/

#include <assert.h>

int
solve(int a, int b)
{
	int r;

	r = 0;
	while (a > 0 && b > 0) {
		if (a >= b) {
			r += a / b;
			a %= b;
		} else {
			r += b / a;
			b %= a;
		}
	}
	return r;
}

int
main()
{
	assert(solve(15, 3) == 5);

	return 0;
}
