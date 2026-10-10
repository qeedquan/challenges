/*

Let an,bn,cn be arithmetic progressions.

It is known that

a1 + b1 + c1 = p,
a2 + b2 + c2 = q

For the given positive integer k find the value of ak + bk + ck.

Input
Three integers p,q (∣p∣,∣q∣≤10^18), k (k>0).

Output
Print the value of ak + bk + ck. It is known that output is no more than 10^18 by absolute value.

Examples

Input #1
2 5 10

Answer #1
29

*/

#include <assert.h>

typedef long long vlong;

vlong
solve(vlong a, vlong b, vlong k)
{
	return a + (k - 1) * (b - a);
}

int
main()
{
	assert(solve(2, 5, 10) == 29);

	return 0;
}
