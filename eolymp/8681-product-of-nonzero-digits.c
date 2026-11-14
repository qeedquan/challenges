/*

Find the product of nonzero digits of the given integer.

Input
One positive integer n (n≤10^9).

Output
Print the product of nonzero digits of number n.

Examples

Input #1
1203405

Answer #1
120

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong n)
{
	uvlong d, r;
	int f;

	f = 0;
	for (r = 1; n > 0; n /= 10) {
		d = n % 10;
		if (d) {
			r *= d;
			f = 1;
		}
	}
	return (f) ? r : 0;
}

int
main()
{
	assert(solve(1203405) == 120);

	return 0;
}
